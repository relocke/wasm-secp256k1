#include "secp256k1.h"

unsigned char sha256_data[32];
unsigned char private_key[32];
unsigned char public_key[33];
unsigned char der_signature[70];
unsigned char seed[32];

unsigned char *get_ptr(int x)
{
    unsigned char *ptr;
    switch (x)
    {
    case 0:
        ptr = private_key;
        break;
    case 1:
        ptr = public_key;
        break;
    case 2:
        ptr = der_signature;
        break;
    case 3:
        ptr = seed;
        break;
    default:
        ptr = sha256_data;
        break;
    }
    return ptr;
};

int sign()
{
    secp256k1_context *ctx = NULL;
    int res;
    size_t len;
    ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
    res = secp256k1_context_randomize(ctx, seed);
    if (!res)
        return -1;
    unsigned char der[72];
    len = sizeof(der);
    secp256k1_ecdsa_signature sig;
    res = secp256k1_ecdsa_sign(ctx, &sig, sha256_data, private_key, NULL, NULL);
    if (!res)
        return -2;

    res = secp256k1_ecdsa_signature_serialize_der(ctx, der, &len, &sig);
    if (!res)
        return 0;
    for (int i = 0; i < len; i++)
        der_signature[i] = der[i];
    // remove private key from memory
    for (int i = 0; i < 32; i++)
        private_key[i] = 0;
    secp256k1_context_destroy(ctx);
    return res;
}
int verify_signature()
{
    int res;
    secp256k1_context *ctx = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY);
    secp256k1_ecdsa_signature sig;
    secp256k1_pubkey pubkey;
    res = secp256k1_ec_pubkey_parse(ctx, &pubkey, public_key, sizeof(public_key));
    if (!res)
        return -1;

    res = secp256k1_ecdsa_signature_parse_der(ctx, &sig, der_signature, sizeof(der_signature));
    if (!res)
        return -2;
    res = secp256k1_ecdsa_verify(ctx, &sig, sha256_data, &pubkey);
    secp256k1_context_destroy(ctx);
    return res;
}
int valid_private_key()
{
    secp256k1_context *ctx;
    ctx = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY);
    int res = secp256k1_ec_seckey_verify(ctx, private_key);
    secp256k1_context_destroy(ctx);
    return res;
}
int get_public_key()
{
    size_t clen = 65;
    secp256k1_context *ctx;
    secp256k1_pubkey pubkey;
    ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);

    int res = secp256k1_ec_seckey_verify(ctx, private_key);
    if (!res)
        return -1;

    res = secp256k1_ec_pubkey_create(ctx, &pubkey, private_key);
    if (!res)
        return -2;

    secp256k1_ec_pubkey_serialize(ctx, public_key, &clen, &pubkey, SECP256K1_EC_COMPRESSED);

    secp256k1_context_destroy(ctx);

    return 1;
}
