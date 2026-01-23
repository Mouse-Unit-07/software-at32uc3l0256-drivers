#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for config source files                                  #
#                                                                              #
#------------------------------------------------------------------------------#
add_library(config_lib INTERFACE)

target_include_directories(config_lib INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)
