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
 * @defgroup    BCDS_HAL HAL Types
 * @ingroup     BCDS_ESSENTIALS
 * @{
 *
 * @brief       The Hardware Abstraction Layer Interface
 *
 * @details
 * This file defines several modules that provide interfaces to abstract certain hardware related aspects.
 */

#ifndef BCDS_HAL_H_
#define BCDS_HAL_H_

/* Include all headers which are needed by this file. */
#include "BCDS_Basics.h"
#include "BCDS_Retcode.h"
#include "BCDS_Essentials.h"
#include "BCDS_Assert.h"

#ifndef BCDS_HAL_CONFIG_H_
#include "BCDS_HALConfig.h"
#else
#error "Don't include BCDS_HALConfig.h directly instead of BCDS_HAL.h"
#endif /* BCDS_HAL_CONFIG_H_ */

/**
 * @brief       Declares an enumeration for various possible communication interfaces.
 *
 * @details     A field of this type is e.g. used by the BSP in the handlers that are created for communication devices
 *              to inform the MCU module about the interface type that is configured for a device.
 */
enum BCDS_HAL_InterfaceType_E
{
    BCDS_HAL_INTERFACE_NONE, /**< Undefined / Default / None of the bus communication interface is used */
    BCDS_HAL_INTERFACE_SPI, /**< SPI is used as the communication interface */
    BCDS_HAL_INTERFACE_I2C, /**< I2C is used as the communication interface */
    BCDS_HAL_INTERFACE_UART, /**< UART is used as the communication interface */
};

/**
 * @brief       Declares an enumeration for various possible transfer modes of communication interfaces.
 *
 * @details     A field of this type is e.g. used by the BSP in the handlers that are created for communication devices
 *              to inform the MCU module about the transfer mode that is configured for a device.
 */
enum BCDS_HAL_TransferMode_E
{
    BCDS_HAL_TRANSFER_MODE_POLLING = 1, /**< The transfer function implementation shall rely on polling for state change */
    BCDS_HAL_TRANSFER_MODE_INTERRUPT, /**< The transfer function implementation shall rely on interrupts on state change */
    BCDS_HAL_TRANSFER_MODE_DMA, /**< The transfer function implementation shall rely on DMA and completion interrupts */
};

/**
 * @deprecated The below enums are provided for backward compatibility.
 * @note - Interface users are requested to not use this, since it will be removed going forward.
 */
#define BCDS_HAL_TRANSFER_MODE_BLOCKING (enum BCDS_HAL_TransferMode_E) 1 /* The implementer shall use BCDS_HAL_TRANSFER_MODE_POLLING instead */
#define BCDS_HAL_TRANSFER_MODE_INTERRUPT_RX_DMA_TX (enum BCDS_HAL_TransferMode_E) 4 /* The implementer shall create different RxMode and TxMode in the handler */
#define BCDS_HAL_TRANSFER_MODE_INTERRUPT_TX_DMA_RX (enum BCDS_HAL_TransferMode_E) 5 /* The implementer shall create different RxMode and TxMode in the handler */

/**
 * @brief       Declares an enumeration for various possible  API call modes.
 */
enum BCDS_HAL_CallMode_E
{
    BCDS_HAL_CALL_MODE_BLOCKING = 1, /**< Blocks function return until operation finished */                                 //!< BCDS_HAL_CALL_MODE_BLOCKING
    BCDS_HAL_CALL_MODE_NON_BLOCKING, /**< Returns before operation completed and caller expects a callback upon completion *///!< BCDS_HAL_CALL_MODE_NON_BLOCKING
};

/**
 * @brief       Data type for a general purpose hardware handle.
 */
typedef void * HWHandle_T;

/**
 * @brief       Data type for a general purpose software handle.
 */
typedef void * SWHandle_T;

/**
 * @brief       Device specific handle
 *
 * @details     A call to BSP_<deviceX>_getHandle will return a reference to a structure of this type holding all
 *              necessary parameters to operate all instances of that specific device
 */
struct HAL_DeviceHandle_S
{
    int32_t const DeviceId; /**< An Id given by the BSP to this particular device */
    enum BCDS_HAL_InterfaceType_E const InterfaceType; /**< The type of the communication interface used to communicate to the device */
    HWHandle_T const BusHandle; /**< The Handle of the communication interface e.g. in I2C it would reference a variable of type struct MCU_SPI_Handle_T */
    SWHandle_T const DeviceConfig; /**< An abstract type holding device specific configuration e.g in I2C this would hold the device address */
    SWHandle_T volatile SWAttribute; /**< An OS aware driver would here hold a reference to a struct holding attributes needed to safely operate this particular communication bus e.g locks or synchronizing signals */
    struct HAL_DeviceHandle_S * const NextDevice; /**< Pointer to the reference of the next device of the same type in the board */
};

/**
 * @brief       The data type for the Device specific handle
 */
typedef struct HAL_DeviceHandle_S HAL_DeviceHandle_T;

/**
 * @brief       Return the Status if we run in ISR Context or not
 *
 * @retval      TRUE if we are in Isr Context
 *
 */
bool HAL_IsInISR(void);

#endif /* BCDS_HAL_H_ */
/** @} */
/* End of documentation group BCDS_HAL */

/**
 * @defgroup BCDS_HAL_MCU_IF MCU
 * @brief The MCU abstraction
 *
 * @defgroup BCDS_HAL_BSP_IF BSP
 * @brief The board support package
 *
 */
