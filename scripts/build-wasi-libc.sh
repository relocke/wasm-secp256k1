#!/bin/bash
cd .submodules/wasi-libc
make install INSTALL_DIR=../.lib/wasi-libc
cd ../../