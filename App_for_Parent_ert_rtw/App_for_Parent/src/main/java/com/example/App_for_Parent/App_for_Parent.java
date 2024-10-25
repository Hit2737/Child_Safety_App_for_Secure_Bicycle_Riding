package com.example.App_for_Parent;

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.widget.Toast;
import android.util.Log;
import java.util.ArrayList;
import android.content.res.Configuration;
import androidx.core.app.ActivityCompat;
import androidx.fragment.app.Fragment;
import androidx.core.content.ContextCompat;
import android.view.LayoutInflater;
import androidx.annotation.NonNull;
import androidx.annotation.RequiresApi;
import com.example.App_for_Parent.databinding.ActivityMainBinding;
import com.google.android.material.tabs.TabLayoutMediator;
import androidx.fragment.app.FragmentManager;
import androidx.navigation.NavController;
import androidx.navigation.Navigation;
import android.view.MenuItem;
import androidx.navigation.fragment.NavHostFragment;
import androidx.navigation.ui.NavigationUI;
import android.widget.LinearLayout;
import com.google.android.material.bottomnavigation.BottomNavigationView;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.view.View;
import android.view.MotionEvent;
import android.widget.Button;
import android.widget.ToggleButton;
import android.widget.TextView;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.Set;
import java.util.HashMap;
import android.annotation.TargetApi;
import android.os.Build;
import android.content.Context;
import android.media.AudioManager;

public class App_for_Parent extends AppCompatActivity implements OnFragmentInteractionListener , SensorEventListener {
    private InfoFragment infoFragment;
    private AppFragment appFragment;
     FragmentManager fm;
     Fragment current;
    private LogFragment logFragment;
     private static ArrayList<AudioFileRead> AudioFileReader = new  ArrayList<AudioFileRead>();
     private Hashtable<Integer,Float> buttonStates = new Hashtable<Integer,Float>();
     private Hashtable<Integer,TextView> textViews = new Hashtable<Integer,TextView>();
     private SensorManager mSensorManager;
     private GPSHandler mGPSHandler;
     private Hashtable<Integer, ThingSpeakRead> thingSpeakReadBlocks = new Hashtable<>();
    private static final int MY_PERMISSIONS_REQUEST_FINE_LOCATION = 300;
    private boolean isFineLocationPermissionGranted = false;
    private boolean isFineLocationPermissionRequested = false;
    String nativeSampleRate;
    String nativeSampleBufSize;
     private String mErrorInfo[];
     private String mReceiveBlockNames[];

     private void registerSensorManager() {
     }

