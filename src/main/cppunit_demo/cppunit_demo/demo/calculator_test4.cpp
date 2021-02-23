/*********************************************************************************
  *Copyright(C),dingbinthu@163.com
  *All rights reserved.
  *
  *FileName:       calculator_test4.cpp
  *Author:         dingbinthu@163.com
  *Version:        1.0
  *Date:           2/21/21
  *Description:    Calculator unittest3 implementation 本例说明如何使用 CppUnit::TestFixture
  *                CppUnit::TestFixture 表示测试固件，用来建立测试基准或构建测试用例的先决条件。
  *                比如在执行测试用例之前连接数据库，准备初始数据等。
  *                CppUnit::TestFixture 提供了两个函数 setUp() 和 tearDown() 用来
  *                在执行测试用例之前和之后进行初始化和清理操作。这两个函数将由 CppUnit 框架在
  *                执行测试用例之前和之后调用。
**********************************************************************************/
#include "cppunit/TestFixture.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TextTestRunner.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestResultCollector.h"
#include "cppunit/TextOutputter.h"

#include "cppunit_demo/demo/calculator_test4.h"
#include "cppunit_demo/demo/calculator.h"

STD_USE_NAMESPACE;
CPPUNIT_DEMO_USE_NAMESPACE;

CPPUNIT_DEMO_BEGIN_NAMESPACE


// 自定义的 TestFixture 需要继承自 CppUnit::TestFixture
class CalculatorFixture : public CppUnit::TestFixture
{
    // CppUnit::TestFixture
public:
    // 提供一个静态的方法返回该 TestFixture 的 TestSuite，
    // 以便传给 TestRunner 使用
    static CppUnit::TestSuite *suite()
    {
        CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("CalculatorTest");
        using Caller = CppUnit::TestCaller<CalculatorFixture>;
        testSuite->addTest(new Caller("testAdd", &CalculatorFixture::testAdd));
        testSuite->addTest(new Caller("testSub", &CalculatorFixture::testSub));
        return testSuite;
    }

public:

    // 重写 setUp() 提供初始化操作
    virtual void setUp() override
    {
        // 在实际情况中，可能执行连接数据库，打开文件，加载资源等操作

        m_calculator = new Calculator();
    }

    // 重写 tearDown() 提供清理操作
    virtual void tearDown() override
    {
        // 在实际情况中，可能执行断开数据库连接，关闭文件，销毁资源等操作

        delete m_calculator; m_calculator = nullptr;
    }

    // 测试用例
public:

    void testAdd()
    {
        CPPUNIT_ASSERT(3 == m_calculator->add(1, 2));
    }

    void testSub()
    {
        CPPUNIT_ASSERT(1 == m_calculator->sub(2, 1));
    }

private:
    Calculator *m_calculator;
};

CPPUNIT_DEMO_END_NAMESPACE

int main(int argc, char** argv)
{
    /* 创建 TestRunner */
    // 这里使用 TextTestRunner 将执行过程中的输出以文本形式打印出来
    CppUnit::TextTestRunner runner;

    /* 注册 TestSuite 到 TestRunner */
    // 实际测试环境当中，可能会注册多个 TestSuite 到 TestRunner
    runner.addTest(CalculatorFixture::suite());

    // 设置输出对象，这里传递一个 TextOutputter，将执行过程中的输出打印到标准输出
    runner.setOutputter(new CppUnit::TextOutputter(&runner.result(), std::cout));

    /* 执行测试用例 */
    runner.run();

    return runner.result().wasSuccessful() ? 0 : 1;
}