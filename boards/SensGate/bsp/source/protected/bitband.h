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
 * @file
 * @defgroup
 * @ingroup
 * @{
 *
 * @brief Provides bit-banding macros for targeted resources.
 *
 * @details 
 */
#ifndef PROTECTED_BITBAND_H_
#define PROTECTED_BITBAND_H_

#include "stm32l486xx.h"

#define BITBAND_SRAM1(reg,bit)              ((SRAM1_BB_BASE + (reg - SRAM1_BASE) * 32 + (bit * 4))) // Convert SRAM1 address
#define BITBAND_SRAM2(reg,bit)              ((SRAM2_BB_BASE + (reg - SRAM2_BASE) * 32 + (bit * 4))) // Convert SRAM2 address
#define BITBAND_PERI(reg,bit)               ((PERIPH_BB_BASE + (reg - PERIPH_BASE) * 32 + (bit * 4))) // Convert PERIPHERAL address

#define BITBAND_RCC_AHB2ENR_OFFSET          (RCC_BASE + 0x4C)
#define BITBAND_RCC_AHB2ENR_GPIOA_POS       0
#define BITBAND_RCC_AHB2ENR_GPIOB_POS       1
#define BITBAND_RCC_AHB2ENR_GPIOC_POS       2
#define BITBAND_RCC_AHB2ENR_GPIOD_POS       3
#define BITBAND_RCC_AHB2ENR_GPIOE_POS       4

#define BITBAND_GPIOAEN_BIT                 *((uint32_t*)BITBAND_PERI(BITBAND_RCC_AHB2ENR_OFFSET,BITBAND_RCC_AHB2ENR_GPIOA_POS))
#define BITBAND_GPIOBEN_BIT                 *((uint32_t*)BITBAND_PERI(BITBAND_RCC_AHB2ENR_OFFSET,BITBAND_RCC_AHB2ENR_GPIOB_POS))
#define BITBAND_GPIOCEN_BIT                 *((uint32_t*)BITBAND_PERI(BITBAND_RCC_AHB2ENR_OFFSET,BITBAND_RCC_AHB2ENR_GPIOC_POS))
#define BITBAND_GPIODEN_BIT                 *((uint32_t*)BITBAND_PERI(BITBAND_RCC_AHB2ENR_OFFSET,BITBAND_RCC_AHB2ENR_GPIOD_POS))
#define BITBAND_GPIOEEN_BIT                 *((uint32_t*)BITBAND_PERI(BITBAND_RCC_AHB2ENR_OFFSET,BITBAND_RCC_AHB2ENR_GPIOE_POS))

#define BITBAND_LPTIM1_ISR_OFFSET           (LPTIM1_BASE + 0x00)
#define BITBAND_LPTIM1_ISR_CMPM_POS         0
#define BITBAND_LPTIM1_ISR_ARRM_POS         1
#define BITBAND_LPTIM1_ISR_EXTTRIG_POS      2
#define BITBAND_LPTIM1_ISR_CMPOK_POS        3
#define BITBAND_LPTIM1_ISR_ARROK_POS        4
#define BITBAND_LPTIM1_ISR_UP_POS           5
#define BITBAND_LPTIM1_ISR_DOWN_POS         6

#define BITBAND_LPTIM1_ISR_CMPM_BIT         *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_ISR_OFFSET,BITBAND_LPTIM1_ISR_CMPM_POS))
#define BITBAND_LPTIM1_ISR_ARRM_BIT         *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_ISR_OFFSET,BITBAND_LPTIM1_ISR_ARRM_POS))
#define BITBAND_LPTIM1_ISR_EXTTRIG_BIT      *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_ISR_OFFSET,BITBAND_LPTIM1_ISR_EXTTRIG_POS))
#define BITBAND_LPTIM1_ISR_CMPOK_BIT        *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_ISR_OFFSET,BITBAND_LPTIM1_ISR_CMPOK_POS))
#define BITBAND_LPTIM1_ISR_ARROK_BIT        *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_ISR_OFFSET,BITBAND_LPTIM1_ISR_ARROK_POS))
#define BITBAND_LPTIM1_ISR_UP_BIT           *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_ISR_OFFSET,BITBAND_LPTIM1_ISR_UP_POS))
#define BITBAND_LPTIM1_ISR_DOWN_BIT         *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_ISR_OFFSET,BITBAND_LPTIM1_ISR_DOWN_POS))

#define BITBAND_LPTIM1_ICR_OFFSET           (LPTIM1_BASE + 0x04)
#define BITBAND_LPTIM1_ICR_CMPM_POS         0
#define BITBAND_LPTIM1_ICR_ARRM_POS         1
#define BITBAND_LPTIM1_ICR_EXTTRIG_POS      2
#define BITBAND_LPTIM1_ICR_CMPOK_POS        3
#define BITBAND_LPTIM1_ICR_ARROK_POS        4
#define BITBAND_LPTIM1_ICR_UP_POS           5
#define BITBAND_LPTIM1_ICR_DOWN_POS         6

#define BITBAND_LPTIM1_ICR_CMPM_BIT         *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_ICR_OFFSET,BITBAND_LPTIM1_ICR_CMPM_POS))
#define BITBAND_LPTIM1_ICR_ARRM_BIT         *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_ICR_OFFSET,BITBAND_LPTIM1_ICR_ARRM_POS))
#define BITBAND_LPTIM1_ICR_EXTTRIG_BIT      *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_ICR_OFFSET,BITBAND_LPTIM1_ICR_EXTTRIG_POS))
#define BITBAND_LPTIM1_ICR_CMPOK_BIT        *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_ICR_OFFSET,BITBAND_LPTIM1_ICR_CMPOK_POS))
#define BITBAND_LPTIM1_ICR_ARROK_BIT        *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_ICR_OFFSET,BITBAND_LPTIM1_ICR_ARROK_POS))
#define BITBAND_LPTIM1_ICR_UP_BIT           *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_ICR_OFFSET,BITBAND_LPTIM1_ICR_UP_POS))
#define BITBAND_LPTIM1_ICR_DOWN_BIT         *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_ICR_OFFSET,BITBAND_LPTIM1_ICR_DOWN_POS))

#define BITBAND_LPTIM1_IER_OFFSET           (LPTIM1_BASE + 0x04)
#define BITBAND_LPTIM1_IER_CMPM_POS         0
#define BITBAND_LPTIM1_IER_ARRM_POS         1
#define BITBAND_LPTIM1_IER_EXTTRIG_POS      2
#define BITBAND_LPTIM1_IER_CMPOK_POS        3
#define BITBAND_LPTIM1_IER_ARROK_POS        4
#define BITBAND_LPTIM1_IER_UP_POS           5
#define BITBAND_LPTIM1_IER_DOWN_POS         6

#define BITBAND_LPTIM1_IER_CMPM_BIT         *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_IER_OFFSET,BITBAND_LPTIM1_IER_CMPM_POS))
#define BITBAND_LPTIM1_IER_ARRM_BIT         *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_IER_OFFSET,BITBAND_LPTIM1_IER_ARRM_POS))
#define BITBAND_LPTIM1_IER_EXTTRIG_BIT      *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_IER_OFFSET,BITBAND_LPTIM1_IER_EXTTRIG_POS))
#define BITBAND_LPTIM1_IER_CMPOK_BIT        *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_IER_OFFSET,BITBAND_LPTIM1_IER_CMPOK_POS))
#define BITBAND_LPTIM1_IER_ARROK_BIT        *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_IER_OFFSET,BITBAND_LPTIM1_IER_ARROK_POS))
#define BITBAND_LPTIM1_IER_UP_BIT           *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_IER_OFFSET,BITBAND_LPTIM1_IER_UP_POS))
#define BITBAND_LPTIM1_IER_DOWN_BIT         *((uint32_t*)BITBAND_PERI(BITBAND_LPTIM1_IER_OFFSET,BITBAND_LPTIM1_IER_DOWN_POS))

#endif /* BSP_BITBAND_H_ */
