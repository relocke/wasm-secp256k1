<img src="static/wasm-secp256k1.svg" height=150px>

# wasm-secp256k1

## WORK IN PROGRESS! 🔨👷🚧

This repository generates portable [Web Assembly](https://webassembly.org/) (WASM) files that contain various cryptographic operations on the secp256k1 curve.

**These include:**

1. Signature generation
2. Signature validation
3. Private key generation

### About

Two submodules [libsecp256k1](https://github.com/bitcoin-core/secp256k1) and [WASI-libc](https://github.com/WebAssembly/wasi-libc) are used along with the LLVM tool chain to produce stand alone wasm files that may be ported to many different environments.

It is currently being employed in an [isomorphic JS](https://en.wikipedia.org/wiki/Isomorphic_JavaScript) environment for [ReLocke/SmartQL-signature](https://github.com/relocke/SmartQL-Signature).

Read more about wasi [here](https://hacks.mozilla.org/2019/03/standardizing-wasi-a-webassembly-system-interface/).

## MacOS setup homebrew

1. clone repo with submodules

```shell
git clone --recursive https://github.com/relocke/wasm-secp256k1.git
```

2. Install LLVM

```shell
brew install llvm
```

3. Activate instillation with

```shell
export PATH=/usr/local/opt/llvm/bin:$PATH
```

4. Check you have wasm32

```shell
llc --version
```

<img src="static/wasm32-llc.png" height="30px">

5. run build script

```shell
source build.sh
```

6. get the Web Assembly Binary Toolkit [WABT](https://github.com/WebAssembly/wabt)

```shell
$ brew install wabt
```

7. Install [wasm-snip](https://github.com/rustwasm/wasm-snip).

```shell
$ cargo install wasm-snip
```

8. build WASM

```shell
$ source wasm.sh
```

## Troubleshooting

### Missing libclang_rt.builtins-wasm32.a

<img src="static/error-linker.png">

To resolve this issue, you need to add `libclang_rt.builtins.a` library to the llvm path specified by the error.
Add the library `wasi/libclang_rt.builtins.a` into the path specified by your compiler.

### libsecp256k1-config.h modifications

<img src="static/config-errors.png">

If you get an error like in the above image, you can try and update the `libsecp256k1-config.h` file located in `.submodules/secp256k1/src/libsecp256k1-config.h` to a different configuration.
