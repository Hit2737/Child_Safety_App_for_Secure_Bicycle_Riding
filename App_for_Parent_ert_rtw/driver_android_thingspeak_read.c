/*
 * driver_android_thingspeak_read.c
 *
 * Driver code
 *
 * Copyright 2016-2021 The MathWorks, Inc.
 */
#include <jni.h>
#include <stdlib.h>
#include <android/log.h>

extern JavaVM *cachedJvm;
extern jobject cachedActivityObj;
extern jclass cachedMainActivityCls;
static jmethodID methodId;

void initThingSpeakread(const int channelID, const char* readAPIKey,int field, double sampleTime){
    
    JNIEnv *pEnv;
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    
    methodId = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "initThingSpeakReadConnection","(ILjava/lang/String;ID)V");
    if (methodId == NULL)
        return; /* initThingSpeakConnection method not found */
    
    jstring jstrKey = (*pEnv)->NewStringUTF(pEnv, readAPIKey);
    (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, methodId, channelID, jstrKey, field, sampleTime);
    // Clear exception if any, so user can proceed
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        __android_log_write(ANDROID_LOG_ERROR, "driver_android_thingspeak_read",
                "Exception: on calling void method initThingSpeakConnection.");
        
        (*pEnv)->ExceptionDescribe(pEnv);
        (*pEnv)->ExceptionClear(pEnv);
    }
    (*pEnv)->DeleteLocalRef(pEnv,jstrKey);
    
}
void readThingspeakData(const int channelID, float* data, int16_t* status, int fieldID){
    JNIEnv *pEnv;
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    
    methodId = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "readThingSpeakData","(II)[F");
    if (methodId == NULL)
        return; /* initThingSpeakConnection method not found */
    jfloatArray ret;
    jfloat values[2];
    ret = (*pEnv)->CallObjectMethod(pEnv, cachedActivityObj, methodId,channelID, fieldID);
    (*pEnv)->GetFloatArrayRegion(pEnv, ret, 0, 2, values);
    // Clear exception if any, so user can proceed
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        __android_log_write(ANDROID_LOG_ERROR, "driver_android_thingspeak_read",
                "Exception: on calling void method initThingSpeakConnection.");
        (*pEnv)->ExceptionDescribe(pEnv);
        
        (*pEnv)->ExceptionClear(pEnv);
        
    }
    *data = values[0];
    *status=(int16_t)values[1];
    (*pEnv)->DeleteLocalRef(pEnv, ret);
    
}


