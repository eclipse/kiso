/*----------------------------------------------------------------------------*/
/*
 *  Copyright (C) Bosch Connected Devices and Solutions.
 *  All Rights Reserved. Confidential.
 *
 *  Distribution only to people who need to know this information in
 *  order to do their job.(Need-to-know principle).
 *  Distribution to persons outside the company, only if these persons
 *  signed a non-disclosure agreement.
 *  Electronic transmission, e.g. via electronic mail, must be made in
 *  encrypted form.
 */
/*----------------------------------------------------------------------------*/

/**
 * @file
 * 
 * @brief Module test specification for the Retcode_unittest module.
 *
 **/

/* include gtest interface */
#include <gtest.h>

FFF_DEFINITION_BLOCK_START /* start of global scope symbol and fake definitions section */

/* Setup compile time configuration defines */
extern "C"
{

#undef BCDS_MODULE_ID
#define BCDS_MODULE_ID BCDS_ESSENTIALS_MODULE_ID_RETCODE

/* Include faked interfaces */
#include "BCDS_Assert_th.hh"

FFF_DEFINITION_BLOCK_END /* end of global scope symbol and fake definitions section */

/* Include Module under Test */
#include "Retcode.c"
}

static uint32_t numErrors;
static Retcode_T lastError;
static bool isFromInterrupt;

class Retcode: public testing::Test
{
protected:
    virtual void SetUp()
    {
        FFF_RESET_HISTORY()
        numErrors = 0;
        lastError = 0;
        isFromInterrupt = false;
        IsRetcodeModuleInitialized = false;

    }

    virtual void TearDown()
    {
        ; /* nothing to do if clean up is not required */
    }
};

/* specify test cases ******************************************************* */

static void myErrorHandlingFunc(Retcode_T error, bool isFromIsr)
{
	numErrors++;
	lastError = error;
	isFromInterrupt = isFromIsr;
}


TEST_F(Retcode, initializeToDefaultFunc)
{

	numErrors = 0;
	lastError = 0;

	EXPECT_EQ(RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_NULL_POINTER), Retcode_Initialize(NULL));
}


TEST_F(Retcode, initialize)
{

	numErrors = 0;
	lastError = 0;

	EXPECT_EQ(RETCODE_OK, Retcode_Initialize(&myErrorHandlingFunc));

	EXPECT_EQ(&myErrorHandlingFunc, errorHandlingFunc);
}

TEST_F(Retcode, initializeMutipleTimes)
{

    numErrors = 0;
    lastError = 0;
    IsRetcodeModuleInitialized = true;

    EXPECT_EQ(RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_INCONSITENT_STATE), Retcode_Initialize(&myErrorHandlingFunc));
}

TEST_F(Retcode, raise)
{

	Retcode_T retcode = RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_RTOS_QUEUE_ERROR);

	Retcode_RaiseError(retcode);

	EXPECT_EQ(retcode, lastError);
	EXPECT_EQ(RETCODE_RTOS_QUEUE_ERROR, Retcode_GetCode(retcode));
	EXPECT_EQ(RETCODE_SEVERITY_ERROR, Retcode_GetSeverity(retcode));
	EXPECT_EQ((uint32_t)BCDS_PACKAGE_ID, Retcode_GetPackage(retcode));
	EXPECT_EQ(BCDS_ESSENTIALS_MODULE_ID_RETCODE, Retcode_GetModuleId(retcode));
	EXPECT_EQ((uint32_t)1, numErrors);
	EXPECT_NE(true, isFromInterrupt);

	retcode = RETCODE(RETCODE_SEVERITY_WARNING, RETCODE_INVALID_PARAM);

	Retcode_RaiseError(retcode);

	EXPECT_EQ(retcode, lastError);
	EXPECT_EQ(RETCODE_INVALID_PARAM, Retcode_GetCode(retcode));
	EXPECT_EQ(RETCODE_SEVERITY_WARNING, Retcode_GetSeverity(retcode));
	EXPECT_EQ((uint32_t)BCDS_PACKAGE_ID, Retcode_GetPackage(retcode));
	EXPECT_EQ(BCDS_ESSENTIALS_MODULE_ID_RETCODE, Retcode_GetModuleId(retcode));
	EXPECT_EQ((uint32_t)2, numErrors);
	EXPECT_NE(true, isFromInterrupt);
}


