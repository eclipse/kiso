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
 *
 * @brief Implements log generic filter.
 *
 */

#include "BCDS_Utils.h"
#undef BCDS_MODULE_ID
#define BCDS_MODULE_ID  BCDS_UTILS_MODULE_ID_LOGGING_FILTER

#if BCDS_FEATURE_LOGGING

#include "BCDS_Logging.h"
#include "LogConfig.h"

#include "BCDS_Basics.h"
#include "BCDS_Retcode.h"

#define LOG_PACKAGE_ID_ALL      (0)
#define LOG_MODULE_ID_ALL       (0)
#define LOG_FILTER_ID_INVALID   (LOG_FILTER_ITEM_COUNT)

/**
 * @brief Log filter item.
 */
typedef struct
{
    uint8_t Level;
    uint8_t Package;
    uint8_t Module;
}__attribute__((packed)) LogFilterItem_T;

static LogFilterItem_T LogFilterItems[LOG_FILTER_ITEM_COUNT] =
{
    {
        .Level = (uint8_t) LOG_LEVEL_PACKAGE_DEFAULT,
        .Package = LOG_PACKAGE_ID_ALL,
        .Module = LOG_MODULE_ID_ALL
    }
};

LogFilterId_T LogFilter_Add(LogLevel_T level, uint8_t package, uint8_t module)
{
    uint32_t i;

    for (i = 0; i < LOG_FILTER_ID_INVALID; ++i)
    {
        if ((uint8_t) LOG_LEVEL_NONE == LogFilterItems[i].Level)
        {
            LogFilterItems[i].Level = (uint8_t) level;
            LogFilterItems[i].Package = package;
            LogFilterItems[i].Module = module;
            break;
        }
    }

    return i;
}

Retcode_T LogFilter_Delete(LogFilterId_T id)
{
    if (id >= LOG_FILTER_ITEM_COUNT)
    {
        return RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_INVALID_PARAM);
    }

    LogFilterItems[id].Level = (uint8_t) LOG_LEVEL_NONE;
    return RETCODE_OK;
}

Retcode_T LogFilter_Configure(LogFilterId_T id, LogLevel_T level, uint8_t package, uint8_t module)
{
    if (id >= LOG_FILTER_ITEM_COUNT)
    {
        return RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_INVALID_PARAM);
    }

    LogFilterItems[id].Level = (uint8_t) level;
    LogFilterItems[id].Package = package;
    LogFilterItems[id].Module = module;

    return RETCODE_OK;
}

bool LogFilter_Apply(LogLevel_T level, uint8_t package, uint8_t module)
{
    bool enabled = true;

    for (uint32_t i = 0; i < LOG_FILTER_ITEM_COUNT; ++i)
    {
        if ((uint8_t) LOG_LEVEL_NONE != LogFilterItems[i].Level)
        {
            enabled = false;
            if ((uint8_t) level <= LogFilterItems[i].Level
                    && ((uint8_t) LOG_PACKAGE_ID_ALL == LogFilterItems[i].Package || package == LogFilterItems[i].Package)
                    && ((uint8_t) LOG_MODULE_ID_ALL == LogFilterItems[i].Module || module == LogFilterItems[i].Module))
            {
                return true;
            }
        }
    }

    return enabled;
}

#endif /* if BCDS_FEATURE_LOGGING */
