#!/bin/bash
set -e
P='\033[0;36m' 
NC='\033[0m'
echo "${P}Building wasi-libc${NC}"
source scripts/build-wasi-libc.sh
echo "${P}Building secp256k1 library${NC}"
source scripts/build-secp256k1.sh
echo "${P}adding wasi/libclang_rt.builtins-wasm32.a to llvm clang path${NC}"
source scripts/add_wasi_to_llvm.sh


