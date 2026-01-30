#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for ASF mock source files                                #
#                                                                              #
#------------------------------------------------------------------------------#
if (TARGET_WINDOWS)
    add_library(asf_mock_lib STATIC
        ${CMAKE_CURRENT_LIST_DIR}/delete-me.c
    )
    
    target_include_directories(asf_mock_lib PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
endif()