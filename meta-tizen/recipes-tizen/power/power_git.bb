require power.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/power;tag=f58d6291c3a787f8fde033a050317f1aaea37226;nobranch=1"

BBCLASSEXTEND += " native "
