#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for hal_at32uc3l0256 source files                        #
#                                                                              #
#------------------------------------------------------------------------------#
add_library(hal_at32uc3l0256_lib STATIC
    ${CMAKE_CURRENT_LIST_DIR}/implementations/clock/clock_at32uc3l0256.c
    ${CMAKE_CURRENT_LIST_DIR}/implementations/gpio/gpio_at32uc3l0256.c
    ${CMAKE_CURRENT_LIST_DIR}/implementations/timer_counter/timer_counter_at32uc3l0256.c
)

target_include_directories(hal_at32uc3l0256_lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/implementations/clock
    ${CMAKE_CURRENT_LIST_DIR}/implementations/gpio
    ${CMAKE_CURRENT_LIST_DIR}/implementations/timer_counter
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
