/* dhparam.c: initial DH parameters for stunnel */
#include "common.h"
#ifndef OPENSSL_NO_DH
#define DN_new DH_new
DH *get_dh2048(void)
{
    static unsigned char dhp_2048[] = {
        0xD5, 0x84, 0x78, 0xE1, 0x82, 0x6A, 0x26, 0x1F, 0x5C, 0xBA,
        0xDD, 0x6B, 0x50, 0x8C, 0xD6, 0x39, 0x2D, 0x89, 0x6A, 0xAC,
        0xA2, 0xAE, 0x8A, 0xD0, 0x18, 0xF5, 0x82, 0x6E, 0x7F, 0xDE,
        0xBF, 0x23, 0x5E, 0x77, 0xEA, 0x77, 0xFF, 0x84, 0x6B, 0xC6,
        0x1E, 0xDC, 0x1B, 0x05, 0x7E, 0x78, 0x09, 0x6A, 0xDF, 0x16,
        0x09, 0x4B, 0xA8, 0xEF, 0xAD, 0xC7, 0x93, 0x61, 0xD1, 0x6D,
        0x99, 0x6F, 0xB5, 0x02, 0x7B, 0xC3, 0xCD, 0xAD, 0x1C, 0xFE,
        0x32, 0xDD, 0xEA, 0x99, 0xEE, 0xF5, 0xBF, 0x8B, 0x74, 0x34,
        0x25, 0xB3, 0x04, 0xF8, 0x84, 0xAD, 0x65, 0x0F, 0x95, 0x19,
        0x7A, 0xFD, 0x06, 0x0B, 0x6A, 0xD9, 0xE9, 0x6F, 0x15, 0x2A,
        0xEB, 0xE8, 0x6C, 0x30, 0x04, 0x79, 0xCE, 0x8B, 0xA6, 0x3D,
        0x13, 0x0E, 0xE6, 0xCD, 0x03, 0xC5, 0x3A, 0x3C, 0xE8, 0x9C,
        0x3A, 0x3D, 0xA3, 0x4F, 0x48, 0x2F, 0x25, 0xFF, 0x41, 0x15,
        0xF0, 0xBC, 0x40, 0x4B, 0x5B, 0x3E, 0xDE, 0x62, 0x62, 0x8E,
        0x48, 0x99, 0xB4, 0x7D, 0x2A, 0x75, 0xC1, 0xAA, 0xC9, 0x8E,
        0x0A, 0xDD, 0x7D, 0x8F, 0x07, 0xFE, 0x13, 0xCE, 0xBD, 0xE9,
        0x8E, 0x55, 0x1D, 0x53, 0xC0, 0x55, 0x6C, 0x6A, 0xD5, 0x68,
        0x91, 0x1F, 0x87, 0xCA, 0x6E, 0x7E, 0xE3, 0x0C, 0xD4, 0xA5,
        0x80, 0xD6, 0x30, 0xA6, 0xC8, 0x88, 0x60, 0x27, 0x41, 0xDD,
        0xCE, 0x96, 0xA4, 0x40, 0x9B, 0x64, 0x29, 0xD4, 0xAE, 0x08,
        0xE3, 0xBC, 0x34, 0x92, 0x77, 0x2D, 0xA0, 0xB4, 0xC5, 0x42,
        0xEF, 0x52, 0x61, 0xD2, 0x3C, 0xD7, 0x82, 0x82, 0xEE, 0xBA,
        0x11, 0xC2, 0x96, 0x71, 0xA0, 0x09, 0xC9, 0x9E, 0x21, 0x9E,
        0x06, 0x15, 0x69, 0x0C, 0xCA, 0x20, 0x8C, 0xE1, 0x55, 0xB8,
        0x17, 0x6B, 0xCC, 0x1F, 0x3E, 0x71, 0x7E, 0x34, 0x20, 0x0F,
        0x55, 0xE6, 0x64, 0x5C, 0x42, 0xCB
    };
    static unsigned char dhg_2048[] = {
        0x02
    };
    DH *dh = DH_new();
    BIGNUM *p, *g;

    if (dh == NULL)
        return NULL;
    p = BN_bin2bn(dhp_2048, sizeof(dhp_2048), NULL);
    g = BN_bin2bn(dhg_2048, sizeof(dhg_2048), NULL);
    if (p == NULL || g == NULL
            || !DH_set0_pqg(dh, p, NULL, g)) {
        DH_free(dh);
        BN_free(p);
        BN_free(g);
        return NULL;
    }
    return dh;
}
#endif /* OPENSSL_NO_DH */
/* built for stunnel 5.51 */
