# AMITY

Copyright (c) 2018 The Amity Project.

Copyright (c) 2018 The NERVA Project.

Copyright (c) 2017-2018 The Masari Project.

Copyright (c) 2014-2018 The Monero Project.

Portions Copyright (c) 2012-2013 The Cryptonote developers.


## License

See [LICENSE](LICENSE).

## Build Instructions

#### Linux

##### One Liner for all Dependencies (Ubuntu/Debian):   
`sudo apt-get install git curl ca-certificates nano zip unzip tar xz-utils cmake g++ make pkg-config libtool-bin autoconf automake build-essential cmake pkg-config pcsc-tools pcscd libpcsclite1 python-dev virtualenv libudev-dev libhidapi-dev libzmq3-dev libunbound-dev libboost-all-dev libusb-1.0-0-dev libusb-dev libssl-dev libsodium-dev libcurl4-openssl-dev libminiupnpc-dev libunwind8-dev liblzma-dev libreadline6-dev libldns-dev libexpat1-dev libgtest-dev doxygen graphviz libhidapi-libusb0`  
  
 ##### Build Commands

-`git clone --recursive https://github.com/CalexCore/AmityCoinV3.git`  
-`cd AmityCoinV3`  
-`./builder/linux`
  
Binaries will be found in `/builder/build/release/bin/`
