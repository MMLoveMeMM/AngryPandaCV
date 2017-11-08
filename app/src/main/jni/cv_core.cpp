#include "cv_core.h"
#include <stdio.h>
#include <stdlib.h>
#include <android/bitmap.h>
#include <opencv2/opencv.hpp>
using namespace cv;
/*
 * Class:     com_panda_org_angrypandacv_core_OpenCVHelper
 * Method:    Gray
 * Signature: ([III)[I
 */
JNIEXPORT jintArray JNICALL Java_com_panda_org_angrypandacv_core_OpenCVHelper_Gray
        (JNIEnv *env, jobject thiz, jintArray buf, jint w, jint h){

    jint *cbuf;
    cbuf = env->GetIntArrayElements(buf, JNI_FALSE );
    if (cbuf == NULL) {
        return 0;
    }

    Mat imgData(h, w, CV_8UC4, (unsigned char *) cbuf);

    uchar* ptr = imgData.ptr(0);
    for(int i = 0; i < w*h; i ++){
        //计算公式：Y(亮度) = 0.299*R + 0.587*G + 0.114*B
        //对于一个int四字节，其彩色值存储方式为：BGRA
        int grayScale = (int)(ptr[4*i+2]*0.299 + ptr[4*i+1]*0.587 + ptr[4*i+0]*0.114);
        ptr[4*i+1] = grayScale;
        ptr[4*i+2] = grayScale;
        ptr[4*i+0] = grayScale;
    }

    int size = w * h;
    jintArray result = env->NewIntArray(size);
    env->SetIntArrayRegion(result, 0, size, cbuf);
    env->ReleaseIntArrayElements(buf, cbuf, 0);
    return result;

}

/*
 * Class:     com_panda_org_angrypandacv_core_OpenCVHelper
 * Method:    SobelImage
 * Signature: (Landroid/graphics/Bitmap;)I
 */
JNIEXPORT jint JNICALL Java_com_panda_org_angrypandacv_core_OpenCVHelper_SobelImage
        (JNIEnv *env, jobject thiz, jobject bmpIn){
    AndroidBitmapInfo inBmpInfo;
    void* inPixelsAddress;
    int ret;
    if ((ret = AndroidBitmap_getInfo(env, bmpIn, &inBmpInfo)) < 0) {
        LOGI("AndroidBitmap_getInfo() failed ! error=%d", ret);
        return -1;
    }
    LOGI("original image :: width is %d; height is %d; stride is %d; format is %d;flags is   %d,stride is %u", inBmpInfo.width, inBmpInfo.height, inBmpInfo.stride, inBmpInfo.format, inBmpInfo.flags, inBmpInfo.stride);
    if ((ret = AndroidBitmap_lockPixels(env, bmpIn, &inPixelsAddress)) < 0) {
        LOGE("AndroidBitmap_lockPixels() failed ! error=%d", ret);
        return -1;
    }

    Mat inMat(inBmpInfo.height, inBmpInfo.width,
              CV_8UC4, inPixelsAddress);
    Sobel(inMat, inMat, inMat.depth(), 1, 1);
    AndroidBitmap_unlockPixels(env, bmpIn);
    LOGI("Return !! ");
    return 0;
}


static JNINativeMethod CoreMethods[] =
{
    {"SobelImage", "(Landroid/graphics/Bitmap;)I",(void *)Java_com_panda_org_angrypandacv_core_OpenCVHelper_SobelImage},
    {"Gray", "([III)[I",(void *)Java_com_panda_org_angrypandacv_core_OpenCVHelper_Gray}
};

int register_android_jni_core_module(JNIEnv* env, jclass clazz){
        return jniRegisterNativeMethods(env, clazz, CoreMethods, sizeof(CoreMethods) / sizeof(CoreMethods[0]));
}
