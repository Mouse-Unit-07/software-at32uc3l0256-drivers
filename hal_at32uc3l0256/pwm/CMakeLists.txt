#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for PWM HAL driver source files                          #
#                                                                              #
#------------------------------------------------------------------------------#
add_library(pwm_at32uc3l0256_lib STATIC
    ${CMAKE_CURRENT_LIST_DIR}/pwm_at32uc3l0256.c
)

target_include_directories(pwm_at32uc3l0256_lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(pwm_at32uc3l0256_lib PUBLIC
    runtime_diagnostics_lib
)

if (TARGET_AVR32)
    target_link_libraries(pwm_at32uc3l0256_lib PUBLIC
        asf_lib
    )
endif()

if (TARGET_WINDOWS)
    target_link_libraries(pwm_at32uc3l0256_lib PUBLIC
        asf_mock_lib
    )
endif()
