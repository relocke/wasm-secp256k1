#include <secp256k1.h>

unsigned char* private_key;
unsigned char* get_ptr() {
    return private_key;
}


unsigned char* get_publickey(int x) {

    int len = 32;
    unsigned char* priv_ptr = get_ptr();
    unsigned char CPubKey[65];  // public storage
    unsigned char prikey[len];
    size_t clen = 65;
    unsigned char* err = 0;
    secp256k1_context *secp256k1_context_sign;
    secp256k1_pubkey pubkey;
    secp256k1_context_sign = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);

    for (int i = 0; i < 32; i += 1) 
        prikey[i] = priv_ptr[i];


    int ret = secp256k1_ec_pubkey_create(secp256k1_context_sign, &pubkey, prikey);
    if (!ret) {
        secp256k1_context_destroy(secp256k1_context_sign);
        return err;
    }
    
    secp256k1_ec_pubkey_serialize(secp256k1_context_sign, CPubKey, &clen, &pubkey, SECP256K1_EC_COMPRESSED);

    if (secp256k1_context_sign)
        secp256k1_context_destroy(secp256k1_context_sign);
    unsigned char *ptr = (unsigned char *)CPubKey;

    return ptr;
}




