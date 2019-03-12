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

#include <gtest.h>

extern "C"
{
#include "BCDS_Utils.h"
#undef BCDS_MODULE_ID
#define BCDS_MODULE_ID BCDS_UTILS_MODULE_ID_EVENTHUB

#if BCDS_FEATURE_EVENTHUB

#include "BCDS_Retcode_th.hh"
#include "BCDS_Assert_th.hh"
#include "fff.h"
#include "Semaphore_th.hh"
#include "ICall_th.hh"

#include "EventHub.c"
}

#if (CONFIG_EVENTHUB_MAX_OBSERVERS <= 0)
#error "CONFIG_EVENTHUB_MAX_OBSERVERS must not be less or equal to 0"
#endif

#define TEST_EVENT  0xAA
#define TEST_DATA   0xBB

bool eventReceived_A;
bool dataCorrect_A;

bool eventReceived_B;
bool dataCorrect_B;

bool eventReceived_All;
bool dataCorrect_All;

void TestObserver_A(TaskEvent_T event, void *data)
{
    eventReceived_A = (TEST_EVENT == event);
    dataCorrect_A = (TEST_DATA == (uint32_t)data);
}

void TestObserver_B(TaskEvent_T event, void *data)
{
    eventReceived_B = (TEST_EVENT == event);
    dataCorrect_B = (TEST_DATA == (uint32_t)data);
}

void TestObserver_All(TaskEvent_T event, void *data)
{
    BCDS_UNUSED(event);
    eventReceived_All = true;
    dataCorrect_All = (TEST_DATA == (uint32_t)data);
}

class eventHub: public testing::Test
{
protected:

    virtual void SetUp()
    {
        RESET_FAKE(Retcode_RaiseError)
        RESET_FAKE(ti_sysbios_knl_Semaphore_create)
        RESET_FAKE(ti_sysbios_knl_Semaphore_pend__E)
        FFF_RESET_HISTORY()
        ;
    }

    /* TearDown() is invoked immediately after a test finishes. */
    virtual void TearDown()
    {
        ; /* nothing to do if clean up is not required */
    }
};

TEST_F(eventHub, EventHub_Initialize_Success)
{
    /** @testcase{ eventHub::EventHub_Initialize_Success: }
     * Test EventHub init success
     */
    Retcode_T rc;
    EventHub_T eventHub;

    ti_sysbios_knl_Semaphore_create_fake.return_val = (Semaphore_Handle)0x01;

    rc = EventHub_Initialize(&eventHub);
    EXPECT_EQ(RETCODE_OK, Retcode_GetCode(rc));
    EXPECT_EQ(0, eventHub.observerCount);
}

TEST_F(eventHub, EventHub_Initialize_Failure)
{
    /** @testcase{ eventHub::EventHub_Initialize_Failure: }
     * Test EventHub init failures
     */
    Retcode_T rc;
    EventHub_T eventHub;

    rc = EventHub_Initialize(&eventHub);
    EXPECT_EQ(RETCODE_SEMAPHORE_ERROR, Retcode_GetCode(rc));

    rc = EventHub_Initialize(NULL);
    EXPECT_EQ(RETCODE_NULL_POINTER, Retcode_GetCode(rc));
}

TEST_F(eventHub, EventHub_Observe_Success)
{
    /** @testcase{ eventHub::EventHub_Observe_Success: }
     * Test EventHub observe success
     */
    Retcode_T rc;
    EventHub_T eventHub;

    ti_sysbios_knl_Semaphore_create_fake.return_val = (Semaphore_Handle)0x01;

    (void)EventHub_Initialize(&eventHub);

    ti_sysbios_knl_Semaphore_pend__E_fake.return_val = TRUE;
    rc = EventHub_Observe(&eventHub, TestObserver_A, (TaskEvent_T) TEST_EVENT);
    EXPECT_EQ(RETCODE_OK, Retcode_GetCode(rc));
    EXPECT_EQ(1, eventHub.observerCount);
}

