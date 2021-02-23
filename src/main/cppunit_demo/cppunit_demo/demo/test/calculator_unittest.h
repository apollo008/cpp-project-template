/*********************************************************************************
  *Copyright(C),dingbinthu@163.com
  *All rights reserved.
  *
  *FileName:       calculator_test.h
  *Author:         dingbinthu@163.com
  *Version:        1.0
  *Date:           2/23/21
  *Description:
**********************************************************************************/
#ifndef _CPPUNIT_DEMO_DEMO_TEST_CALCULATOR_TEST_H_
#define _CPPUNIT_DEMO_DEMO_TEST_CALCULATOR_TEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>

#include "cppunit_demo/demo/calculator.h"
#include "cppunit_demo/common.h"
#include "tulip/TLogDefine.h"


CPPUNIT_DEMO_BEGIN_NAMESPACE

class CalculatorTest: public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(CalculatorTest);
    CPPUNIT_TEST(testAdd);
    CPPUNIT_TEST(testSub);
    CPPUNIT_TEST(testFileContent);
    CPPUNIT_TEST_SUITE_END();
public:
    CalculatorTest();
    ~CalculatorTest();
public:
    void setUp();
    void tearDown();
public:
    void testAdd();
    void testSub();
    void testFileContent();
private:
    Calculator*             m_calculator;
    string                  m_rootDir;
    string                  m_testDataFile1;
    string                  m_testDataFile2;
private:
    TLOG_DECLARE();
};
CPPUNIT_DEMO_END_NAMESPACE

#endif //_CPPUNIT_DEMO_DEMO_TEST_CALCULATOR_TEST_H_
