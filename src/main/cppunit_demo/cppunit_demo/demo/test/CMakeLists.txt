
add_executable(cppunit_demo_test
        calculator_unittest.cpp
        ${DOTEST_CPP}
        )
target_link_libraries(cppunit_demo_test
        cppunit_demo_lib
        tulip
        cppunit
        dl
        )

add_test(cppunit_demo_test cppunit_demo_test)