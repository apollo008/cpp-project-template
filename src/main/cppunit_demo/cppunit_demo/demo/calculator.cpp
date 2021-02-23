/*********************************************************************************
  *Copyright(C),dingbinthu@163.com
  *All rights reserved.
  *
  *FileName:       calculator.cpp
  *Author:         dingbinthu@163.com
  *Version:        1.0
  *Date:           2/21/21
  *Description:    File to implementation of class Calculator
**********************************************************************************/
#include "cppunit_demo/demo/calculator.h"

STD_USE_NAMESPACE;


CPPUNIT_DEMO_BEGIN_NAMESPACE

int Calculator::add(int num1, int num2)
{
    return num1 + num2;
}

int Calculator::sub(int num1, int num2)
{
    return num1 - num1;  // 错误，应该是 num1 - num2
}


CPPUNIT_DEMO_END_NAMESPACE
