#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for usart_at32uc3l0256 test files                        #
#                                                                              #
#------------------------------------------------------------------------------#
set_property(GLOBAL APPEND PROPERTY
    ALL_TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/test_usart_at32uc3l0256.cpp
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256/usart/usart_at32uc3l0256.c
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256/usart/usart_at32uc3l0256.h
)

add_executable(test_usart_at32uc3l0256
    ${CMAKE_CURRENT_SOURCE_DIR}/test_usart_at32uc3l0256.cpp
    ${CMAKE_SOURCE_DIR}/platforms/windows/test_main.cpp
)

target_link_libraries(test_usart_at32uc3l0256 PRIVATE
    usart_at32uc3l0256_lib
    CppUTest::CppUTest
    CppUTestExt
)

add_test(NAME test_usart_at32uc3l0256 COMMAND test_usart_at32uc3l0256)
