#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for ASF mock source files                                #
#                                                                              #
#------------------------------------------------------------------------------#
if (TARGET_WINDOWS)
    add_library(asf_mock_lib STATIC
        ${CMAKE_CURRENT_LIST_DIR}/clock/clock_mock.c
        ${CMAKE_CURRENT_LIST_DIR}/gpio/gpio_mock.c
        ${CMAKE_CURRENT_LIST_DIR}/timer_counter/timer_counter_mock.c
        ${CMAKE_CURRENT_LIST_DIR}/pwm/pwm_mock.c
        ${CMAKE_CURRENT_LIST_DIR}/iic/iic_mock.c
        ${CMAKE_CURRENT_LIST_DIR}/adc/adc_mock.c
        ${CMAKE_CURRENT_LIST_DIR}/usart/usart_mock.c
    )
    
    target_include_directories(asf_mock_lib PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/clock
        ${CMAKE_CURRENT_LIST_DIR}/gpio
        ${CMAKE_CURRENT_LIST_DIR}/timer_counter
        ${CMAKE_CURRENT_LIST_DIR}/pwm
        ${CMAKE_CURRENT_LIST_DIR}/iic
        ${CMAKE_CURRENT_LIST_DIR}/adc
        ${CMAKE_CURRENT_LIST_DIR}/usart
    )
endif()
