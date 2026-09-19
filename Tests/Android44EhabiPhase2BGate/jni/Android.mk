LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := agr_eh2b_probe
LOCAL_SRC_FILES := probe.cpp
LOCAL_ARM_MODE := thumb
include $(BUILD_SHARED_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE := agr_eh2b_types
LOCAL_SRC_FILES := types.cpp
LOCAL_ARM_MODE := thumb
include $(BUILD_SHARED_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE := agr_eh2b_suite
LOCAL_SRC_FILES := suite.cpp
LOCAL_SHARED_LIBRARIES := agr_eh2b_types agr_eh2b_probe
LOCAL_ARM_MODE := thumb
include $(BUILD_SHARED_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE := agr_eh2b_C
LOCAL_SRC_FILES := c.cpp
LOCAL_SHARED_LIBRARIES := agr_eh2b_types agr_eh2b_probe
LOCAL_ARM_MODE := thumb
include $(BUILD_SHARED_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE := agr_eh2b_B
LOCAL_SRC_FILES := b.cpp
LOCAL_SHARED_LIBRARIES := agr_eh2b_C agr_eh2b_probe
LOCAL_ARM_MODE := arm
include $(BUILD_SHARED_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE := agr_eh2b_A
LOCAL_SRC_FILES := a.cpp
LOCAL_SHARED_LIBRARIES := agr_eh2b_B agr_eh2b_types agr_eh2b_probe
LOCAL_ARM_MODE := thumb
include $(BUILD_SHARED_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE := agr_eh2b_reference
LOCAL_SRC_FILES := reference.c
LOCAL_LDLIBS := -ldl
include $(BUILD_EXECUTABLE)
