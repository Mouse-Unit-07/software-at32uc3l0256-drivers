#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for external interrupt controller HAL driver source      #
# files                                                                        #
#                                                                              #
#------------------------------------------------------------------------------#
if(NOT DEFINED MOUSE_TARGET)
    message(FATAL_ERROR "MOUSE_TARGET not specified")
endif()

if(MOUSE_TARGET STREQUAL "rev_a")
    set(EIC_SOURCE
        ${CMAKE_CURRENT_LIST_DIR}/eic_rev_a_at32uc3l0256.c
    )
elseif(MOUSE_TARGET STREQUAL "rev_b")
    set(EIC_SOURCE
        ${CMAKE_CURRENT_LIST_DIR}/eic_rev_b_at32uc3l0256.c
    )
else()
    message(FATAL_ERROR "Unsupported MOUSE_TARGET: ${MOUSE_TARGET}")
endif()

add_library(eic_at32uc3l0256_lib STATIC
    ${EIC_SOURCE}
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
