// Generated by view binder compiler. Do not edit!
package com.example.Test.databinding;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.viewbinding.ViewBinding;
import androidx.viewbinding.ViewBindings;
import com.example.Test.Camera2View;
import com.example.Test.CameraView;
import com.example.Test.R;
import java.lang.NullPointerException;
import java.lang.Override;
import java.lang.String;

public final class CameraViewBinding implements ViewBinding {
  @NonNull
  private final FrameLayout rootView;

  @NonNull
  public final Camera2View surface2View;

  @NonNull
  public final CameraView surfaceView;

  private CameraViewBinding(@NonNull FrameLayout rootView, @NonNull Camera2View surface2View,
      @NonNull CameraView surfaceView) {
    this.rootView = rootView;
    this.surface2View = surface2View;
    this.surfaceView = surfaceView;
  }

  @Override
  @NonNull
  public FrameLayout getRoot() {
    return rootView;
  }

  @NonNull
  public static CameraViewBinding inflate(@NonNull LayoutInflater inflater) {
    return inflate(inflater, null, false);
  }

  @NonNull
  public static CameraViewBinding inflate(@NonNull LayoutInflater inflater,
      @Nullable ViewGroup parent, boolean attachToParent) {
    View root = inflater.inflate(R.layout.camera_view, parent, false);
    if (attachToParent) {
      parent.addView(root);
    }
    return bind(root);
  }

  @NonNull
  public static CameraViewBinding bind(@NonNull View rootView) {
    // The body of this method is generated in a way you would not otherwise write.
    // This is done to optimize the compiled bytecode for size and performance.
    int id;
    missingId: {
      id = R.id.surface2_view;
      Camera2View surface2View = ViewBindings.findChildViewById(rootView, id);
      if (surface2View == null) {
        break missingId;
      }

      id = R.id.surface_view;
      CameraView surfaceView = ViewBindings.findChildViewById(rootView, id);
      if (surfaceView == null) {
        break missingId;
      }

      return new CameraViewBinding((FrameLayout) rootView, surface2View, surfaceView);
    }
    String missingId = rootView.getResources().getResourceName(id);
    throw new NullPointerException("Missing required view with ID: ".concat(missingId));
  }
}
