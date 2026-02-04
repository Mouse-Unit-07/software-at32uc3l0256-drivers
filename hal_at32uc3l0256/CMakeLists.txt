#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for hal_at32uc3l0256 source files                        #
#                                                                              #
#------------------------------------------------------------------------------#
add_library(hal_at32uc3l0256_lib STATIC
    ${CMAKE_CURRENT_LIST_DIR}/clock/clock_at32uc3l0256.c
    ${CMAKE_CURRENT_LIST_DIR}/gpio/gpio_at32uc3l0256.c
    ${CMAKE_CURRENT_LIST_DIR}/timer_counter/timer_counter_at32uc3l0256.c
    ${CMAKE_CURRENT_LIST_DIR}/pwm/pwm_at32uc3l0256.c
    ${CMAKE_CURRENT_LIST_DIR}/iic/iic_at32uc3l0256.c
    ${CMAKE_CURRENT_LIST_DIR}/adc/adc_at32uc3l0256.c
)

target_include_directories(hal_at32uc3l0256_lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/clock
    ${CMAKE_CURRENT_LIST_DIR}/gpio
    ${CMAKE_CURRENT_LIST_DIR}/timer_counter
    ${CMAKE_CURRENT_LIST_DIR}/pwm
    ${CMAKE_CURRENT_LIST_DIR}/iic
    ${CMAKE_CURRENT_LIST_DIR}/adc
)

target_link_libraries(hal_at32uc3l0256_lib PUBLIC
    runtime_diagnostics_lib
)

if (TARGET_AVR32)
    target_link_libraries(hal_at32uc3l0256_lib PUBLIC
        asf_lib
    )
endif()

if (TARGET_WINDOWS)
    target_link_libraries(hal_at32uc3l0256_lib PUBLIC
        asf_mock_lib
    )
endif()
