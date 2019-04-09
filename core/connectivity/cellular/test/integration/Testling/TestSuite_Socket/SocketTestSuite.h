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
 * @file	Tests socket open,close and UDP data send functionalities.
 *
 * This interface tests different scenarios like multiple socket opens,
 * UDP send with various time delays and bytes to be send, socket close
 * APIs
 *
 */

#ifndef SocketTestSuite_H
#define SocketTestSuite_H


/* Include all headers which are needed by this file. */
#include "BCDS_Retcode.h"

/* Put the type and macro definitions here */
#define SOCKET_DELAY_260_SECS                   UINT32_C(260000)

/* convert the ascii value into decimal value */
#define SOCKET_ASCII_TO_DECIMAL_VALUE           0x30
#define SOCKET_GET_TLV_ELEMENT_SIZE             UINT8_C(3)
#define SOCKET_FIRST_TLV_ELEMENT_TYPE           UINT8_C(23)
#define SOCKET_SECOND_TLV_ELEMENT_TYPE          UINT8_C(24)

/* Put the function declarations here */

/**
 * @brief  Registers the Socket suite and the respective test cases for this suite
 *
 * @retval Status of the Socket test suite operation, RETCODE_OK on success or some
 * error code otherwise.
 */
Retcode_T SocketTestSuite_Init(void);

#endif /* SocketTestSuite_H */

