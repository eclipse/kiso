/********************************************************************************
* Copyright (c) 2010-2019 Robert Bosch GmbH
*
* This program and the accompanying materials are made available under the
* terms of the Eclipse Public License 2.0 which is available at
* http://www.eclipse.org/legal/epl-2.0.
*
* SPDX-License-Identifier: EPL-2.0
*
* Contributors:
*    Robert Bosch GmbH - initial contribution
*
********************************************************************************/

/**
 * @This file contains the public key for the signature validation
 *
 * Put here the documentation of this header file. Explain the interface exposed
 * by this header, e.g. what is the purpose of use, how to use it, etc.
 */

#ifndef PublicKey_H
#define PublicKey_H

#ifdef INSTKEY
/* Key from INST PKI */
/* Modulus of the public key */
const Esc_UINT8 CurrentMod[] =
{
        0xc7,0xe9,0x21,0x24,0x37,0xd5,0xfc,0xa0,0x39,0x98,
        0xdd,0x59,0xdc,0xba,0xcd,0x9f,0x94,0x88,0xe2,0xbd,
        0x34,0x88,0xe8,0x79,0x02,0x5e,0x0a,0x18,0x55,0x49,
        0xf4,0xaf,0xff,0xb2,0x4a,0x79,0x4c,0xe5,0xe0,0x2e,
        0x80,0xf6,0xd6,0x4a,0xa0,0x59,0x86,0x97,0x94,0x4a,
        0xaa,0x42,0xf7,0x86,0x91,0x4c,0xc5,0xd9,0xc8,0x38,
        0x36,0x01,0x3b,0x7f,0x9c,0x59,0x8f,0xa0,0x7e,0xa3,
        0xe7,0xfe,0xd2,0x26,0x3c,0x55,0x3f,0x7a,0xf2,0x08,
        0xbb,0xbb,0x61,0x7e,0x41,0xb3,0x14,0x00,0x7b,0xa3,
        0x02,0x91,0xf9,0x89,0xfe,0x83,0x7f,0x58,0xbf,0x35,
        0x2e,0xca,0xff,0xf1,0x0a,0x95,0x81,0x5e,0xe7,0x76,
        0x0f,0x2b,0x0a,0xd9,0xc0,0x76,0x60,0xa7,0xdb,0x5b,
        0x4d,0xd8,0x6e,0x49,0x34,0xa9,0x08,0xba,0xbb,0x06,
        0xa4,0xeb,0x65,0x35,0x24,0xfc,0xf5,0x9d,0x88,0x97,
        0x63,0x3f,0xe7,0x24,0xa2,0xba,0x27,0xa8,0x96,0x3d,
        0xbd,0x8a,0xc2,0x71,0x80,0x23,0xa0,0x32,0x8d,0xc7,
        0x23,0x1f,0x51,0x14,0xed,0x91,0x1a,0x3e,0x44,0xd4,
        0xef,0x17,0x7e,0x79,0x63,0x15,0x9f,0x53,0x33,0x8e,
        0xe5,0x42,0xde,0x73,0xd1,0x9b,0x31,0x5a,0x63,0x58,
        0x1d,0x36,0x32,0x95,0xac,0x99,0x28,0xf4,0xbb,0x0f,
        0x18,0x75,0x4f,0x39,0x4c,0x4d,0x91,0x67,0xa5,0x56,
        0x4b,0x85,0xc1,0x77,0x20,0xe9,0xe0,0x21,0xac,0x9e,
        0xe2,0x36,0x66,0xd2,0x4f,0x48,0x3a,0xa8,0x61,0xd2,
        0x3e,0xc6,0xb1,0x56,0x5b,0xcf,0xe4,0x04,0x5a,0x30,
        0x63,0x09,0x5d,0xba,0x34,0xc3,0xde,0x0e,0xe6,0xa5,
        0xac,0xf4,0x83,0x4d,0x8e,0xa9

};
const Esc_UINT16 keySizeBits = UINT16_C(2048); /* key size */
const Esc_UINT32 pubExp = UINT32_C(65537); /* Modulus Exponent value */

#else
/* Modulus of the public key */
const Esc_UINT8 CurrentMod[] =
{
        0xa7,0xcb,0xae,0x23,0x0f,0x0d,0xbe,0x66,0x4a,0x32,
        0x4f,0x55,0x68,0x3c,0x80,0x11,0xf9,0xb2,0x8d,0x17,
        0x78,0x0f,0x62,0xab,0xc2,0xa1,0xef,0x46,0x18,0xff,
        0x82,0x54,0xee,0x3a,0x01,0x94,0x87,0x55,0x03,0xc0,
        0xab,0x06,0xe3,0x5e,0x28,0x0e,0x53,0xa4,0x2d,0xcf,
        0xf7,0x1c,0xcd,0x4a,0xf6,0xa9,0x52,0xf0,0xb9,0xbe,
        0x65,0xe7,0xc3,0x95,0x33,0xdb,0x45,0xb0,0x59,0x73,
        0x97,0x81,0xb3,0xab,0x1b,0x27,0x22,0x1e,0xd4,0x99,
        0xa5,0x5b,0x78,0xd6,0xfd,0x0c,0x40,0xd5,0x4d,0x3a,
        0xfe,0x45,0xd6,0x2a,0x69,0x2e,0x13,0x01,0x8f,0x73,
        0xfa,0xc5,0x47,0xc0,0x1c,0xa9,0x51,0x85,0x49,0xf5,
        0x58,0x88,0x2f,0x43,0x25,0xb1,0x6f,0x07,0xb1,0x54,
        0x9f,0xf3,0x48,0x39,0x18,0xb1,0x84,0xfc,0xab,0x89,
        0x77,0x8f,0x63,0x2e,0x2c,0xbe,0x0a,0x2b,0x03,0x30,
        0x3a,0xd9,0xf5,0xa7,0x09,0x9a,0x86,0xd9,0x2c,0x80,
        0xde,0x15,0x4c,0xee,0x9f,0x3b,0x24,0xaf,0x85,0xbe,
        0xad,0xa1,0x17,0x88,0x1a,0x43,0x92,0x4b,0x24,0xa6,
        0xe5,0xa8,0x46,0xca,0x54,0xc8,0xc3,0xa3,0xaa,0xbc,
        0xed,0xc1,0xfe,0x10,0xc7,0x3b,0x91,0x9c,0xda,0x0a,
        0x0a,0x2f,0xbe,0x12,0x3e,0xbd,0x60,0xcb,0x87,0x27,
        0x7e,0x34,0x91,0xe1,0xbf,0x0e,0x53,0x83,0xdb,0x69,
        0xba,0x51,0x38,0xeb,0xbb,0xb6,0x3b,0xb6,0xa0,0x5f,
        0x07,0xda,0xc0,0x7d,0xb8,0xfc,0x2f,0x93,0xe6,0xe3,
        0x94,0x25,0x8b,0x60,0x44,0x16,0xb9,0x31,0xe9,0x77,
        0x13,0x40,0xac,0xe9,0x3e,0x81,0x42,0x34,0x4c,0xdc,
        0x4f,0xbf,0x03,0x11,0x87,0x05
};
const Esc_UINT16 keySizeBits = UINT16_C(2048); /* key size */
const Esc_UINT32 pubExp = UINT32_C(65537); /* Modulus Exponent value */
#endif /* INSTKEY */

#endif /* PublicKey_H */

