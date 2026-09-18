LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := agr_eh2_probe
LOCAL_SRC_FILES := probe.cpp
LOCAL_ARM_MODE := thumb
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := agr_eh2_same
LOCAL_SRC_FILES := same.cpp
LOCAL_SHARED_LIBRARIES := agr_eh2_probe
LOCAL_ARM_MODE := thumb
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := agr_eh2_C
LOCAL_SRC_FILES := c.cpp
LOCAL_SHARED_LIBRARIES := agr_eh2_probe
LOCAL_ARM_MODE := thumb
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := agr_eh2_B
LOCAL_SRC_FILES := b.cpp
LOCAL_SHARED_LIBRARIES := agr_eh2_C agr_eh2_probe
LOCAL_ARM_MODE := arm
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := agr_eh2_A
LOCAL_SRC_FILES := a.cpp
LOCAL_SHARED_LIBRARIES := agr_eh2_B agr_eh2_probe
LOCAL_ARM_MODE := thumb
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := agr_eh2_reference
LOCAL_SRC_FILES := reference.c
LOCAL_LDLIBS := -ldl
include $(BUILD_EXECUTABLE)

