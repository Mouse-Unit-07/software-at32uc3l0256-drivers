#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for ADC HAL driver source files                          #
#                                                                              #
#------------------------------------------------------------------------------#
add_library(adc_at32uc3l0256_lib STATIC
    ${CMAKE_CURRENT_LIST_DIR}/adc_at32uc3l0256.c
)

target_include_directories(adc_at32uc3l0256_lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(adc_at32uc3l0256_lib PRIVATE
    runtime_diagnostics_lib
)

if (TARGET_AVR32)
    target_link_libraries(adc_at32uc3l0256_lib PRIVATE
        asf_lib
    )
endif()

if (TARGET_WINDOWS)
    target_link_libraries(adc_at32uc3l0256_lib PRIVATE
        asf_mock_lib
    )
endif()
