clang \
-Oz \
--target=wasm32-unknown-wasi \
--sysroot .lib/wasi-libc \
-nostartfiles \
-Wl,--no-entry \
-I .lib/gmp/include \
-I .submodules/secp256k1/include \
-I .submodules/secp256k1 \
-D HAVE_CONFIG_H=true \
-Wl,--export="get_public_key" \
-Wl,--export="valid_private_key" \
-Wl,--export="get_ptr" \
-Wl,--export="sign" \
-Wl,--export="verify_signature" \
-o wasm/wasm_secp256k1.wasm src/wasm_secp256k1.c .submodules/secp256k1/src/secp256k1.c

mkdir tmp
wasm2wat wasm/wasm_secp256k1.wasm -o tmp/wasm_secp256k1.wat
awk -f scripts/rm_fd_close.awk tmp/wasm_secp256k1.wat > tmp/one.wat
awk -f scripts/rm_fd_seek.awk tmp/one.wat > tmp/two.wat
awk -f scripts/rm_fd_write.awk tmp/two.wat > tmp/four.wat
wat2wasm tmp/four.wat -o tmp/wasm_secp256k1.wasm
wasm-snip tmp/wasm_secp256k1.wasm -o wasm/secp256k1.wasm
rm -r tmp

