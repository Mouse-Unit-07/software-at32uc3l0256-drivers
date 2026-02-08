#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for clock_hal_config test files                          #
#                                                                              #
#------------------------------------------------------------------------------#
set(ALL_TEST_SOURCES
    ${ALL_TEST_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/test_clock_hal_config.cpp
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256_config/clock/clock_hal_config.c
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256_config/clock/clock_hal_config.h
    PARENT_SCOPE
)

add_executable(test_clock_hal_config
    ${CMAKE_CURRENT_SOURCE_DIR}/test_clock_hal_config.cpp
    ${CMAKE_SOURCE_DIR}/cmake/tests/test_main.cpp
)

target_link_libraries(test_clock_hal_config PRIVATE
    hal_contracts_lib
    hal_at32uc3l0256_config_lib
    CppUTest::CppUTest
    CppUTestExt
)

add_test(NAME test_clock_hal_config COMMAND test_clock_hal_config)
