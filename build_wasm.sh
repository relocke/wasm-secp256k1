clang \
--target=wasm32-unknown-wasi \
--sysroot .lib/wasi-libc \
-nostartfiles \
-Wl,--import-memory \
-Wl,--no-entry \
-I .lib/gmp/include \
-I .submodules/secp256k1/include \
-I .submodules/secp256k1 \
-D HAVE_CONFIG_H=true \
-Wl,--export="generate_public_key" \
-o wasm/generate_public_key.wasm  src/generate_public_key.c .submodules/secp256k1/src/secp256k1.c