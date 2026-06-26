#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for internal interrupt controller HAL config source      #
# files                                                                        #
#                                                                              #
#------------------------------------------------------------------------------#
add_library(iic_at32uc3l0256_config_lib STATIC
    ${CMAKE_CURRENT_LIST_DIR}/iic_hal_config.c
)

target_include_directories(iic_at32uc3l0256_config_lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    $<TARGET_PROPERTY:hal_contracts_lib,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:iic_at32uc3l0256_lib,INTERFACE_INCLUDE_DIRECTORIES>
)

target_link_libraries(iic_at32uc3l0256_config_lib PRIVATE
    hal_contracts_lib
    iic_at32uc3l0256_lib
)