TEST_F(Retcode, retcodeOKPackageAndSeverityDropped1)
{
	Retcode_T retcode = RETCODE(RETCODE_SEVERITY_FATAL, RETCODE_SUCCESS);

	EXPECT_EQ(RETCODE(RETCODE_SEVERITY_FATAL, RETCODE_SUCCESS), retcode);

	EXPECT_EQ((uint32_t)BCDS_PACKAGE_ID, Retcode_GetPackage(retcode));
	EXPECT_EQ(RETCODE_SEVERITY_FATAL, Retcode_GetSeverity(retcode));
	EXPECT_EQ(RETCODE_SUCCESS, Retcode_GetCode(retcode));
}


TEST_F(Retcode, retcodeSeverity)
{
	Retcode_T retcode = RETCODE(RETCODE_SEVERITY_NONE, RETCODE_FAILURE);
	EXPECT_EQ(RETCODE_SEVERITY_NONE, Retcode_GetSeverity(retcode));

	retcode = RETCODE(RETCODE_SEVERITY_INFO, RETCODE_FAILURE);
	EXPECT_EQ(RETCODE_SEVERITY_INFO, Retcode_GetSeverity(retcode));

	retcode = RETCODE(RETCODE_SEVERITY_WARNING, RETCODE_FAILURE);
	EXPECT_EQ(RETCODE_SEVERITY_WARNING, Retcode_GetSeverity(retcode));

	retcode = RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_FAILURE);
	EXPECT_EQ(RETCODE_SEVERITY_ERROR, Retcode_GetSeverity(retcode));

	retcode = RETCODE(RETCODE_SEVERITY_WARNING, RETCODE_FAILURE);
	EXPECT_EQ(RETCODE_SEVERITY_WARNING, Retcode_GetSeverity(retcode));
}



TEST_F(Retcode, retcodeOKPackageAndSeverityDropped2)
{

	Retcode_T retcode = RETCODE(RETCODE_SEVERITY_FATAL, RETCODE_SUCCESS);

	EXPECT_NE(RETCODE_SUCCESS, retcode);


	EXPECT_EQ((uint32_t)BCDS_PACKAGE_ID, Retcode_GetPackage(retcode));
	EXPECT_EQ(RETCODE_SEVERITY_FATAL, Retcode_GetSeverity(retcode));
	EXPECT_EQ(RETCODE_SUCCESS, Retcode_GetCode(retcode));
}




TEST_F(Retcode, retcodeMacro)
{
	Retcode_T retcode = RETCODE(RETCODE_SEVERITY_NONE,RETCODE_FAILURE);

	EXPECT_NE((Retcode_T)0, retcode);
	EXPECT_NE(RETCODE_OK, retcode);

	EXPECT_EQ((uint32_t)BCDS_PACKAGE_ID, Retcode_GetPackage(retcode));
	EXPECT_EQ(0, Retcode_GetSeverity(retcode));
	EXPECT_EQ(RETCODE_FAILURE, Retcode_GetCode(retcode));
}



TEST_F(Retcode, composeMacro)
{
	Retcode_T retcode = RETCODE(RETCODE_SEVERITY_FATAL, RETCODE_FAILURE);

	EXPECT_NE((Retcode_T)0, retcode);
	EXPECT_NE(RETCODE_SUCCESS, retcode);

	EXPECT_EQ((uint32_t)BCDS_PACKAGE_ID, Retcode_GetPackage(retcode));
	EXPECT_EQ(RETCODE_SEVERITY_FATAL, Retcode_GetSeverity(retcode));
	EXPECT_EQ(RETCODE_FAILURE, Retcode_GetCode(retcode));
}

TEST_F(Retcode, RetcodeRaiseFromIsr)
{
    Retcode_T retcode = RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_UNEXPECTED_BEHAVIOR);

    Retcode_RaiseErrorFromIsr(retcode);

    EXPECT_EQ(retcode, lastError);
    EXPECT_EQ(RETCODE_UNEXPECTED_BEHAVIOR, Retcode_GetCode(retcode));
    EXPECT_EQ(RETCODE_SEVERITY_ERROR, Retcode_GetSeverity(retcode));
    EXPECT_EQ((uint32_t)BCDS_PACKAGE_ID, Retcode_GetPackage(retcode));
    EXPECT_EQ(BCDS_ESSENTIALS_MODULE_ID_RETCODE, Retcode_GetModuleId(retcode));
    EXPECT_EQ((uint32_t)1, numErrors);
    EXPECT_EQ(true, isFromInterrupt);
}



/*****************************************************************************************/
