/****************************************************************************/
/**
 *  Copyright (C) Robert Bosch. All Rights Reserved. Confidential.
 *
 *  Distribution only to people who need to know this information in
 *  order to do their job.(Need-to-know principle).
 *  Distribution to persons outside the company, only if these persons
 *  signed a non-disclosure agreement.
 *  Electronic transmission, e.g. via electronic mail, must be made in
 *  encrypted form.
 *
 *  @file 
 *
 *
 *  Mockup implementation for the BCDS_MCU_SPI_th module.
 *
 * ****************************************************************************/

/* header definition ******************************************************** */
#ifndef BCDS_MCU_SPI_TH_HH_
#define BCDS_MCU_SPI_TH_HH_

/* Include the needed headers */
#include "BCDS_HAL_th.hh"

/* wrap the real interface header */
#include "BCDS_MCU_SPI.h"

/* faked variables needs to be initialized by the test fixture */

/* mock-ups for the provided interfaces */

#if BCDS_FEATURE_SPI

FAKE_VALUE_FUNC(Retcode_T, MCU_SPI_Initialize, SPI_T, MCU_SPI_Callback_T);
FAKE_VALUE_FUNC(Retcode_T, MCU_SPI_Deinitialize, SPI_T);
FAKE_VALUE_FUNC(Retcode_T, MCU_SPI_Send, SPI_T, uint8_t*, uint32_t);
FAKE_VALUE_FUNC(Retcode_T, MCU_SPI_Receive, SPI_T, uint8_t*, uint32_t);
FAKE_VALUE_FUNC(Retcode_T, MCU_SPI_Transfer, SPI_T, uint8_t*, uint8_t*, uint32_t);
FAKE_VALUE_FUNC(uint32_t, MCU_SPI_GetDataCount, SPI_T);

#endif /* BCDS_FEATURE_SPI */
#endif /* BCDS_MCU_SPI_TH_HH_*/

