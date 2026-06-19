/*
 * Minimal opensslv.h supplied for the bundled (RainbowMiner) OpenSSL 1.1.1
 * import libraries. The upstream RainbowMiner header set ships sha.h /
 * e_os2.h / opensslconf.h but not opensslv.h; ccminer's bignum.cpp and
 * crypto/wildkeccak-cpu.cpp only need OPENSSL_VERSION_NUMBER to pick the
 * 1.1.x BIGNUM API path (>= 0x10100000L), so define just enough here.
 */

#ifndef HEADER_OPENSSLV_H
# define HEADER_OPENSSLV_H

# define OPENSSL_VERSION_NUMBER  0x1010100fL
# define OPENSSL_VERSION_TEXT    "OpenSSL 1.1.1 (bundled)"
# define OPENSSL_VERSION_PTEXT   " part of " OPENSSL_VERSION_TEXT

# define SHLIB_VERSION_HISTORY ""
# define SHLIB_VERSION_NUMBER "1.1"

#endif /* HEADER_OPENSSLV_H */
