#include <cppunit_demo/test/test.h>
#include "cppunit_demo/demo/test/calculator_unittest.h"

STD_USE_NAMESPACE;

CPPUNIT_DEMO_BEGIN_NAMESPACE

CPPUNIT_TEST_SUITE_REGISTRATION(CalculatorTest);

TLOG_SETUP(cppunitdemo, CalculatorTest);

CalculatorTest::CalculatorTest() {
    m_calculator = nullptr;
}

CalculatorTest::~CalculatorTest() {
    CHECK_DELETE_AND_SET_NULL(m_calculator);
}

void CalculatorTest::setUp()
{
    m_calculator = new Calculator();
    m_rootDir = string(TEST_DATA_PATH);
    m_testDataFile1 = m_rootDir + "/" + "cppunit_test_demo1_testdata.txt";
    m_testDataFile2 = m_rootDir + "/" + "cppunit_test_demo2_testdata.txt";
    TLOG_LOG(INFO,"rootDir:[%s],testDataFile1:[%s],testDataFile2:[%s]", m_rootDir.c_str(), m_testDataFile1.c_str(), m_testDataFile2.c_str());
}

void CalculatorTest::tearDown()
{
    delete m_calculator;
    m_calculator = nullptr;
}

void CalculatorTest::testAdd()
{
    CPPUNIT_ASSERT(3 == m_calculator->add(1, 2));
}

void CalculatorTest::testSub()
{
    CPPUNIT_ASSERT(1 == m_calculator->sub(2, 1));
}

void CalculatorTest::testFileContent() {
    std::ifstream if1(m_testDataFile1.c_str());
    if (if1.is_open() == false) {
        TLOG_LOG(ERROR,"Failed to open testdata file:[%s]", m_testDataFile1.c_str());
        CPPUNIT_ASSERT_MESSAGE(string("Failed to open file:") + m_testDataFile1, true);
    }
    else {
        TLOG_LOG(ERROR,"Open testdata file:[%s] successfully", m_testDataFile1.c_str());
    }

    std::ifstream if2(m_testDataFile2.c_str());
    if (if2.is_open() == false) {
        TLOG_LOG(ERROR,"Failed to open testdata file:[%s]", m_testDataFile2.c_str());
        CPPUNIT_ASSERT_MESSAGE(string("Failed to open file:") + m_testDataFile2, true);
    }
    else {
        TLOG_LOG(ERROR,"Open testdata file:[%s] successfully", m_testDataFile2.c_str());
    }

    string content1,content2;
    if1 >> content1;
    if2 >> content2;

    CPPUNIT_ASSERT(string("150") == content1);
    CPPUNIT_ASSERT(string("201") == content2);
    if1.close();
    if2.close();
}

CPPUNIT_DEMO_END_NAMESPACE