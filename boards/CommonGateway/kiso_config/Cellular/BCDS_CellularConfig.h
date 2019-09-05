/*----------------------------------------------------------------------------*/
/*
 * Copyright (C) 2015-2018 Bosch Connected Devices and Solutions GmbH.
 * Copyright (C) 2019 Robert Bosch GmbH.
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

#ifndef BCDS_CELLULARCONFIG_H_
#define BCDS_CELLULARCONFIG_H_

/* *** HARDWARE AND BSP ***************************************************** */
#include "BCDS_BSP_Cellular_SaraR4N4.h"

#define CELLULAR_BSP_CONNECT() BSP_Cellular_SaraR4N4_Connect()
#define CELLULAR_BSP_ENABLE() BSP_Cellular_SaraR4N4_Enable()
#define CELLULAR_BSP_DISABLE() BSP_Cellular_SaraR4N4_Disable()
#define CELLULAR_BSP_DISCONNECT() BSP_Cellular_SaraR4N4_Disconnect()
#define CELLULAR_BSP_GET_UART_HANDLE() BSP_Cellular_SaraR4N4_GetUARTHandle();
#define CELLULAR_BSP_RESET() BSP_Cellular_SaraR4N4_Reset()

#define CELLULAR_RX_BUFFER_SIZE (UINT32_C(1500))      //!<    set the rx receiver buffer size
#define CELLULAR_AT_SEND_BUFFER_SIZE (UINT32_C(1500)) //!<    set the tx transmitter buffer size

/* *** SOCKET SERVICE ******************************************************* */
#define CELLULAR_SOCKET_COUNT (UINT32_C(7)) //!<    max number of data sockets in ublox cellular

/* *** NETWORK ************************************************************** */
#define CELLULAR_COUNTRY_CODE_LENGTH (UINT32_C(3))  //!<    the max length for a contry code
#define CELLULAR_NETWORK_CODE_LENGTH (UINT32_C(3))  //!<    the max length for network code to be reported
#define CELLULAR_LOCATION_CODE_LENGTH (UINT32_C(4)) //!<    the max length for the location identifier
#define CELLULAR_CELL_ID_LENGTH (UINT32_C(4))       //!<    the max length for a cell id reported by the modem

#define CELLULAR_DATACTX_COUNT (UINT32_C(1))           //!<    the number of tx data contexts created by the modem
#define CELLULAR_MNO_PROFILE (AT_UMNOPROF_MNO_DEFAULT) //!< the MNO profile to be used
#define CELLULAR_LTENBIOT_BAND_BITMASK1 (0x80080)      //!< the bitmask according to the LTE Spec to enable disbale specific channels
#define CELLULAR_LTENBIOT_BAND_BITMASK2 (0)            //!< the bitmask according to the LTE Spec to enable disbale specific channels
#define CELLULAR_LTEM1_BAND_BITMASK1 (4)               //!< the bitmask according to the LTE Spec to enable disbale specific channels
#define CELLULAR_LTEM1_BAND_BITMASK2 (0)               //!< the bitmask according to the LTE Spec to enable disbale specific channels

/* *** ENGINE *************************************************************** */
#define CELLULAR_DRV_TASK_PRIORITY (UINT32_C(3))       //!< the command dispatcher's priority
#define CELLULAR_DRV_TASK_STACK_SIZE (UINT32_C(512))   //!< the command dispatcher's stack size
#define CELLULAR_RESP_TASK_PRIORITY (UINT32_C(3))      //!< the response parsers's priority
#define CELLULAR_RESP_TASK_STACK_SIZE (UINT32_C(1024)) //!< the response parsers's stack size

#define CELLULAR_ENABLE_TRACING (0) //!< If enabled, will use the logging feature to print modem responses

#endif /* BCDS_CELLULARCONFIG_H_ */
