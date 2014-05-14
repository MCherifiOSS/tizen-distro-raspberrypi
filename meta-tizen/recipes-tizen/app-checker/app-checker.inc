DESCRIPTION = "App Checker"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache License, Version 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

PROVIDES = ""

#PROVIDES by app-checker-server-dev 


#PROVIDES by app-checker-dev 


#PROVIDES by app-checker 


#PROVIDES by app-checker-server 


RDEPENDS = ""
#RDEPENDS of app-checker-server-dev (${PN}-server-dev)
RDEPENDS_${PN}-server-dev += "app-checker-server"

#RDEPENDS of app-checker-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "app-checker"

#RDEPENDS of app-checker-server (${PN}-server)
RDEPENDS_${PN}-server += "app-checker"


DEPENDS = ""
#DEPENDS of app-checker 
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "dlog"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/app-checker.manifest .
 
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ; 
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
 LD_AS_NEEDED=1; export LD_AS_NEEDED ; 
 
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
         -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
         -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
         -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
         -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
         -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON . 
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}${prefix}/lib/ac-plugins
 
 
 
}

PACKAGES += " app-checker-server-dev "
PACKAGES += " app-checker-server "

app-checker-server-dev_files = ""
app-checker-server-dev_files += "app-checker.manifest"
app-checker-server-dev_files += "${prefix}/lib/libapp-checker-server.so"
app-checker-server-dev_files += "${prefix}/lib/pkgconfig/app-checker-server.pc"
app-checker-server-dev_files += "/usr/include/app-checker/app-checker-server.h"

app-checker-server_files = ""
app-checker-server_files += "app-checker.manifest"
app-checker-server_files += "${prefix}/lib/libapp-checker-server.so.0"
app-checker-server_files += "${prefix}/lib/libapp-checker-server.so.0.1.0"

app-checker_files = ""
app-checker_files += "app-checker.manifest"
app-checker_files += "${prefix}/lib/libapp-checker.so.0"
app-checker_files += "${prefix}/lib/libapp-checker.so.0.1.0"
app-checker_files += "${prefix}/lib/ac-plugins"

app-checker-dev_files = ""
app-checker-dev_files += "app-checker.manifest"
app-checker-dev_files += "${prefix}/lib/libapp-checker.so"
app-checker-dev_files += "${prefix}/lib/pkgconfig/app-checker.pc"
app-checker-dev_files += "/usr/include/app-checker/app-checker.h"

FILES_${PN}-server-dev = "${app-checker-server-dev_files}"
FILES_${PN}-server = "${app-checker-server_files}"
FILES_${PN} = "${app-checker_files}"
FILES_${PN}-dev = "${app-checker-dev_files}"

PKG_app-checker-server-dev= "app-checker-server-dev"
PKG_app-checker-server= "app-checker-server"
PKG_app-checker= "app-checker"
PKG_app-checker-dev= "app-checker-dev"

require app-checker-extraconf.inc