    private boolean checkIfAllPermissionsGranted()
    {
        return true && isFineLocationPermissionGranted;
    }
    private void requestPermission() {
        String permissionRationale = "";
        // Here, thisClass is the current activity
        //request for fine location
        if (ContextCompat.checkSelfPermission(thisClass,
                Manifest.permission.ACCESS_FINE_LOCATION)
                != PackageManager.PERMISSION_GRANTED) {

            // Permission is not granted. Should we show an explanation?
            if (ActivityCompat.shouldShowRequestPermissionRationale(thisClass,
                    Manifest.permission.ACCESS_FINE_LOCATION)) {
                permissionRationale += "Access fine location, ";
            } else {
                // No explanation needed; request the permission
                if (!isFineLocationPermissionRequested) {
                    isFineLocationPermissionRequested = true;
                    ActivityCompat.requestPermissions(thisClass,
                            new String[]{Manifest.permission.ACCESS_FINE_LOCATION},
                            MY_PERMISSIONS_REQUEST_FINE_LOCATION);
                    return;
                }
            }
        } else {
            // Permission has already been granted
            isFineLocationPermissionGranted = true;
        }
        if (!permissionRationale.isEmpty())
            if (infoFragment != null) {
                infoFragment.updateModelInfo(permissionRationale + "permission not granted. Model cannot start.");
            }
    }
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        com.example.App_for_Parent.databinding.ActivityMainBinding activityMainBinding = ActivityMainBinding.inflate(LayoutInflater.from(this));
        setContentView(activityMainBinding.getRoot());
        fm = getSupportFragmentManager();
        Fragment navHostFragment = fm.findFragmentById(R.id.nav_host_fragment);
        navHostFragment = navHostFragment.getChildFragmentManager().getFragments().get(0);
        current =  navHostFragment;
        appFragment  = (AppFragment) navHostFragment;
        infoFragment  = new InfoFragment();
        logFragment  = new LogFragment();
        fm.beginTransaction().add(R.id.nav_host_fragment, logFragment, "3").hide(logFragment).commit();
        fm.beginTransaction().add(R.id.nav_host_fragment, infoFragment, "2").hide(infoFragment).commit();
        fm.beginTransaction().add(R.id.nav_host_fragment, appFragment, "1").commit();
        BottomNavigationView navView = findViewById(R.id.nav_view);
        NavController navController = Navigation.findNavController(this, R.id.nav_host_fragment);
        NavigationUI.setupWithNavController(navView, navController);
        navView.setOnNavigationItemSelectedListener(new BottomNavigationView.OnNavigationItemSelectedListener() {
        @Override
                public boolean onNavigationItemSelected(@NonNull MenuItem menuItem) {
                        switch (menuItem.getItemId()) {                case R.id.navigation_app:
                fm.beginTransaction().hide(current).show(appFragment).commit();
                current = appFragment;
        return true;                case R.id.navigation_info:
                fm.beginTransaction().hide(current).show(infoFragment).commit();
                current = infoFragment;
        return true;                case R.id.navigation_log:
                fm.beginTransaction().hide(current).show(logFragment).commit();
                current = logFragment;
        return true;                }
                return false;
                }
        });
        // Initiate the SensorManager
        mSensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
         mGPSHandler = new GPSHandler(this);
        queryNativeAudioParameters();
        thisClass = this;
mErrorInfo = getResources().getStringArray(R.array.error_information);
mReceiveBlockNames = getResources().getStringArray(R.array.tcpReceiveBlockNames);
     }

    private App_for_Parent thisClass;
    private final Thread BgThread = new Thread() {
    @Override
    public void run() {
            String argv[] = new String[] {"MainActivity","App_for_Parent"};
            naMain(argv, thisClass);
        }
    };

    public void flashMessage(final String inMessage) {
        runOnUiThread(new Runnable() {
              public void run() {
                    Toast.makeText(getBaseContext(), inMessage, Toast.LENGTH_SHORT).show();
              }
        });
    }

    public void terminateApp() {
        finish();
    }

    protected void onDestroy() {
         if (BgThread.isAlive())
             naOnAppStateChange(6);
        Iterator it = thingSpeakReadBlocks.entrySet().iterator();
        while (it.hasNext()) {
            HashMap.Entry pair = (HashMap.Entry)it.next();
            ThingSpeakRead tsR  = (ThingSpeakRead) pair.getValue();
            tsR.cancelTimer();
        }
         super.onDestroy();
         System.exit(0); //to kill all our threads.
    }

   //Methods for ThingSpeak Write block
   public void initThingSpeakReadConnection(int channelID, String readAPIKey, int field, double sampleTime) {
       if (!thingSpeakReadBlocks.containsKey(channelID)) {
            ThingSpeakRead thingSpeakWrite = new ThingSpeakRead(channelID,readAPIKey, field, this, sampleTime);
            thingSpeakWrite.setChannelID(channelID);
            thingSpeakWrite.setReadAPIKey(readAPIKey);
            thingSpeakWrite.setLogFragment(logFragment);
            thingSpeakReadBlocks.put(channelID, thingSpeakWrite);
       } else{
             ThingSpeakRead tsR = thingSpeakReadBlocks.get(channelID);
             if (tsR != null) {
                  tsR.addSampleTime(field, sampleTime);
             }
       }
   }
   public float[] readThingSpeakData(int channelid, int field) {
       ThingSpeakRead thingSpeakRead = thingSpeakReadBlocks.get(channelid);
       if( thingSpeakRead != null){
           float[] f =  thingSpeakRead.readData(channelid, field);
           return f;
       }else
           return new float[]{0,0};   }

	@Override
    public void onAttachFragment(Fragment fragment) {
        super.onAttachFragment(fragment);
        if (fragment instanceof InfoFragment) {
            this.infoFragment = (InfoFragment) fragment;
            infoFragment.setFragmentInteractionListener(this);
        }
        if (fragment instanceof AppFragment) {
            ((AppFragment)fragment).setFragmentInteractionListener(this);
        }
        if (fragment instanceof LogFragment) {
            this.logFragment = (LogFragment) fragment;
            Set<Integer> keySet = thingSpeakReadBlocks.keySet();
            Iterator<Integer> itr = keySet.iterator();
            while (itr.hasNext()) {
                Integer v = itr.next();
                thingSpeakReadBlocks.get(v).setLogFragment((LogFragment) fragment);
            }
        }
    }

	@Override
    public void onFragmentCreate(String name) {

    }

    @Override
    public void onFragmentStart(String name) {
        switch (name) {
            case "Info":
               break;
            case "App":
                break;
            default:
                break;
    }
    }

    @Override
    public void onFragmentResume(String name) {
        switch (name) {
            case "App":
                registerDataDisplays();
                for (int i=1;i<=1;i++) {
                    registerButtonFcn(i);
                }
                if (checkIfAllPermissionsGranted()){
                    if (!BgThread.isAlive()) {
                        BgThread.start();
                    }
                }
                break;
            default:
                break;
        }
    }

    @Override
    public void onFragmentPause(String name) {
    }
    @Override
    protected void onResume() {
            requestPermission();
         super.onResume();
         if (BgThread.isAlive())
             naOnAppStateChange(3);
         registerSensorManager();
    }

    @Override
    protected void onPause() {
        if (BgThread.isAlive())
            naOnAppStateChange(4);
         mSensorManager.unregisterListener(this);
        super.onPause();
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
    }

    @Override
    public void onRequestPermissionsResult(int requestCode,
                                           String permissions[], int[] grantResults) {
        switch (requestCode) {
            case MY_PERMISSIONS_REQUEST_FINE_LOCATION:
                // If request is cancelled, the result arrays are empty.
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    // permission was granted, yay! Do related task you need to do.
                    isFineLocationPermissionGranted = true;
                    mGPSHandler = new GPSHandler(thisClass);
                } else {
                    // permission denied, boo!
                    flashMessage("Access location Permission not granted");
                }
                isFineLocationPermissionRequested = false;
                break;

            // other case lines to check for other
            // permissions this app might request.
        }
        if (!checkIfAllPermissionsGranted() && !isFineLocationPermissionRequested) {
            requestPermission();
        }
    }

    public void registerDataDisplays() {
    // bind text views for data display block;
    for (int i = 1; i <= 2; i++) {
            TextView textView = (TextView) findViewById(
            getResources().getIdentifier("DataDisplay" + i, "id", getPackageName()));
            textViews.put(i, textView);
        }
    }
    public void registerButtonFcn(int id) {
        String buttonid     = "button"+id;
        final ToggleButton button = (ToggleButton)findViewById(getResources().getIdentifier(buttonid, "id", getPackageName()));
        if (null == button)
            return;
        setButtonState(button);
        button.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
                setButtonState(button);
			}
		});
    }

    // update the hash table with button id and state
    public void setButtonState(ToggleButton button) {
    	if(button.isChecked()) {
            buttonStates.put(button.getId(),1.0f);
		} else {
            buttonStates.put(button.getId(),0.0f);
		}
    }

    public float getButtonState(int id) {
        String buttonid = "button"+id;
        Float buttonState = buttonStates.get(getResources().getIdentifier(buttonid, "id", getPackageName()));
        return buttonState == null?-1:buttonState.floatValue();
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        float [] values = event.values;
        //Comment out if you want to log the data in logcat
        //String logMessage = String.format("%d: 0'%g'", event.sensor.getType(), values[0]);
        //Log.d("Sensor Data IN:", logMessage);
        switch(event.sensor.getType()) {
        }
    }

    // Get SensorEvent Data throws exception if the data is null
    // Get GPS Data if GPS is enabled. Otherwise return 0,0
    public double[] getGPSData() {
        return mGPSHandler.getLocationData();
    }

    public void displayText(int id, byte[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    public void displayText(int id, short[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    public void displayText(int id, int[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    public void displayText(int id, long[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    public void displayText(int id, float[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    public void displayText(int id, double[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    private void updateTextViewById(final int id, final String finalStringToDisplay) {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                try {
                    TextView tv = textViews.get(id);
                    if(tv != null) {
                        tv.setText(finalStringToDisplay);
                    }
					
                } catch (Exception ex) {
                    Log.e("App_for_Parent.updateTextViewById", ex.getLocalizedMessage());
                }
            }
        });
    }
    @TargetApi(Build.VERSION_CODES.JELLY_BEAN_MR1)
    private void queryNativeAudioParameters() {
        Log.d("audioEQ", "queryNativeAudioParameters called");
        AudioManager myAudioMgr = (AudioManager) getSystemService(Context.AUDIO_SERVICE);
        nativeSampleRate = myAudioMgr.getProperty(AudioManager.PROPERTY_OUTPUT_SAMPLE_RATE);
        nativeSampleBufSize = myAudioMgr.getProperty(AudioManager.PROPERTY_OUTPUT_FRAMES_PER_BUFFER);
    }

    public int getNativeSampleRate() {
        Log.d("audioEQ", "JNI getNativeSampleRate called");
        return Integer.parseInt(nativeSampleRate);
    }
    public int getNativeSampleBufSize() {
        Log.d("audioEQ", "JNI getNativeSampleBufSize called");
        return Integer.parseInt(nativeSampleBufSize);
    }
    // Log TCP info
     public void displayTCPLogs(short errorNo, int blockId, short isReceive, String argument) {
       if (mErrorInfo != null && mErrorInfo.length >= errorNo) {
          String errorInfo = mErrorInfo[errorNo];
          if (isReceive == 1 && blockId >0 && mReceiveBlockNames.length >= blockId)
              errorInfo = mReceiveBlockNames[blockId-1] + errorInfo;
            if (!argument.equals(""))
                errorInfo = errorInfo.replace("#argument#",argument);
            logFragment.updateTCPLog(errorInfo);
       }
}

public int audioFileReadInit(String fileName, int frameSize) {
    AudioFileReader.add(new AudioFileRead(this, fileName, frameSize));
    return AudioFileReader.size() - 1;
}
public short[] audioFileReadStep(int idx) {
    return AudioFileReader.get(idx).AudioFileReadStep();
}
public void audioFileReadTerminate(int idx) {
    AudioFileReader.get(idx).AudioFileReadTerminate();
}
    private native int naMain(String[] argv, App_for_Parent pThis);
    private native void naOnAppStateChange(int state);
    static {
        System.loadLibrary("App_for_Parent");
    }

}
