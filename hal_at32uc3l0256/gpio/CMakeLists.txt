#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for GPIO HAL driver source files                         #
#                                                                              #
#------------------------------------------------------------------------------#
if(NOT DEFINED MOUSE_TARGET)
    message(FATAL_ERROR "MOUSE_TARGET not specified")
endif()

if(MOUSE_TARGET STREQUAL "rev_a")
    set(GPIO_SOURCE
        ${CMAKE_CURRENT_LIST_DIR}/gpio_rev_a_at32uc3l0256.c
    )
elseif(MOUSE_TARGET STREQUAL "rev_b")
    set(GPIO_SOURCE
        ${CMAKE_CURRENT_LIST_DIR}/gpio_rev_b_at32uc3l0256.c
    )
else()
    message(FATAL_ERROR "Unsupported MOUSE_TARGET: ${MOUSE_TARGET}")
endif()

add_library(gpio_at32uc3l0256_lib STATIC
    ${GPIO_SOURCE}
)

target_link_libraries(gpio_at32uc3l0256_lib PRIVATE
    runtime_diagnostics_lib
)

if (TARGET_AVR32)
    target_include_directories(gpio_at32uc3l0256_lib PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        $<TARGET_PROPERTY:asf_lib,INTERFACE_INCLUDE_DIRECTORIES>
    )

    target_link_libraries(gpio_at32uc3l0256_lib PRIVATE
        asf_lib
    )
endif()

if (TARGET_WINDOWS)
    target_include_directories(gpio_at32uc3l0256_lib PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        $<TARGET_PROPERTY:asf_mock_lib,INTERFACE_INCLUDE_DIRECTORIES>
    )

    target_link_libraries(gpio_at32uc3l0256_lib PRIVATE
        asf_mock_lib
    )
endif()
