add_subdirectory(test)

add_library(cppunit_demo_lib SHARED
        calculator.cpp)

add_executable(cppunit_demo_test1 calculator_test1.cpp )
add_executable(cppunit_demo_test2 calculator_test2.cpp )
add_executable(cppunit_demo_test3 calculator_test3.cpp )
add_executable(cppunit_demo_test4 calculator_test4.cpp )
add_executable(cppunit_demo_test5 calculator_test5.cpp )

set_property(TARGET cppunit_demo_test1 PROPERTY CXX_STANDARD 11)
set_property(TARGET cppunit_demo_test2 PROPERTY CXX_STANDARD 11)
set_property(TARGET cppunit_demo_test3 PROPERTY CXX_STANDARD 11)
set_property(TARGET cppunit_demo_test4 PROPERTY CXX_STANDARD 11)
set_property(TARGET cppunit_demo_test5 PROPERTY CXX_STANDARD 11)

target_link_libraries(cppunit_demo_test1 cppunit dl tulip cppunit_demo_lib )
target_link_libraries(cppunit_demo_test2 cppunit dl tulip cppunit_demo_lib )
target_link_libraries(cppunit_demo_test3 cppunit dl tulip cppunit_demo_lib )
target_link_libraries(cppunit_demo_test4 cppunit dl tulip cppunit_demo_lib )
target_link_libraries(cppunit_demo_test5 cppunit dl tulip cppunit_demo_lib )

#add_test(cppunit_demo_test1 cppunit_demo_test1)
#add_test(cppunit_demo_test2 cppunit_demo_test2)
#add_test(cppunit_demo_test3 cppunit_demo_test3)
#add_test(cppunit_demo_test4 cppunit_demo_test4)
#add_test(cppunit_demo_test5 cppunit_demo_test5)



install(TARGETS
        cppunit_demo_test1
        cppunit_demo_test2
        cppunit_demo_test3
        cppunit_demo_test4
        cppunit_demo_test5
        DESTINATION bin)

install(TARGETS
        cppunit_demo_lib
        DESTINATION lib)

install(FILES
        calculator_test1.h
        calculator_test2.h
        calculator_test3.h
        calculator_test4.h
        calculator_test5.h
        calculator.h
        DESTINATION include/cppunit_demo/demo)
