#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for USART HAL config source files                        #
#                                                                              #
#------------------------------------------------------------------------------#
add_library(usart_at32uc3l0256_config_lib STATIC
    ${CMAKE_CURRENT_LIST_DIR}/usart_hal_config.c
)

target_include_directories(usart_at32uc3l0256_config_lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    $<TARGET_PROPERTY:hal_contracts_lib,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:usart_at32uc3l0256_lib,INTERFACE_INCLUDE_DIRECTORIES>
)

target_link_libraries(usart_at32uc3l0256_config_lib PRIVATE
    hal_contracts_lib
    usart_at32uc3l0256_lib
)
