require avahi.inc

LIC_FILES_CHKSUM = "file://LICENSE;md5=2d5025d4aa3495befef8f17206a5b0a1 \
                    file://avahi-common/address.h;endline=25;md5=b1d1d2cda1c07eb848ea7d6215712d9d \
                    file://avahi-core/dns.h;endline=23;md5=6fe82590b81aa0ddea5095b548e2fdcb \
                    file://avahi-daemon/main.c;endline=21;md5=9ee77368c5407af77caaef1b07285969 \
                    file://avahi-client/client.h;endline=23;md5=f4ac741a25c4f434039ba3e18c8674cf"

RDEPENDS_avahi-daemon = "sysvinit-pidof"
PR = "r1"

EXTRA_OECONF += "--disable-gtk3"

FILES_avahi-autoipd = "${sbindir}/avahi-autoipd \
                       ${sysconfdir}/avahi/avahi-autoipd.action \
		       ${sysconfdir}/dhcp3/*/avahi-autoipd"
