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
//lint -e49 error in standard libraries suppressed

/*
 * Redefine Package ID
 */
#include "BCDS_Utils.h"
#undef BCDS_MODULE_ID
#define BCDS_MODULE_ID BCDS_UTILS_MODULE_ID_ERRORLOGGER

#if BCDS_FEATURE_ERRORLOGGER

#ifdef BCDS_PACKAGE_ID
#undef BCDS_PACKAGE_ID
#define BCDS_PACKAGE_ID 0
#endif

/* own header files */
#include "BCDS_ErrorLogger.h"

/* Put constant and variable definitions here */

/** @brief Actual consecutive sequence number
 * @details The sequence number is stored with the error entry in the log.
 * The first error sequence number is 1 and is incremented by 1 with each new
 * entry that is made in the log.
 */
static uint16_t ErrorSeqNo = 0;

/**
 * Defines the next index onto which an error can be written
 */
static uint32_t NextIndexToWriteOn = 0;

/** @brief Buffer into which the error logger data is stored when fetched from user
 * data section
 * @details The error log is organized as a ring buffer with a fixed size and
 * is able to hold a fixed number of error logger entries. When the end of the
 * buffer is reached then writing starts over at the first entry.
 */
static uint8_t DataFromUserPage[ERRORLOGGER_SIZE] = { 0 };

/** Pointer on an array of MAXENTRIES log entries */
static ErrorLogger_LogEntry_T (*pErrorEntries)[MAXENTRIES];

ErrorLoggerConfig_T ErrorLoggerHandle;

/* Put function implementations here */

/* The description of the function is available under function prototypes of this file */
Retcode_T ErrorLogger_Init(ErrorLoggerConfig_T LoggerData)
{
    Retcode_T nvmRetCode = RETCODE_OK;
    ErrorLoggerHandle = LoggerData;

    /* A pointer on an array of log entries */
    pErrorEntries = (ErrorLogger_LogEntry_T (*)[MAXENTRIES]) DataFromUserPage; /* Point on first entry */

    /* Need to read out the entire error log in order to process it */
    nvmRetCode = ErrorLoggerHandle.ReadLogs(ErrorLoggerHandle.StorageMedium, DataFromUserPage, ErrorLoggerHandle.position, ErrorLoggerHandle.length);
    if (RETCODE_OK == nvmRetCode)
    {
        uint16_t highestSeq = 0;

        /* Then loop through the entries and search the entry with containing
         * the highest sequence number to determine the next write index
         */
        for (uint32_t i = 0; i < MAXENTRIES; i++)
        {
            if ((*pErrorEntries)[i].SeqNo >= highestSeq)
            {
                highestSeq = (*pErrorEntries)[i].SeqNo;
            }
        }
        ErrorSeqNo = highestSeq;
        /* Determine the next index to write on. The sequence number is
         * consecutively incremented with each new entry so that the first
         * entry starts with a sequence number of 1.
         */
        NextIndexToWriteOn = ErrorSeqNo % MAXENTRIES;
        return RETCODE_OK;
    }
    else
    {
        return RETCODE(RETCODE_SEVERITY_ERROR, (Retcode_T )RETCODE_FAILURE);
    }
}

/* The description of the function is available under function prototypes of this file */
Retcode_T ErrorLogger_LogError(Retcode_T Error)
{
    Retcode_T nvmRet = RETCODE_OK;

    /* If error code is RETCODE_OK implies no error. So don't log */
    if (RETCODE_OK == Error)
    {
        return RETCODE(RETCODE_SEVERITY_WARNING, (Retcode_T )RETCODE_INVALID_PARAM);
    }
    /* else do nothing */

    ErrorSeqNo++; /* first entry ever has sequence number 1 */
    /* Fill next error entry with data */
    (*pErrorEntries)[NextIndexToWriteOn].TimeStamp = ErrorLoggerHandle.Time_Stamp();
    (*pErrorEntries)[NextIndexToWriteOn].ErrorCode = Error;
    (*pErrorEntries)[NextIndexToWriteOn].SeqNo = ErrorSeqNo;
    (*pErrorEntries)[NextIndexToWriteOn].Reserved = 0x0;

    nvmRet = ErrorLoggerHandle.WriteLogs(ErrorLoggerHandle.StorageMedium, (void *) pErrorEntries,ErrorLoggerHandle.position, ErrorLoggerHandle.length);
    if (RETCODE_OK == nvmRet)
    {
        /* Recalculate write index */
        NextIndexToWriteOn = ErrorSeqNo % MAXENTRIES;
        return RETCODE_OK;
    }
    else
    {
    	/* Userpage write is not success. So error is not updated to Userpage. */

        ErrorSeqNo -= 1;
    }
    return nvmRet;
}

