#include "cppunit_demo/common.h"
#include "cppunit_demo/demo/calculator.h"
#include "tulip/TLogDefine.h"


STD_USE_NAMESPACE;
CPPUNIT_DEMO_USE_NAMESPACE;

int main(int argc, char** argv) {

    // configurate TLog from logger config file 'logger.conf'
    TLOG_CONFIG("logger.conf");

    //declare and setup tlog variable
    TLOG_DECLARE_AND_SETUP_LOGGER(CPPUNITDEMO, MAIN);


    CalculatorPtr calculator = std::make_shared<Calculator>();
    int num1 = 20;
    int num2 = 10;
    int sum = calculator->add(num1,num2);
    TLOG_LOG(INFO, "%d + %d = %d", num1, num2, sum);

    TLOG_LOG_FLUSH();
    TLOG_LOG_SHUTDOWN();
    return 0;
}