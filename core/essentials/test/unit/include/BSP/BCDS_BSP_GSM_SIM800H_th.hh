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

#ifndef BCDS_BCDS_BSP_GSM_SIM800H_th_HH
#define BCDS_BCDS_BSP_GSM_SIM800H_th_HH

/* Include the needed headers */
#include "BCDS_HAL_th.hh"

/* wrap the real interface header */
#include "BCDS_BSP_GSM_SIM800H.h"

/* Faked variables needs to be initialized by the test fixture */

/* Mock-ups for the provided interfaces */

#if BCDS_FEATURE_BSP_GSM_SIM800H

FAKE_VALUE_FUNC(Retcode_T, BSP_GSM_SIM800H_Connect);
FAKE_VALUE_FUNC(Retcode_T, BSP_GSM_SIM800H_Enable);
FAKE_VALUE_FUNC(Retcode_T, BSP_GSM_SIM800H_Disable);
FAKE_VALUE_FUNC(Retcode_T, BSP_GSM_SIM800H_Disconnect);
FAKE_VALUE_FUNC(Retcode_T, BSP_GSM_SIM800H_Restart);
FAKE_VALUE_FUNC(Retcode_T, BSP_GSM_SIM800H_Reset);
FAKE_VALUE_FUNC(Retcode_T, BSP_GSM_SIM800H_Wakeup);
FAKE_VALUE_FUNC(Retcode_T, BSP_GSM_SIM800H_Sleep);
FAKE_VALUE_FUNC(HWHandle_T, BSP_GSM_SIM800H_GetUARTHandle);

#endif /* BCDS_FEATURE_BSP_GSM_SIM800H */
#endif /* BCDS_BCDS_BSP_GSM_SIM800H_th_HH */
