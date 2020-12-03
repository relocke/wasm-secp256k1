#!/bin/bash
CURRENT_DIR=$(pwd)
cd /usr/local/Cellar
K=$(find "$PWD" -type d | grep 'llvm/[0-9.]\+/lib/clang/[0-9.]\+/lib$')
cp -R $CURRENT_DIR/.lib/wasi $K
cd $CURRENT_DIR
