/*********************************************************************************
  *Copyright(C),dingbinthu@163.com
  *All rights reserved.
  *
  *FileName:       string_to_int_unittest_exe.cpp
  *Author:         dingbinthu@163.com
  *Version:        1.0
  *Date:           2/25/21
  *Description:    File to demo imeplementation for entire unittest exe code process
**********************************************************************************/
#include <cassert>
#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TextTestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <string>
#include <sstream>


bool Str2IntCore(const char* pDigits, bool minus, int* result) {
    assert(nullptr != pDigits && nullptr != result);
    long long num = 0;
    while (*pDigits != '\0') {
        if (*pDigits >= '0' && *pDigits <= '9') {
            int flag = (minus ? -1: 1);
            num = 10 * num + flag * (*pDigits - '0');
            if ( (!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)(0x80000000))) {
                num = 0;
                break;
            }
            ++pDigits;
        }
        else {
            num = 0;
            break;
        }
    }
    *result = (int)num;
    return '\0' == *pDigits;
}

bool Str2Int(const char* pStr, int* result) {
    if (nullptr == pStr || nullptr == result || '\0' == *pStr) {
        return false;
    }
    *result = 0;
    bool minus = false;
    if (*pStr == '+') {
        ++pStr;
    }
    else if (*pStr == '-') {
        minus = true;
        ++pStr;
    }
    if ('\0' != *pStr) {
        return Str2IntCore(pStr,minus,result);
    }
    return false;
}


class Str2IntTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(Str2IntTest);
    CPPUNIT_TEST(testStr2Int);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp() {}
    void tearDown() {}

    void testStr2Int() {
        testStr2IntInternal(nullptr,false,0,__LINE__);
        testStr2IntInternal("",false,0,__LINE__);
        testStr2IntInternal("0",true,0,__LINE__);
        testStr2IntInternal("1",true,1,__LINE__);
        testStr2IntInternal(".",false,0,__LINE__);
        testStr2IntInternal("a",false,0,__LINE__);
        testStr2IntInternal("e",false,0,__LINE__);
        testStr2IntInternal("E",false,0,__LINE__);
        testStr2IntInternal("+",false,0,__LINE__);
        testStr2IntInternal("-",false,0,__LINE__);
        testStr2IntInternal("+3",true,3,__LINE__);
        testStr2IntInternal("-3",true,-3,__LINE__);
        testStr2IntInternal("-3a",false,0,__LINE__);

        testStr2IntInternal("2147483646",true,2147483646,__LINE__);
        testStr2IntInternal("2147483647",true,2147483647,__LINE__);
        testStr2IntInternal("2147483648",false,0,__LINE__);
        testStr2IntInternal("2147483649",false,0,__LINE__);

        testStr2IntInternal("-2147483646",true,-2147483646,__LINE__);
        testStr2IntInternal("-2147483647",true,-2147483647,__LINE__);
        testStr2IntInternal("-2147483648",true,-2147483648,__LINE__);
        testStr2IntInternal("-2147483649",false,0,__LINE__);
    }
private:
    void testStr2IntInternal(const char* pStr, bool ret, int result, int lineNo) {
       int v;
       bool r = Str2Int(pStr,&v);
       std::ostringstream oss;
       oss << "from lineNo:" << lineNo;
       std::string msg = oss.str();
       if (r) {
           CPPUNIT_ASSERT_EQUAL_MESSAGE(msg.c_str(), ret,r);
           CPPUNIT_ASSERT_EQUAL_MESSAGE(msg.c_str(),result,v);
       }
       else {
           CPPUNIT_ASSERT_EQUAL_MESSAGE(msg.c_str(),ret,r);
       }
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(Str2IntTest);


int main(int argc, char** argv) {
    CppUnit::TextTestRunner testRunner;
    testRunner.setOutputter(new CppUnit::CompilerOutputter(&testRunner.result(),std::cerr));
    CppUnit::TestFactoryRegistry& registry = CppUnit::TestFactoryRegistry::getRegistry();
    testRunner.addTest(registry.makeTest());
    bool ok = testRunner.run("",false);
    return ok ? 0:1;
}