TEST_F(eventHub, EventHub_Observe_Failure)
{
    /** @testcase{ eventHub::EventHub_Observe_Failure: }
     * Test EventHub observe failures
     */
    Retcode_T rc;
    EventHub_T eventHub;

    ti_sysbios_knl_Semaphore_create_fake.return_val = (Semaphore_Handle)0x01;

    rc = EventHub_Observe(NULL, TestObserver_A, (TaskEvent_T) TEST_EVENT);
    EXPECT_EQ(RETCODE_NULL_POINTER, Retcode_GetCode(rc));

    rc = EventHub_Observe(&eventHub, NULL, (TaskEvent_T) TEST_EVENT);
    EXPECT_EQ(RETCODE_NULL_POINTER, Retcode_GetCode(rc));

    (void)EventHub_Initialize(&eventHub);
    ti_sysbios_knl_Semaphore_pend__E_fake.return_val = (uint32_t)1;
    eventHub.lock = (Semaphore_Handle)0;
    rc = EventHub_Observe(&eventHub, TestObserver_A, (TaskEvent_T) TEST_EVENT);
    EXPECT_EQ(RETCODE_UNINITIALIZED, Retcode_GetCode(rc));

    eventHub.lock = (Semaphore_Handle)1;
    eventHub.observerCount = CONFIG_EVENTHUB_MAX_OBSERVERS;
    rc = EventHub_Observe(&eventHub, TestObserver_A, (TaskEvent_T) TEST_EVENT);
    EXPECT_EQ(RETCODE_OUT_OF_RESOURCES, Retcode_GetCode(rc));

    eventHub.observerCount = 0;
    ti_sysbios_knl_Semaphore_pend__E_fake.return_val = (uint32_t)0;
    rc = EventHub_Observe(&eventHub, TestObserver_A, (TaskEvent_T) TEST_EVENT);
    EXPECT_EQ(RETCODE_SEMAPHORE_ERROR, Retcode_GetCode(rc));

    eventHub.lock = (Semaphore_Handle)1;
    ti_sysbios_knl_Semaphore_pend__E_fake.return_val = FALSE;
    rc = EventHub_Observe(&eventHub, TestObserver_A, (TaskEvent_T) TEST_EVENT);
    EXPECT_EQ(RETCODE_SEMAPHORE_ERROR, Retcode_GetCode(rc));
}

TEST_F(eventHub, EventHub_ObserveAll_Success)
{
    /** @testcase{ eventHub::EventHub_ObserveAll_Success: }
     * Test EventHub observe all events success
     */
    Retcode_T rc;
    EventHub_T eventHub;

    ti_sysbios_knl_Semaphore_create_fake.return_val = (Semaphore_Handle)0x01;;
    (void)EventHub_Initialize(&eventHub);

    ti_sysbios_knl_Semaphore_pend__E_fake.return_val = TRUE;
    rc = EventHub_ObserveAll(&eventHub, TestObserver_A);
    EXPECT_EQ(RETCODE_OK, Retcode_GetCode(rc));
    EXPECT_EQ((uint32_t)1, eventHub.observerCount);
}

TEST_F(eventHub, EventHub_ObserveAll_Failure)
{
    /** @testcase{ eventHub::EventHub_ObserveAll_Failure: }
     * Test EventHub observe all events failures
     */
    Retcode_T rc;
    EventHub_T eventHub;

    rc = EventHub_ObserveAll(NULL, TestObserver_A);
    EXPECT_EQ(RETCODE_NULL_POINTER, Retcode_GetCode(rc));

    rc = EventHub_ObserveAll(&eventHub, NULL);
    EXPECT_EQ(RETCODE_NULL_POINTER, Retcode_GetCode(rc));

    ti_sysbios_knl_Semaphore_create_fake.return_val = (Semaphore_Handle)0x01;;
    (void)EventHub_Initialize(&eventHub);
    ti_sysbios_knl_Semaphore_pend__E_fake.return_val = (uint32_t)1;
    eventHub.lock = (Semaphore_Handle)0;
    rc = EventHub_ObserveAll(&eventHub, TestObserver_A);
    EXPECT_EQ(RETCODE_UNINITIALIZED, Retcode_GetCode(rc));

    eventHub.lock = (Semaphore_Handle)1;
    eventHub.observerCount = CONFIG_EVENTHUB_MAX_OBSERVERS;
    rc = EventHub_ObserveAll(&eventHub, TestObserver_A);
    EXPECT_EQ(RETCODE_OUT_OF_RESOURCES, Retcode_GetCode(rc));

    eventHub.observerCount = 0;
    ti_sysbios_knl_Semaphore_pend__E_fake.return_val = FALSE;
    rc = EventHub_ObserveAll(&eventHub, TestObserver_A);
    EXPECT_EQ(RETCODE_SEMAPHORE_ERROR, Retcode_GetCode(rc));

}