/* The description of the function is available under function prototypes of this file */
Retcode_T ErrorLogger_GetLastErrorLog(ErrorLogger_LogEntry_T *LogEntry)
{
    if (LogEntry)
    {
        /* NextIndexToWriteOn should also be the last error logged */
        if (ErrorSeqNo)
        {
            uint32_t LastIndexWritten;
            if (NextIndexToWriteOn > 0)
            {
                LastIndexWritten = NextIndexToWriteOn - 1;
            }
            else
            {
                LastIndexWritten = (MAXENTRIES - 1);
            }
            *LogEntry = (*pErrorEntries)[LastIndexWritten];
            return RETCODE_OK;
        }
        else
        {
            /*No Error is occured */
            return RETCODE(RETCODE_SEVERITY_INFO, (Retcode_T )RETCODE_OUT_OF_RESOURCES);
        }
    }
    else
    {
        return RETCODE(RETCODE_SEVERITY_INFO, (Retcode_T )RETCODE_INVALID_PARAM);
    }
}

/* The description of the function is available under function prototypes of this file */
Retcode_T ErrorLogger_HasError(Retcode_T Error)
{
    /* Loop through the logged errors and search the error code passed */
    Retcode_T retcode = RETCODE(RETCODE_SEVERITY_INFO, (Retcode_T )RETCODE_FAILURE);
    if (ErrorSeqNo)
    {
        for (uint32_t i = 0; i < MAXENTRIES; i++)
        {
            if ((*pErrorEntries)[i].ErrorCode == Error)
            {
                retcode = RETCODE_OK;
                break; /* LEAVES THE LOOP */
            }
        }
    }
    return retcode;
}

/* The description of the function is available under function prototypes of this file */
uint16_t ErrorLogger_GetTotalErrors(void)
{
    return ErrorSeqNo;
}

uint8_t ErrorLogger_GetCurrentErrors(void)
{
    uint8_t ErrorCount;
    if (ErrorSeqNo >= MAXENTRIES)
    {
        ErrorCount = MAXENTRIES;
    }
    else
    {
        ErrorCount = ErrorSeqNo;
    }
    return ErrorCount;
}

/* The description of the function is available under function prototypes of this file */
Retcode_T ErrorLogger_GetErrorAt(uint8_t index, ErrorLogger_LogEntry_T *LogEntry)
{
    Retcode_T retcode = RETCODE(RETCODE_SEVERITY_INFO, (Retcode_T )RETCODE_INVALID_PARAM);
    if (LogEntry && (index < MAXENTRIES))
    {
        if ((*pErrorEntries)[index].SeqNo)
        {
            *LogEntry = (*pErrorEntries)[index];
            retcode = RETCODE_OK;
        }
        else
        {
            /* Error at that index */
            retcode = RETCODE(RETCODE_SEVERITY_INFO, (Retcode_T )RETCODE_OUT_OF_RESOURCES);
        }
    }
    return retcode;
}

/* The description of the function is available under function prototypes of this file */
Retcode_T ErrorLogger_ClearAllErrorLogs(void)
{
    Retcode_T retcode = RETCODE_OK;
    /* clear log */
    memset(DataFromUserPage, 0, ErrorLoggerHandle.length);
    /* Write entire error cleared log to flash */
    retcode = ErrorLoggerHandle.EraseLogs(ErrorLoggerHandle.StorageMedium, (void *) pErrorEntries, ErrorLoggerHandle.position, ErrorLoggerHandle.length);                                            //write activity here
    if (RETCODE_OK == retcode)
    {
        /* Re-initialize stuff as all errors are cleared now*/
        retcode = ErrorLogger_Init(ErrorLoggerHandle);
    }

    return retcode;
}

#endif /* if BCDS_FEATURE_ERRORLOGGER */
