// Generated by view binder compiler. Do not edit!
package com.example.App_for_Parent.databinding;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.viewbinding.ViewBinding;
import androidx.viewbinding.ViewBindings;
import com.example.App_for_Parent.R;
import java.lang.NullPointerException;
import java.lang.Override;
import java.lang.String;

public final class FragmentLogBinding implements ViewBinding {
  @NonNull
  private final LinearLayout rootView;

  @NonNull
  public final TextView httplog;

  @NonNull
  public final TextView httplogtitle;

  @NonNull
  public final TextView mqttlog;

  @NonNull
  public final TextView mqttlogtitle;

  @NonNull
  public final TextView tcplog;

  @NonNull
  public final TextView tcplogtitle;

  @NonNull
  public final TextView thingspeaklog;

  @NonNull
  public final TextView thingspeaklogtitle;

  private FragmentLogBinding(@NonNull LinearLayout rootView, @NonNull TextView httplog,
      @NonNull TextView httplogtitle, @NonNull TextView mqttlog, @NonNull TextView mqttlogtitle,
      @NonNull TextView tcplog, @NonNull TextView tcplogtitle, @NonNull TextView thingspeaklog,
      @NonNull TextView thingspeaklogtitle) {
    this.rootView = rootView;
    this.httplog = httplog;
    this.httplogtitle = httplogtitle;
    this.mqttlog = mqttlog;
    this.mqttlogtitle = mqttlogtitle;
    this.tcplog = tcplog;
    this.tcplogtitle = tcplogtitle;
    this.thingspeaklog = thingspeaklog;
    this.thingspeaklogtitle = thingspeaklogtitle;
  }

  @Override
  @NonNull
  public LinearLayout getRoot() {
    return rootView;
  }

  @NonNull
  public static FragmentLogBinding inflate(@NonNull LayoutInflater inflater) {
    return inflate(inflater, null, false);
  }

  @NonNull
  public static FragmentLogBinding inflate(@NonNull LayoutInflater inflater,
      @Nullable ViewGroup parent, boolean attachToParent) {
    View root = inflater.inflate(R.layout.fragment_log, parent, false);
    if (attachToParent) {
      parent.addView(root);
    }
    return bind(root);
  }

  @NonNull
  public static FragmentLogBinding bind(@NonNull View rootView) {
    // The body of this method is generated in a way you would not otherwise write.
    // This is done to optimize the compiled bytecode for size and performance.
    int id;
    missingId: {
      id = R.id.httplog;
      TextView httplog = ViewBindings.findChildViewById(rootView, id);
      if (httplog == null) {
        break missingId;
      }

      id = R.id.httplogtitle;
      TextView httplogtitle = ViewBindings.findChildViewById(rootView, id);
      if (httplogtitle == null) {
        break missingId;
      }

      id = R.id.mqttlog;
      TextView mqttlog = ViewBindings.findChildViewById(rootView, id);
      if (mqttlog == null) {
        break missingId;
      }

      id = R.id.mqttlogtitle;
      TextView mqttlogtitle = ViewBindings.findChildViewById(rootView, id);
      if (mqttlogtitle == null) {
        break missingId;
      }

      id = R.id.tcplog;
      TextView tcplog = ViewBindings.findChildViewById(rootView, id);
      if (tcplog == null) {
        break missingId;
      }

      id = R.id.tcplogtitle;
      TextView tcplogtitle = ViewBindings.findChildViewById(rootView, id);
      if (tcplogtitle == null) {
        break missingId;
      }

      id = R.id.thingspeaklog;
      TextView thingspeaklog = ViewBindings.findChildViewById(rootView, id);
      if (thingspeaklog == null) {
        break missingId;
      }

      id = R.id.thingspeaklogtitle;
      TextView thingspeaklogtitle = ViewBindings.findChildViewById(rootView, id);
      if (thingspeaklogtitle == null) {
        break missingId;
      }

      return new FragmentLogBinding((LinearLayout) rootView, httplog, httplogtitle, mqttlog,
          mqttlogtitle, tcplog, tcplogtitle, thingspeaklog, thingspeaklogtitle);
    }
    String missingId = rootView.getResources().getResourceName(id);
    throw new NullPointerException("Missing required view with ID: ".concat(missingId));
  }
}
