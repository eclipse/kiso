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
 
#ifndef BCDS_BCDS_BSP_Mic_MAX4466_th_HH
#define BCDS_BCDS_BSP_Mic_MAX4466_th_HH

/* Include the needed headers */
#include "BCDS_HAL_th.hh"

/* wrap the real interface header */
#include "BCDS_BSP_Mic_MAX4466.h"

/* Faked variables needs to be initialized by the test fixture */

/* Mock-ups for the provided interfaces */

#if BCDS_FEATURE_BSP_MIC_MAX4466

FAKE_VALUE_FUNC(Retcode_T, BSP_Mic_MAX4466_Connect);
FAKE_VALUE_FUNC(Retcode_T, BSP_Mic_MAX4466_Enable);
FAKE_VALUE_FUNC(Retcode_T, BSP_Mic_MAX4466_Disable);
FAKE_VALUE_FUNC(Retcode_T, BSP_Mic_MAX4466_Disconnect);

#endif /* BCDS_FEATURE_BSP_MIC_MAX4466 */

#endif /* BCDS_BCDS_BSP_Mic_MAX4466_th_HH */
