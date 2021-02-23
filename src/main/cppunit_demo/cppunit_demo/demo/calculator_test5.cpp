/*********************************************************************************
  *Copyright(C),dingbinthu@163.com
  *All rights reserved.
  *
  *FileName:       calculator_test5.cpp
  *Author:         dingbinthu@163.com
  *Version:        1.0
  *Date:           2/21/21
  *Description:    Calculator unittest5 implementation 本例说明如何使用 CppUnit::TestFixture
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
#include "cppunit/extensions/HelperMacros.h"

#include "cppunit_demo/demo/calculator_test5.h"
#include "cppunit_demo/demo/calculator.h"

STD_USE_NAMESPACE;
CPPUNIT_DEMO_USE_NAMESPACE;

CPPUNIT_DEMO_BEGIN_NAMESPACE


// 自定义的 TestFixture 需要继承自 CppUnit::TestFixture
class CalculatorFixture : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(CalculatorFixture);
        CPPUNIT_TEST(testAdd);
        CPPUNIT_TEST(testSub);
    CPPUNIT_TEST_SUITE_END();

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
// 在实现 TestFixute 的 cpp 文件中注册自定义的 TestFixture
// 到全局的 TestFactoryRegistry 中
CPPUNIT_TEST_SUITE_REGISTRATION(CalculatorFixture);

CPPUNIT_DEMO_END_NAMESPACE

int main(int argc, char** argv)
{
    /* 创建 TestRunner */
    // 这里使用 TextTestRunner 将执行过程中的输出以文本形式打印出来
    CppUnit::TextTestRunner runner;

    // 在执行测试用力的 cpp 文件中通过全局的 TestFactoryRegistry 获取
    // 所有注册在其中的 TestSuite
    runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());


    // 设置输出对象，这里传递一个 TextOutputter，将执行过程中的输出打印到标准输出
    runner.setOutputter(new CppUnit::TextOutputter(&runner.result(), std::cout));

    /* 执行测试用例 */
    runner.run();

    return runner.result().wasSuccessful() ? 0 : 1;
}
