package=unwind
$(package)_version=1.2.1
$(package)_download_path=https://download.savannah.nongnu.org/releases/libunwind
$(package)_file_name=lib$(package)-$($(package)_version).tar.gz
$(package)_sha256_hash=3f3ecb90e28cbe53fba7a4a27ccce7aad188d3210bb1964a923a731a27a75acb

define $(package)_config_cmds
  cp -f $(BASEDIR)/config.guess config/config.guess &&\
  cp -f $(BASEDIR)/config.sub config/config.sub &&\
  $($(package)_autoconf) --disable-shared --enable-static
endef

define $(package)_build_cmds
  $(MAKE)
endef

define $(package)_stage_cmds
  $(MAKE) DESTDIR=$($(package)_staging_dir) install
endef

define $(package)_postprocess_cmds
  rm lib/*.la
endef

