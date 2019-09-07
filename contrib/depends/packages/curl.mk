package=curl
$(package)_version=7.65.3
$(package)_download_path=http://curl.haxx.se/download/
$(package)_file_name=$(package)-$($(package)_version).tar.gz
$(package)_sha256_hash=4376ac72b95572fb6c4fbffefb97c7ea0dd083e1974c0e44cd7e49396f454839


define $(package)_config_cmds
  ./configure --prefix="${BASEDIR}/curl" --with-ssl --without-zlib --disable-dict --disable-ftp --disable-gopher --disable-file --disable-imap --disable-ldap --disable-ldaps --disable-pop3 --disable-proxy --disable-rtsp --disable-smtp --disable-telnet --disable-tftp --disable-smb --disable-smbs --disable-psl --without-brotli --without-libidn2 --disable-ftmp --without-libpsl --without-librtmp --enable-static --disable-shared

endef

define $(package)_build_cmds
  $(MAKE) 
endef

define $(package)_stage_cmds
  mkdir $($(package)_staging_prefix_dir)/include &&\
  $(MAKE) DESTDIR=$($(package)_staging_dir) install
endef

