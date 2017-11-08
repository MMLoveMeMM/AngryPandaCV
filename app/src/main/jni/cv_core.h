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
 * Method:    Gray
 * Signature: ([III)[I
 */
JNIEXPORT jintArray JNICALL Java_com_panda_org_angrypandacv_core_OpenCVHelper_Gray
        (JNIEnv *, jobject, jintArray, jint, jint);

/*
 * Class:     com_panda_org_angrypandacv_core_OpenCVHelper
 * Method:    SobelImage
 * Signature: (Landroid/graphics/Bitmap;)I
 */
JNIEXPORT jint JNICALL Java_com_panda_org_angrypandacv_core_OpenCVHelper_SobelImage
        (JNIEnv *, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif //__H_AAC_MODULE_H__