TEST_F(eventHub, EventHub_Notify_Success)
{
    /** @testcase{ eventHub::EventHub_Notify_Success: }
     * Test EventHub notify success
     */
    EventHub_T eventHub;
    Retcode_T rc;
    uint32_t expectedObservers = 0;

    eventReceived_A = false;
    dataCorrect_A = false;
    eventReceived_B = false;
    dataCorrect_B = false;
    eventReceived_All = false;
    dataCorrect_All = false;
    ti_sysbios_knl_Semaphore_create_fake.return_val = (Semaphore_Handle)0x01;;
    ti_sysbios_knl_Semaphore_pend__E_fake.return_val = (uint32_t)1;
    (void)EventHub_Initialize(&eventHub);
    (void)EventHub_Observe(&eventHub, TestObserver_A, (TaskEvent_T) TEST_EVENT);
    expectedObservers++;
    /* depending on the config, we might not have enough slots for another observe */
#if (CONFIG_EVENTHUB_MAX_OBSERVERS >= 2)
    (void)EventHub_Observe(&eventHub, TestObserver_B, (TaskEvent_T) TEST_EVENT);
    expectedObservers++;
#endif
#if (CONFIG_EVENTHUB_MAX_OBSERVERS >= 3)
    (void)EventHub_ObserveAll(&eventHub, TestObserver_All);
    expectedObservers++;
#endif
    rc = EventHub_Notify(&eventHub, (TaskEvent_T) TEST_EVENT, (void*) TEST_DATA);
    EXPECT_EQ(RETCODE_OK, Retcode_GetCode(rc));
    EXPECT_EQ(expectedObservers, eventHub.observerCount);
    EXPECT_EQ(true, eventReceived_A);
    EXPECT_EQ(true, dataCorrect_A);
#if (CONFIG_EVENTHUB_MAX_OBSERVERS >= 2)
    EXPECT_EQ(true, eventReceived_B);
    EXPECT_EQ(true, dataCorrect_B);
#endif
#if (CONFIG_EVENTHUB_MAX_OBSERVERS >= 3)
    EXPECT_EQ(true, eventReceived_All);
    EXPECT_EQ(true, dataCorrect_All);
#endif
}

TEST_F(eventHub, EventHub_Notify_Failure)
{
    /** @testcase{ eventHub::EventHub_Notify_Failure: }
     * Test EventHub notify failures
     */
    EventHub_T eventHub;
    Retcode_T rc;

    eventReceived_A = false;
    ti_sysbios_knl_Semaphore_create_fake.return_val = (Semaphore_Handle)0x01;;
    ti_sysbios_knl_Semaphore_pend__E_fake.return_val = (uint32_t)1;
    (void)EventHub_Initialize(&eventHub);
    (void)EventHub_Observe(&eventHub, TestObserver_A, (TaskEvent_T) TEST_EVENT);
    rc = EventHub_Notify(NULL, (TaskEvent_T) TEST_EVENT, NULL);
    EXPECT_EQ(RETCODE_NULL_POINTER, Retcode_GetCode(rc));

    eventHub.lock = (Semaphore_Handle)0;
    rc = EventHub_Notify(&eventHub, (TaskEvent_T) TEST_EVENT, NULL);
    EXPECT_EQ(RETCODE_UNINITIALIZED, Retcode_GetCode(rc));

    eventHub.lock = (Semaphore_Handle)1;
    ti_sysbios_knl_Semaphore_pend__E_fake.return_val = FALSE;
    rc = EventHub_Notify(&eventHub, (TaskEvent_T) TEST_EVENT, NULL);
    EXPECT_EQ(RETCODE_SEMAPHORE_ERROR, Retcode_GetCode(rc));
    EXPECT_NE(true, eventReceived_A);

}
#else
}
#endif /* if BCDS_FEATURE_EVENTHUB */
