#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for hal_at32uc3l0256 test files                          #
#                                                                              #
#------------------------------------------------------------------------------#
set(ALL_TEST_SOURCES
    ${ALL_TEST_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/test_hal_at32uc3l0256.cpp
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256/clock/clock_at32uc3l0256.c
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256/clock/clock_at32uc3l0256.h
    PARENT_SCOPE
)

add_executable(test_hal_at32uc3l0256
    ${CMAKE_CURRENT_SOURCE_DIR}/test_hal_at32uc3l0256.cpp
    ${CMAKE_SOURCE_DIR}/cmake/tests/test_main.cpp
)

# Needed for STL library in C++ test file:
target_compile_definitions(test_hal_at32uc3l0256
    PRIVATE CPPUTEST_USE_NEW_MACROS=0
)

target_link_libraries(test_hal_at32uc3l0256 PRIVATE
    hal_at32uc3l0256_lib
    CppUTest::CppUTest
    CppUTestExt
)

add_test(NAME test_hal_at32uc3l0256 COMMAND test_hal_at32uc3l0256)
