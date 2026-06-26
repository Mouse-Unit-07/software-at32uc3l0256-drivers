#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for pwm_at32uc3l0256 test files                          #
#                                                                              #
#------------------------------------------------------------------------------#
set_property(GLOBAL APPEND PROPERTY
    ALL_TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/test_pwm_at32uc3l0256.cpp
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256/pwm/pwm_at32uc3l0256.c
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256/pwm/pwm_at32uc3l0256.h
)

add_executable(test_pwm_at32uc3l0256
    ${CMAKE_CURRENT_SOURCE_DIR}/test_pwm_at32uc3l0256.cpp
    ${CMAKE_SOURCE_DIR}/platforms/windows/test_main.cpp
)

target_link_libraries(test_pwm_at32uc3l0256 PRIVATE
    pwm_at32uc3l0256_lib
    CppUTest::CppUTest
    CppUTestExt
)

add_test(NAME test_pwm_at32uc3l0256 COMMAND test_pwm_at32uc3l0256)
