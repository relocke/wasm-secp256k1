#!/bin/bash
cd .submodules/secp256k1
./autogen.sh
./configure
make
make check
cd ../../


