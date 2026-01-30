#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for hal_at32uc3l0256 source files                        #
#                                                                              #
#------------------------------------------------------------------------------#
add_library(hal_at32uc3l0256_lib STATIC
    ${CMAKE_CURRENT_LIST_DIR}/delete-me.c
)

target_include_directories(hal_at32uc3l0256_lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(hal_at32uc3l0256_lib PUBLIC
    asf_lib
)
