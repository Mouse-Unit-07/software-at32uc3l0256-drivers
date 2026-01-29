#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for hal_implementation source files                      #
#                                                                              #
#------------------------------------------------------------------------------#
add_library(at32uc3l0256_hal_implementation_lib STATIC
    ${CMAKE_CURRENT_LIST_DIR}/delete-me.c
)

target_include_directories(at32uc3l0256_hal_implementation_lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(at32uc3l0256_hal_implementation_lib PUBLIC
    hal_contracts_lib
    runtime_diagnostics_lib
)
