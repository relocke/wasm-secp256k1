#!/bin/bash
cd .submodules/secp256k1/
./autogen.sh
./configure
make INSTALL_DIR=../../.lib/secp256k1
cp ../../.lib/libsecp256k1-config.h src/libsecp256k1-config.h
cd ../wasi-libc
make install INSTALL_DIR=../../.lib/wasi-libc
cd ../../

