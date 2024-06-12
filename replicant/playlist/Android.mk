ifneq ($(REPLICANT_NO_PLAYLIST), 1)

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
include $(ROOT_REPLICANT)/PlatformName.mk
LOCAL_MODULE := playlist
LOCAL_MODULE_FILENAME := lib$(LOCAL_MODULE).$(PLATFORM_NAME).w6c

LOCAL_C_INCLUDES := $(ROOT_REPLICANT)
LOCAL_CFLAGS := -fvisibility=hidden

LOCAL_STATIC_LIBRARIES :=  nu foundation
LOCAL_SHARED_LIBRARIES := nx

LOCAL_SRC_FILES :=  main.cpp PlaylistManager.cpp

include $(BUILD_SHARED_LIBRARY)

endif