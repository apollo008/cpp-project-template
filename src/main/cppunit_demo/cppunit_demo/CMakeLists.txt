
add_subdirectory(test)
add_subdirectory(demo)

add_library(cppunit_demo_main_lib SHARED
        cppunit_demo_main.cpp
        )
target_link_libraries(cppunit_demo_main_lib
        cppunit_demo_lib
        tulip
        )

add_executable( cppunit_demo_main
        cppunit_demo_main.cpp
        )
target_link_libraries( cppunit_demo_main
        cppunit_demo_lib
        tulip
        )

install(FILES
        common.h
        DESTINATION include/cppunit_demo)

install(TARGETS
        cppunit_demo_main_lib
        DESTINATION lib)

install(TARGETS
        cppunit_demo_main
        DESTINATION bin)
