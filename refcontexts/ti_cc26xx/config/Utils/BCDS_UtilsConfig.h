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
 * @brief Utils config header.
 *
 * @details Provides configuration interface for the Utils components.
 */

#ifndef BCDS_UTILSCONFIG_H_
#define BCDS_UTILSCONFIG_H_

#ifndef BCDS_FEATURE_CMDLINEDEBUGGER
/** @brief Enable (1) or disable (0) the CmdLineDebugger feature. */
#define BCDS_FEATURE_CMDLINEDEBUGGER    1
#endif

#ifndef BCDS_FEATURE_CMDPROCESSOR
/** @brief Enable (1) or disable (0) the CmdProcessor feature. */
#define BCDS_FEATURE_CMDPROCESSOR       1
#endif

#ifndef BCDS_FEATURE_CRC
/** @brief Enable (1) or disable (0) the Crc feature. */
#define BCDS_FEATURE_CRC                1
#endif

#ifndef BCDS_FEATURE_EVENTHUB
/** @brief Enable (1) or disable (0) the EventHub feature. */
#define BCDS_FEATURE_EVENTHUB           1
#endif

#ifndef BCDS_FEATURE_GUARDEDTASK
/** @brief Enable (1) or disable (0) the GuardedTask feature. */
#define BCDS_FEATURE_GUARDEDTASK        1
#endif

#ifndef BCDS_FEATURE_LEANB2CAP
/** @brief Enable (1) or disable (0) the LeanB2Cap feature. */
#define BCDS_FEATURE_LEANB2CAP          1
#endif

#ifndef BCDS_FEATURE_ERRORLOGGER
/** @brief Enable (1) or disable (0) the ErrorLogger feature. */
#define BCDS_FEATURE_ERRORLOGGER        1
#endif

#ifndef BCDS_FEATURE_LOGGING
/** @brief Enable (1) or disable (0) the Logging feature. */
#define BCDS_FEATURE_LOGGING            1
#endif

#ifndef BCDS_FEATURE_QUEUE
/** @brief Enable (1) or disable (0) the Queue feature. */
#define BCDS_FEATURE_QUEUE              1
#endif

#ifndef BCDS_FEATURE_RINGBUFFER
/** @brief Enable (1) or disable (0) the RingBuffer feature. */
#define BCDS_FEATURE_RINGBUFFER         1
#endif

#ifndef BCDS_FEATURE_SLEEPCONTROL
/** @brief Enable (1) or disable (0) the SleepControl feature. */
#define BCDS_FEATURE_SLEEPCONTROL       1
#endif

#ifndef BCDS_FEATURE_TASKMONITOR
/** @brief Enable (1) or disable (0) the TaskMonitor feature. */
#define BCDS_FEATURE_TASKMONITOR        1
#endif

#ifdef BCDS_FEATURE_TASKMONITOR
/**
 * @brief BCDS_TASKMONITOR_MAX_TASKS
 * Maximum number of TaskMonitor tickets to reserve for the system.
 */
#define BCDS_TASKMONITOR_MAX_TASKS      10
#endif /* ifdef BCDS_FEATURE_TASKMONITOR */

#ifndef BCDS_FEATURE_TLV
/** @brief Enable (1) or disable (0) the Tlv feature. */
#define BCDS_FEATURE_TLV                1
#endif

#ifndef BCDS_FEATURE_UARTTRANSCEIVER
/** @brief Enable (1) or disable (0) the UartTransceiver feature. */
#define BCDS_FEATURE_UARTTRANSCEIVER    1
#endif

#ifndef BCDS_FEATURE_XPROTOCOL
/** @brief Enable (1) or disable (0) the XProtocol feature. */
#define BCDS_FEATURE_XPROTOCOL          1
#endif

#endif /* BCDS_UTILSCONFIG_H_ */
