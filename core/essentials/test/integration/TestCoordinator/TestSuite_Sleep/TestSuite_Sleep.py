import abstract_test_suite
import abstract_test_case
from CChannel import Message
from Configuration import *
from TestSuite_Sleep.test_duration import test_durations

class TestSuite_Sleep(abstract_test_suite.AbstractTestSuite):

    def setUp(self):
        # adding the test cases
        test_duration = test_durations.get_next_test_duration()
        tlvs = [(TLV_TYPE_TEST_DURATION, str(test_duration))]

        generic_test_case_dict = {'test_case_name': 'TestCase_SleepToEM3', 'test_case_id': 1,
                                  'timeouts': [TIMEOUT, TIMEOUT, 5*test_duration, TIMEOUT], 'tlvs': [None, tlvs, None]}

        self.add_generic_test_case(**generic_test_case_dict)

        generic_test_case_dict = {'test_case_name': 'TestCase_SleepToEm2', 'test_case_id': 2,
                                  'timeouts': [TIMEOUT, TIMEOUT, 5 * test_duration, TIMEOUT],
                                  'tlvs': [None, tlvs, None]}

        self.add_generic_test_case(**generic_test_case_dict)

        # you can use the same dict to add other test case by changing the field that you want as follow:
        # generic_test_case_dict['test_case_name'] = 'Test case b'
        # generic_test_case_dict['test_case_id'] = 2
        # generic_test_case_dict['some field'] = xxx
        # ...
        # self.add_generic_test_case(**generic_test_case_dict)
        #
        # You can also not use a dictionnary and pass the argument directly to the method as follow:
        # self.add_generic_test_case('Test Case a', 1, [TIMEOUT, TIMEOUT, 5*test_duration, TIMEOUT], [None, tlvs, None],
        #                            ['Test Participant A', 'Test Participant B'])

        # self.add_test_case(TestCase_1_b)
        # self.add_test_case(TestCase_1_c)

        # sending setup command to the test participants
        self.generic_setUp()

    def tearDown(self):
        self.generic_tearDown()


class TestCase_SleepToEM3(abstract_test_case.AbstractTestCase):
    test_case_id = 1

    def setUp(self):
        print("==============================")
        print("SetUp: TestCase EM3 Sleep")
        print("==============================")
        ack = self.send_setup_command(EMBEDDED_TEST_PARTICIPANT, TIMEOUT)
        self.assertEqual(Message.NO_ERROR, ack.getErrorCode(), "")

    def runTest(self):
        print("==============================")
        print("Run: TestCase EM3 Sleep")
        print("==============================")

        test_duration = test_durations.get_next_test_duration()
        tlvs = [(TLV_TYPE_TEST_DURATION, str(test_duration))]
        ack = self.send_run_command(EMBEDDED_TEST_PARTICIPANT, TIMEOUT, tlvs)
        self.assertEqual(Message.NO_ERROR, ack.getErrorCode(), "")

        result = self.wait_for_reports([EMBEDDED_TEST_PARTICIPANT], 5 * test_duration)

        report1 = self.get_last_report(EMBEDDED_TEST_PARTICIPANT)

        self.assertEqual(True, result, "the waitForReports has timed out...\n"
                         + "max time duration: " + str(test_duration)
                         + "\ntime duration 1:   " + str(test_duration) + str(report1)
                         + "\ntime duration 2:   " + str(test_duration) + str(report2)
                         + "\ntime duration 3:   " + str(test_duration) + str(report3))

        self.assertNotEqual(None, report1, "report shouldn't be empty")
        self.assertEqual(Message.NO_ERROR, report1.getErrorCode(), "OK, this is the end of the test case")

    def tearDown(self):
        print("==============================")
        print("TearDown: TestCase EM3 Sleep")
        print("==============================")
        ack = self.send_teardown_command(EMBEDDED_TEST_PARTICIPANT, TIMEOUT)
        self.assertEqual(Message.NO_ERROR, ack.getErrorCode(), "")


class TestCase_SleepToEm2(abstract_test_case.AbstractTestCase):
    test_case_id = 2

    def setUp(self):
        print("==============================")
        print("SetUp: TestCase EM2 Sleep")
        print("==============================")
        ack = self.send_setup_command(EMBEDDED_TEST_PARTICIPANT, TIMEOUT)
        self.assertEqual(Message.NO_ERROR, ack.getErrorCode(), "")

    def runTest(self):
        print("==============================")
        print("Run: TestCase EM2 Sleep")
        print("==============================")

        test_duration = test_durations.get_next_test_duration()
        tlvs = [(TLV_TYPE_TEST_DURATION, str(test_duration))]
        ack = self.send_run_command(EMBEDDED_TEST_PARTICIPANT, TIMEOUT, tlvs)
        self.assertEqual(Message.NO_ERROR, ack.getErrorCode(), "")

        result = self.wait_for_reports([EMBEDDED_TEST_PARTICIPANT], 5 * test_duration)

        report1 = self.get_last_report(EMBEDDED_TEST_PARTICIPANT)

        self.assertEqual(True, result, "the waitForReports has timed out...\n"
                         + "max time duration: " + str(test_duration)
                         + "\ntime duration 1:   " + str(test_duration) + str(report1)
                         + "\ntime duration 2:   " + str(test_duration) + str(report2)
                         + "\ntime duration 3:   " + str(test_duration) + str(report3))

        self.assertNotEqual(None, report1, "report shouldn't be empty")
        self.assertEqual(Message.NO_ERROR, report1.getErrorCode(), "OK, this is the end of the test case")

    def tearDown(self):
        print("==============================")
        print("TearDown: TestCase EM2 Sleep")
        print("==============================")
        ack = self.send_teardown_command(EMBEDDED_TEST_PARTICIPANT, TIMEOUT)
        self.assertEqual(Message.NO_ERROR, ack.getErrorCode(), "")

