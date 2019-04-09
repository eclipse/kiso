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
 * @ingroup BSP_BOARD
 * @{
 *  @file
 *
 *  @brief Interfaces to the System Clock module
 */

#ifndef SYSTEMCLOCK_H_
#define SYSTEMCLOCK_H_

#include "BCDS_BSP_Board.h"

#if BCDS_FEATURE_HAL_TICK_HANDLER

/*
 * @brief Performs operations prior to SysTick count increment.
 * @details This function is initialized during BSP_Board_OSTickInitialize()
 * and makes it possible for the application to perform some operations before
 * the SysTick counter is incremented
 * (e.g. context switching in OS based applications)
 *  * This function is called in SysTick_Handler() function in IrqHandler.c file
 */
extern BSP_Systick_Callback_T BSP_SysTickOsPreProcessing;

/*
 * @brief Performs operations Post to SysTick count increment.
 * @details This function is initialized during BSP_Board_OSTickInitialize()
 * and makes it possible for the application to perform some operations after
 * the SysTick counter has is incremented
 * (e.g. context switching in OS based applications)
 * This function is called in SysTick_Handler() function in IrqHandler.c file
 */
extern BSP_Systick_Callback_T BSP_SysTickOsPostProcessing;

/*
 * @brief System clock configuration
 * @details This function Initializes the system clock settings after a reset or
 * a wake-up from low power mode
 * @return RETCODE_OK in case of success error code otherwise.
 */
Retcode_T SystemClock_Config(void);

/*
 * @brief System clock timer on-time ISR
 */
void SystemClock_ISR(void);

#endif /* BCDS_FEATURE_HAL_TICK_HANDLER */
#endif /* SYSTEMCLOCK_H_ */
/**@}*//* @ingroup BSP_BOARD */
