# wasm-secp256k1

<span style="color:yellow;background:BLACK;padding:10px;">WORK IN PROGRESS</span>.


## MacOS setup homebrew edition

0. clone repo
> $ git clone --recursive https://github.com/relocke/wasm-secp256k1.git

1. Install LLVM
> $ brew install llvm
2. Activate instillation with
> $ export PATH=/usr/local/opt/llvm/bin:$PATH
3. check you have wasm32
> $ llc --version
<img src="static/wasm32-llc.png">

4. run build script
> $ source build.sh

5. build wasm

> $ source build_wasm.sh

--- 

## About .lib

#### GMP
Contains header files and libraries for [GMP](https://gmplib.org/)

#### wasi/libclang_rt.builtins-wasm32

Can be built from [wasi-sdk](https://github.com/WebAssembly/wasi-sdk) or download the directly from [here](https://github.com/WebAssembly/wasi-sdk/releases).


## Troubleshooting

### Missing libclang_rt.builtins-wasm32.a
<img src="static/error-linker.png">

To resolve this issue, you need to add `libclang_rt.builtins.a` library to the llvm path specified by the error.
Add the library `wasi/libclang_rt.builtins.a` into the path specified by your compiler.


### libsecp256k1-config.h modifications

<img src="static/config-errors.png">

If you get an error like in the above image, you can try and update the `libsecp256k1-config.h` file located in `.submodules/secp256k1/src/libsecp256k1-config.h` to a different configuration. 