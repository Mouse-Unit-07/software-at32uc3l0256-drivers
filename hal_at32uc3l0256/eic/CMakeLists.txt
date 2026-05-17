#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for external interrupt controller HAL driver source      #
# files                                                                        #
#                                                                              #
#------------------------------------------------------------------------------#
add_library(eic_at32uc3l0256_lib STATIC
    ${CMAKE_CURRENT_LIST_DIR}/eic_at32uc3l0256.c
)

target_include_directories(eic_at32uc3l0256_lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(eic_at32uc3l0256_lib PUBLIC
    runtime_diagnostics_lib
)

if (TARGET_AVR32)
    target_link_libraries(eic_at32uc3l0256_lib PUBLIC
        asf_lib
    )
endif()

if (TARGET_WINDOWS)
    target_link_libraries(eic_at32uc3l0256_lib PUBLIC
        asf_mock_lib
    )
endif()
