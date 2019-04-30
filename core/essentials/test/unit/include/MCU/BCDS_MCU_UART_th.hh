/*----------------------------------------------------------------------------*/
/*
 * Copyright (c) 2010-2019 Robert Bosch GmbH
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *    Robert Bosch GmbH - initial contribution
 */
/*----------------------------------------------------------------------------*/

#ifndef BCDS_BCDS_UART_th_HH_
#define BCDS_BCDS_UART_th_HH_

/* Include the needed headers */
#include "BCDS_HAL_th.hh"

/* wrap the real interface header */
#include "BCDS_MCU_UART.h"

/* Faked variables needs to be initialized by the test fixture */

/* Mock-ups for the provided interfaces */
#if BCDS_FEATURE_UART

FAKE_VALUE_FUNC(Retcode_T, MCU_UART_Initialize, UART_T, MCU_UART_Callback_T);
FAKE_VALUE_FUNC(Retcode_T, MCU_UART_Deinitialize, UART_T);
FAKE_VALUE_FUNC(Retcode_T, MCU_UART_Send, UART_T, uint8_t*, uint32_t);
FAKE_VALUE_FUNC(Retcode_T, MCU_UART_Receive, UART_T, uint8_t*, uint32_t);
FAKE_VALUE_FUNC(Retcode_T, MCU_UART_GetRxCount, UART_T, uint32_t*);

#endif /* #if BCDS_FEATURE_UART && UART_COUNT */
#endif /* BCDS_BCDS_UART_th_HH_ */
