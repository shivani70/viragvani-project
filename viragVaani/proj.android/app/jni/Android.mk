LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES := $(LOCAL_PATH)/hellocpp/main.cpp \
                   $(LOCAL_PATH)/../../../Classes/AppDelegate.cpp \
                   $(LOCAL_PATH)/../../../Classes/HelloWorldScene.cpp\
                   $(LOCAL_PATH)/../../../Classes/FeedBackLayer.cpp\
                   $(LOCAL_PATH)/../../../Classes/Mainpage_layer.cpp\
                   $(LOCAL_PATH)/../../../Classes/HomePage_layer.cpp\
                   $(LOCAL_PATH)/../../../Classes/Janiye_aacharya_layer.cpp\
                   $(LOCAL_PATH)/../../../Classes/support/Common.cpp\
                   $(LOCAL_PATH)/../../../Classes/support/CustomHttpRequest.cpp\
                   $(LOCAL_PATH)/../../../Classes/support/LoaderLayer.cpp\
                   $(LOCAL_PATH)/../../../Classes/support/SoundController.cpp\
                   $(LOCAL_PATH)/../../../Classes/support/TouchableLayer.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static
LOCAL_STATIC_LIBRARIES += creator_reader

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-add-path, $(LOCAL_PATH)/../../../cocos2d)
$(call import-module, ./../../Classes/reader)  # import module path

$(call import-module, cocos)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
