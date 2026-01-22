#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for hello_world test files                               #
#                                                                              #
#------------------------------------------------------------------------------#
# \/=== Add all test and associated tested source files
set(LOCAL_TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/test_print_hello_world.cpp
    ${CMAKE_SOURCE_DIR}/src/hello_world/print_hello_world.c
)

set(ALL_TEST_SOURCES
    ${ALL_TEST_SOURCES}
    ${LOCAL_TEST_SOURCES}
    PARENT_SCOPE
)

add_executable(test_hello_world # <=== Define your test target
    ${LOCAL_TEST_SOURCES}
    ${CMAKE_SOURCE_DIR}/tests/test_main.cpp
)

target_include_directories(test_hello_world PRIVATE # <=== Rename to your test target
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(test_hello_world PRIVATE # <=== Rename to your test target
    hello_world_lib # <== Rename to your build target
    CppUTest
    CppUTestExt
)

add_test(NAME test_hello_world COMMAND test_hello_world) # <=== Rename to your test target
