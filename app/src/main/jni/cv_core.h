#ifndef __H_AAC_MODULE_H__
#define __H_AAC_MODULE_H__
#include <jni.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<android/log.h>
#include "cv_native.h"

#ifdef __cplusplus
extern "C"
{
#endif

int register_android_jni_core_module(JNIEnv* env, jclass clazz);

/*
 * Class:     com_panda_org_angrypandacv_core_OpenCVHelper
 * Method:    gray
 * Signature: ([III)[I
 */
JNIEXPORT jintArray JNICALL Java_cn_edu_zafu_opencv_OpenCVHelper_gray
        (JNIEnv *, jobject, jintArray, jint, jint);

#ifdef __cplusplus
}
#endif
#endif //__H_AAC_MODULE_H__