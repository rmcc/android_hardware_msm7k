ifeq ($(strip $(BOARD_USES_QCOM_HARDWARE)), true)

# When zero we link against libmmcamera; when 1, we dlopen libmmcamera.
DLOPEN_LIBMMCAMERA:=1

ifneq ($(BUILD_TINY_ANDROID),true)

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_CFLAGS:=-fno-short-enums
LOCAL_SRC_FILES:= QualcommCameraHardware.cpp

GENERIC_CFLAGS:= -Dlrintf=_ffix_r -D__align=__alignx -include stdint.h \
        -D__alignx\(x\)=__attribute__\(\(__aligned__\(x\)\)\) \
        -D_POSIX_SOURCE \
        -DPOSIX_C_SOURCE=199506L \
        -D_XOPEN_SOURCE=600 -D_XOPEN_SOURCE_EXTENDED=1 \
        -D_BSD_SOURCE=1 -D_SVID_SOURCE=1 -D_GNU_SOURCE -DT_ARM \
        -DCUST_H=\"custsdcaalba.h\" \
        -D__MSMHW_MODEM_PROC__=1 -D__MSMHW_APPS_PROC__=2 \
        -D__MSMHW_PROC_DEF__=__MSMHW_APPS_PROC__ \
        -DMSMHW_MODEM_PROC -DMSMHW_APPS_PROC \
        -DIMAGE_APPS_PROC -DQC_MODIFIED \
        -Dinline=__inline  -DASSERT=ASSERT_FATAL\
        -Dsvcsm_create=svcrtr_create \
        -DCONFIG_MSM7600  \
        -DDLOPEN_LIBMMCAMERA=$(DLOPEN_LIBMMCAMERA) #\
	#-include camera_defs_i.h 

LOCAL_CFLAGS+= $(GENERIC_CFLAGS)

LOCAL_SHARED_LIBRARIES:= libutils libui liblog

ifneq ($(DLOPEN_LIBMMCAMERA),1)
LOCAL_SHARED_LIBRARIES+= libmmcamera libmmcamera_target
else
LOCAL_SHARED_LIBRARIES+= libdl
endif

LOCAL_MODULE:= libcamera
include $(BUILD_SHARED_LIBRARY)

endif

endif # BOARD_USES_QCOM_HARDWARE
