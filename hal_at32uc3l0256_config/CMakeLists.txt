#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for hal_at32uc3l0256_config source files                 #
#                                                                              #
#------------------------------------------------------------------------------#
add_library(hal_at32uc3l0256_config_lib STATIC
    ${CMAKE_CURRENT_LIST_DIR}/clock/clock_hal_config.c
    ${CMAKE_CURRENT_LIST_DIR}/gpio/gpio_hal_config.c
    ${CMAKE_CURRENT_LIST_DIR}/timer_counter/timer_counter_hal_config.c
    ${CMAKE_CURRENT_LIST_DIR}/pwm/pwm_hal_config.c
    ${CMAKE_CURRENT_LIST_DIR}/iic/iic_hal_config.c
    ${CMAKE_CURRENT_LIST_DIR}/adc/adc_hal_config.c
    ${CMAKE_CURRENT_LIST_DIR}/usart/usart_hal_config.c
    ${CMAKE_CURRENT_LIST_DIR}/eic/eic_hal_config.c
)

target_include_directories(hal_at32uc3l0256_config_lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/clock
    ${CMAKE_CURRENT_LIST_DIR}/gpio
    ${CMAKE_CURRENT_LIST_DIR}/timer_counter
    ${CMAKE_CURRENT_LIST_DIR}/pwm
    ${CMAKE_CURRENT_LIST_DIR}/iic
    ${CMAKE_CURRENT_LIST_DIR}/adc
    ${CMAKE_CURRENT_LIST_DIR}/usart
    ${CMAKE_CURRENT_LIST_DIR}/eic
)

# libraries that link to hal_at32uc3l0256_config_lib need hal_contracts_lib
# for hal_at32uc3l0256_config_lib to make any sense
target_link_libraries(hal_at32uc3l0256_config_lib PUBLIC
    hal_contracts_lib
)

# ...but they don't need the implementation
target_link_libraries(hal_at32uc3l0256_config_lib PRIVATE
    hal_at32uc3l0256_lib
)