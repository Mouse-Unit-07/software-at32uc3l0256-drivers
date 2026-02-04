#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for adc_at32uc3l0256 test files                          #
#                                                                              #
#------------------------------------------------------------------------------#
set(ALL_TEST_SOURCES
    ${ALL_TEST_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/test_adc_at32uc3l0256.cpp
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256/adc/adc_at32uc3l0256.c
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256/adc/adc_at32uc3l0256.h
    PARENT_SCOPE
)

add_executable(test_adc_at32uc3l0256
    ${CMAKE_CURRENT_SOURCE_DIR}/test_adc_at32uc3l0256.cpp
    ${CMAKE_SOURCE_DIR}/cmake/tests/test_main.cpp
)

target_link_libraries(test_adc_at32uc3l0256 PRIVATE
    hal_at32uc3l0256_lib
    CppUTest::CppUTest
    CppUTestExt
)

if (TARGET_AVR32)
    target_link_libraries(test_adc_at32uc3l0256 PUBLIC
        asf_lib
    )
endif()

if (TARGET_WINDOWS)
    target_link_libraries(test_adc_at32uc3l0256 PUBLIC
        asf_mock_lib
    )
endif()

add_test(NAME test_adc_at32uc3l0256 COMMAND test_adc_at32uc3l0256)
