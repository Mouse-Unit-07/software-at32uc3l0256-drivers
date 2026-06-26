#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for clock HAL driver source files                        #
#                                                                              #
#------------------------------------------------------------------------------#
add_library(clock_at32uc3l0256_lib STATIC
    ${CMAKE_CURRENT_LIST_DIR}/clock_at32uc3l0256.c
)

target_link_libraries(clock_at32uc3l0256_lib PRIVATE
    runtime_diagnostics_lib
)

if (TARGET_AVR32)
    target_include_directories(clock_at32uc3l0256_lib PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        $<TARGET_PROPERTY:asf_lib,INTERFACE_INCLUDE_DIRECTORIES>
    )

    target_link_libraries(clock_at32uc3l0256_lib PRIVATE
        asf_lib
    )
endif()

if (TARGET_WINDOWS)
    target_include_directories(clock_at32uc3l0256_lib PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        $<TARGET_PROPERTY:asf_mock_lib,INTERFACE_INCLUDE_DIRECTORIES>
    )

    target_link_libraries(clock_at32uc3l0256_lib PRIVATE
        asf_mock_lib
    )
endif()
