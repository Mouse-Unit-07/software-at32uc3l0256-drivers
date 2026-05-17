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
)

# libraries that link to these config libraries need hal_contracts_lib
# for the config libraries to make any sense
target_link_libraries(usart_at32uc3l0256_config_lib PUBLIC
    hal_contracts_lib
)

# ...but they don't need the implementation
target_link_libraries(usart_at32uc3l0256_config_lib PRIVATE
    usart_at32uc3l0256_lib
)
