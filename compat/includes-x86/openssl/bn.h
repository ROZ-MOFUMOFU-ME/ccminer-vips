/*
 * Minimal self-contained openssl/bn.h for the bundled (RainbowMiner) OpenSSL
 * 1.1.1 import libraries, whose header set ships only sha.h / e_os2.h /
 * opensslconf.h (+ the opensslv.h we add alongside). ccminer's bignum.hpp
 * (the >= 1.1.0 BIGNUM wrapper used by net-diff / nBits handling) needs the
 * BN_* declarations below; the prototypes match OpenSSL 1.1.1 exactly and the
 * symbols resolve against the bundled libcrypto. BIGNUM / BN_CTX stay opaque
 * (already the case in 1.1.x), so no struct layout is assumed here.
 */

#ifndef HEADER_BN_H
# define HEADER_BN_H

# include <stddef.h>

/* 64-bit limbs on Win64 (SIXTY_FOUR_BIT), 32-bit on Win32 — must match the
 * ABI of BN_get_word / BN_set_word in the precompiled libcrypto. */
# if defined(_WIN64) || defined(__x86_64__) || defined(_M_X64)
#  define BN_ULONG unsigned long long
# else
#  define BN_ULONG unsigned int
# endif

# ifdef __cplusplus
extern "C" {
# endif

typedef struct bignum_st BIGNUM;
typedef struct bignum_ctx BN_CTX;

BIGNUM *BN_new(void);
void BN_clear_free(BIGNUM *a);
BIGNUM *BN_copy(BIGNUM *a, const BIGNUM *b);

int BN_set_word(BIGNUM *a, BN_ULONG w);
BN_ULONG BN_get_word(const BIGNUM *a);
const BIGNUM *BN_value_one(void);

BN_CTX *BN_CTX_new(void);
void BN_CTX_free(BN_CTX *c);

int BN_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int BN_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int BN_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx);
int BN_div(BIGNUM *dv, BIGNUM *rem, const BIGNUM *m, const BIGNUM *d,
           BN_CTX *ctx);
# define BN_mod(rem, m, d, ctx) BN_div(NULL, (rem), (m), (d), (ctx))

int BN_lshift(BIGNUM *r, const BIGNUM *a, int n);
int BN_rshift(BIGNUM *r, const BIGNUM *a, int n);
int BN_cmp(const BIGNUM *a, const BIGNUM *b);

void BN_set_negative(BIGNUM *b, int n);
int BN_is_negative(const BIGNUM *b);
int BN_is_zero(const BIGNUM *a);
int BN_num_bits(const BIGNUM *a);
# define BN_num_bytes(a) ((BN_num_bits(a) + 7) / 8)

int BN_bn2mpi(const BIGNUM *a, unsigned char *to);
BIGNUM *BN_mpi2bn(const unsigned char *s, int len, BIGNUM *ret);

# ifdef __cplusplus
}
# endif

#endif /* HEADER_BN_H */
