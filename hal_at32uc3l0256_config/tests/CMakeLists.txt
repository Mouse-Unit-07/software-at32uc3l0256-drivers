#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for hal_at32uc3l0256_config test files                   #
#                                                                              #
#------------------------------------------------------------------------------#
set(ALL_TEST_SOURCES
    ${ALL_TEST_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/test_hal_at32uc3l0256_config.cpp
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256_config/configs/clock/clock_hal_config.c
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256_config/configs/clock/clock_hal_config.h
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256_config/configs/gpio/gpio_hal_config.c
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256_config/configs/gpio/gpio_hal_config.h
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256_config/configs/timer_counter/timer_counter_hal_config.c
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256_config/configs/timer_counter/timer_counter_hal_config.h
    PARENT_SCOPE
)

add_executable(test_hal_at32uc3l0256_config
    ${CMAKE_CURRENT_SOURCE_DIR}/test_hal_at32uc3l0256_config.cpp
    ${CMAKE_SOURCE_DIR}/cmake/tests/test_main.cpp
)

target_link_libraries(test_hal_at32uc3l0256_config PRIVATE
    asf_mock_lib
    hal_at32uc3l0256_config_lib
    CppUTest::CppUTest
    CppUTestExt
)

add_test(NAME test_hal_at32uc3l0256_config COMMAND test_hal_at32uc3l0256_config)
