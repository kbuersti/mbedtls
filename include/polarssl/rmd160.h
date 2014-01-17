/**
 * \file rdm160.h
 *
 * \brief RIPE MD-160 message digest
 *
 *  Copyright (C) 2014-2014, Brainspark B.V.
 *
 *  This file is part of PolarSSL (http://www.polarssl.org)
 *  Lead Maintainer: Paul Bakker <polarssl_maintainer at polarssl.org>
 *
 *  All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#ifndef POLARSSL_RMD160_H
#define POLARSSL_RMD160_H

#include "config.h"

#include <string.h>

#if defined(_MSC_VER) && !defined(EFIX64) && !defined(EFI32)
#include <basetsd.h>
typedef UINT32 uint32_t;
#else
#include <inttypes.h>
#endif

#define POLARSSL_ERR_RMD160_FILE_IO_ERROR                 -0x0074  /**< Read/write error in file. */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief          RMD160 context structure
 */
typedef struct
{
    uint32_t total[2];          /*!< number of bytes processed  */
    uint32_t state[5];          /*!< intermediate digest state  */
    unsigned char buffer[64];   /*!< data block being processed */
}
rmd160_context;

/**
 * \brief          RMD160 context setup
 *
 * \param ctx      context to be initialized
 */
void rmd160_starts( rmd160_context *ctx );

/**
 * \brief          RMD160 process buffer
 *
 * \param ctx      RMD160 context
 * \param input    buffer holding the  data
 * \param ilen     length of the input data
 */
void rmd160_update( rmd160_context *ctx,
                    const unsigned char *input, size_t ilen );

/**
 * \brief          RMD160 final digest
 *
 * \param ctx      RMD160 context
 * \param output   RMD160 checksum result
 */
void rmd160_finish( rmd160_context *ctx, unsigned char output[16] );

/**
 * \brief          Output = RMD160( input buffer )
 *
 * \param input    buffer holding the  data
 * \param ilen     length of the input data
 * \param output   RMD160 checksum result
 */
void rmd160( const unsigned char *input, size_t ilen,
             unsigned char output[16] );

#if defined(POLARSSL_FS_IO)
/**
 * \brief          Output = RMD160( file contents )
 *
 * \param path     input file name
 * \param output   RMD160 checksum result
 *
 * \return         0 if successful, or POLARSSL_ERR_RMD160_FILE_IO_ERROR
 */
int rmd160_file( const char *path, unsigned char output[16] );
#endif /* POLARSSL_FS_IO */


/**
 * \brief          Checkup routine
 *
 * \return         0 if successful, or 1 if the test failed
 */
int rmd160_self_test( int verbose );

#ifdef __cplusplus
}
#endif

#endif /* rmd160.h */
