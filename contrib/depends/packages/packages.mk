packages:=boost openssl zeromq cppzmq expat ldns readline libiconv hidapi protobuf libusb
native_packages := native_ccache native_protobuf

darwin_native_packages = native_biplist native_ds_store native_mac_alias
darwin_packages = sodium-darwin ncurses

linux_packages = eudev ncurses sodium
qt_packages = qt

ifeq ($(build_tests),ON)
packages += gtest
endif

ifeq ($(host_os),linux)
ifneq ($(host_arch),riscv64)
packages += unwind
packages += sodium
endif
endif

ifeq ($(host_os),mingw32)
packages += icu4c
packages += sodium
packages += ncurses
endif

ifneq ($(build_os),darwin)
darwin_native_packages += native_cctools native_cdrkit native_libdmg-hfsplus
endif

