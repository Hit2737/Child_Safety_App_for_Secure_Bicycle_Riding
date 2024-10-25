// Generated by view binder compiler. Do not edit!
package com.example.App_for_Child.databinding;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.viewbinding.ViewBinding;
import androidx.viewbinding.ViewBindings;
import com.example.App_for_Child.R;
import java.lang.NullPointerException;
import java.lang.Override;
import java.lang.String;

public final class FragmentAppBinding implements ViewBinding {
  @NonNull
  private final LinearLayout rootView;

  @NonNull
  public final AutoGeneratedWidgetsBinding autoGeneratedWidgets;

  @NonNull
  public final LinearLayout layoutapp;

  private FragmentAppBinding(@NonNull LinearLayout rootView,
      @NonNull AutoGeneratedWidgetsBinding autoGeneratedWidgets, @NonNull LinearLayout layoutapp) {
    this.rootView = rootView;
    this.autoGeneratedWidgets = autoGeneratedWidgets;
    this.layoutapp = layoutapp;
  }

  @Override
  @NonNull
  public LinearLayout getRoot() {
    return rootView;
  }

  @NonNull
  public static FragmentAppBinding inflate(@NonNull LayoutInflater inflater) {
    return inflate(inflater, null, false);
  }

  @NonNull
  public static FragmentAppBinding inflate(@NonNull LayoutInflater inflater,
      @Nullable ViewGroup parent, boolean attachToParent) {
    View root = inflater.inflate(R.layout.fragment_app, parent, false);
    if (attachToParent) {
      parent.addView(root);
    }
    return bind(root);
  }

  @NonNull
  public static FragmentAppBinding bind(@NonNull View rootView) {
    // The body of this method is generated in a way you would not otherwise write.
    // This is done to optimize the compiled bytecode for size and performance.
    int id;
    missingId: {
      id = R.id.auto_generated_widgets;
      View autoGeneratedWidgets = ViewBindings.findChildViewById(rootView, id);
      if (autoGeneratedWidgets == null) {
        break missingId;
      }
      AutoGeneratedWidgetsBinding binding_autoGeneratedWidgets = AutoGeneratedWidgetsBinding.bind(autoGeneratedWidgets);

      LinearLayout layoutapp = (LinearLayout) rootView;

      return new FragmentAppBinding((LinearLayout) rootView, binding_autoGeneratedWidgets,
          layoutapp);
    }
    String missingId = rootView.getResources().getResourceName(id);
    throw new NullPointerException("Missing required view with ID: ".concat(missingId));
  }
}
