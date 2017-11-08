LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)


#OpenCV_INSTALL_MODULES := on
OPENCV_INSTALL_MODULES:=on
OpenCV_CAMERA_MODULES := off

OPENCV_LIB_TYPE := SHARED

ifeq ("$(wildcard $(OPENCV_MK_PATH))","")
include ..\..\..\..\native\jni\OpenCV.mk
else
include $(OPENCV_MK_PATH)
endif

LOCAL_MODULE := OpenCV

LOCAL_SRC_FILES := cv_core.cpp \
                    cv_native.cpp \
                    cv_utils.cpp

LOCAL_C_INCLUDE := $(LOCAL_PATH)

LOCAL_LDLIBS +=  -lm -llog -ljnigraphics

include $(BUILD_SHARED_LIBRARY)