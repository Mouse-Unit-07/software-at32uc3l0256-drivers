#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for timer_counter_hal_config test files                  #
#                                                                              #
#------------------------------------------------------------------------------#
set_property(GLOBAL APPEND PROPERTY
    ALL_TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/test_timer_counter_hal_config.cpp
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256_config/timer_counter/timer_counter_hal_config.c
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256_config/timer_counter/timer_counter_hal_config.h
)

add_executable(test_timer_counter_hal_config
    ${CMAKE_CURRENT_SOURCE_DIR}/test_timer_counter_hal_config.cpp
    ${CMAKE_SOURCE_DIR}/platforms/windows/test_main.cpp
)

target_link_libraries(test_timer_counter_hal_config PRIVATE
    hal_contracts_lib
    timer_counter_at32uc3l0256_config_lib
    CppUTest::CppUTest
    CppUTestExt
)

add_test(NAME test_timer_counter_hal_config COMMAND test_timer_counter_hal_config)
