require privacy-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/privacy-manager;tag=5989bdf8a27392f56de66b3b093d853e92093aa9;nobranch=1"

BBCLASSEXTEND = "native"
