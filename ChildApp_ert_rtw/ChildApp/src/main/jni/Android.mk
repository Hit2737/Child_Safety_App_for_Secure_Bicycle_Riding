LOCAL_PATH := ..
include $(CLEAR_VARS)
LOCAL_MODULE := ChildApp
LOCAL_CFLAGS += -DDEBUG_ANDROID -DMODEL=ChildApp -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT -DPORTABLE_WORDSIZES -DDRIVER_ANDROID_AUDIOCAPTURE -DDRIVER_ANDROID_AUDIOPLAYBACK 
LOCAL_CPPFLAGS := -std=c++11
LOCAL_SRC_FILES := MW_TCPSendReceive.c ert_main.c ChildApp.c ChildApp_data.c rtGetInf.c rtGetNaN.c rt_nonfinite.c androidinitialize.c driver_android_accelerometer.c driver_android_audiofileread.c driver_android_audiocapture.c driver_android_audioplayback.c audio_engine.cpp audio_player.cpp audio_recorder.cpp driver_android_button.c driver_android_gyroscope.c driver_android_location.c driver_android_datadisplay.c driver_android_tcp_log.c 
LOCAL_C_INCLUDES += C:/Simulink C:/PROGRA~3/MATLAB/SUPPOR~1/R2023a/toolbox/target/SUPPOR~1/android/include C:/PROGRA~3/MATLAB/SUPPOR~1/R2023a/toolbox/target/SUPPOR~1/SHARED~1/include C:/Simulink/CHILDA~1 C:/PROGRA~1/MATLAB/R2023a/extern/include C:/PROGRA~1/MATLAB/R2023a/simulink/include C:/PROGRA~1/MATLAB/R2023a/rtw/c/src C:/PROGRA~1/MATLAB/R2023a/rtw/c/src/ext_mode/common C:/PROGRA~1/MATLAB/R2023a/rtw/c/ert 
LOCAL_LDLIBS  +=  -llog -ldl -lOpenSLES -latomic
include $(BUILD_SHARED_LIBRARY)
