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

/**
 * @file 
 * @brief Add a brief description here.
 *
 * @details Put here the documentation of this header file. Explain the interface exposed
 * by this header, e.g. what is the purpose of use, how to use it, etc.
 */

#ifndef PWM_BUZZER_H_
#define PWM_BUZZER_H_

#include "BCDS_BSP_PWM_Buzzer.h"

#if BCDS_FEATURE_BSP_PWM_BUZZER

/* Include all headers which are needed by this file. */

/**
 * @brief Gets status of the module
 */
enum BSP_ModuleState_E PWM_Buzzer_getState(void);

/* Put the type and macro definitions here */

/* Put the function declarations here */

#endif /* BCDS_FEATURE_BSP_PWM_BUZZER */

#endif /* PWM_BUZZER_H_ */

