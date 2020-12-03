#!/bin/bash
cd secp256k1
./autogen.sh
./configure
make
make check


