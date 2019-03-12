/*----------------------------------------------------------------------------*/
/*
 * Copyright (C) Bosch Connected Devices and Solutions GmbH. 
 * All Rights Reserved. Confidential.
 *
 * Distribution only to people who need to know this information in
 * order to do their job.(Need-to-know principle).
 * Distribution to persons outside the company, only if these persons
 * signed a non-disclosure agreement.
 * Electronic transmission, e.g. via electronic mail, must be made in
 * encrypted form.
 */
/*----------------------------------------------------------------------------*/
 
#ifndef BCDS_HAL_DELAY_TH_HH_
#define BCDS_HAL_DELAY_TH_HH_

/* include or ban the real interface header */
#include "BCDS_HAL_Delay.h"

/* Include the needed headers */
#include "gtest.h"

/* Faked variables needs to be initialized by the test fixture */

/* Mock-ups for the provided interfaces */
FAKE_VALUE_FUNC(Retcode_T, HAL_Delay_SetMsHook, HAL_Delay_MsHook_T);
FAKE_VALUE_FUNC(Retcode_T, HAL_Delay_WaitUs, uint32_t);
FAKE_VALUE_FUNC(Retcode_T, HAL_Delay_WaitMs, uint32_t);

#endif /* BCDS_HAL_DELAY_TH_HH_ */
