#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <openssl/md5.h>

char *md5(const char *str, int length) {
    MD5_CTX c;
    uint8_t digest[MD5_DIGEST_LENGTH];
    char *out = (char*) malloc(MD5_DIGEST_LENGTH * 2 + 1);

    MD5_Init(&c);

    while (length > 0) {
        if (length > 512) {
            MD5_Update(&c, str, 512);
        } else {
            MD5_Update(&c, str, length);
        }
        length -= 512;
        str += 512;
    }

    MD5_Final(digest, &c);

    for (int n = 0; n < MD5_DIGEST_LENGTH; ++n) {
        snprintf(out + n*2, 3, "%02x", digest[n]);
    }

    out[MD5_DIGEST_LENGTH * 2] = '\0';

    return out;
}