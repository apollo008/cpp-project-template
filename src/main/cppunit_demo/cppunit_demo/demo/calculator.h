/*********************************************************************************
  *Copyright(C),dingbinthu@163.com
  *All rights reserved.
  *
  *FileName:       calculator.h
  *Author:         dingbinthu@163.com
  *Version:        1.0
  *Date:           2/21/21
  *Description:    File to declare class of calculator
**********************************************************************************/

#ifndef __CPPUNIT_DEMO_CALCULATOR_H__
#define __CPPUNIT_DEMO_CALCULATOR_H__

#include "cppunit_demo/common.h"

CPPUNIT_DEMO_BEGIN_NAMESPACE

class Calculator
{
public:
    int add(int num1, int num2);
    int sub(int num1, int num2);
};
TYPEDEF_PTR(Calculator);



CPPUNIT_DEMO_END_NAMESPACE

#endif //__CPPUNIT_DEMO_CALCULATOR_H__
