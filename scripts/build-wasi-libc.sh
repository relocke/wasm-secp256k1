#!/bin/bash
cd wasi-libc
make install INSTALL_DIR=../.lib/wasi-libc
cd ..