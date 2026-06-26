#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for timer counter HAL config source files                #
#                                                                              #
#------------------------------------------------------------------------------#
add_library(timer_counter_at32uc3l0256_config_lib STATIC
    ${CMAKE_CURRENT_LIST_DIR}/timer_counter_hal_config.c
)

target_include_directories(timer_counter_at32uc3l0256_config_lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    $<TARGET_PROPERTY:hal_contracts_lib,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:timer_counter_at32uc3l0256_lib,INTERFACE_INCLUDE_DIRECTORIES>
)

target_link_libraries(timer_counter_at32uc3l0256_config_lib PRIVATE
    hal_contracts_lib
    timer_counter_at32uc3l0256_lib
)
