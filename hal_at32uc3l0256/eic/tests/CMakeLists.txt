#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for eic_at32uc3l0256 test files                          #
#                                                                              #
#------------------------------------------------------------------------------#
if(NOT DEFINED MOUSE_TARGET)
    message(FATAL_ERROR "MOUSE_TARGET not specified")
endif()

if(MOUSE_TARGET STREQUAL "rev_a")
    set(EIC_TEST_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/test_eic_rev_a_at32uc3l0256.cpp
    )
elseif(MOUSE_TARGET STREQUAL "rev_b")
    set(EIC_TEST_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/test_eic_rev_b_at32uc3l0256.cpp
    )
else()
    message(FATAL_ERROR "Unsupported MOUSE_TARGET: ${MOUSE_TARGET}")
endif()

set_property(GLOBAL APPEND PROPERTY
    ALL_TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/test_eic_rev_a_at32uc3l0256.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_eic_rev_b_at32uc3l0256.cpp
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256/eic/eic_rev_a_at32uc3l0256.c
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256/eic/eic_rev_b_at32uc3l0256.c
    ${CMAKE_SOURCE_DIR}/src/hal_at32uc3l0256/eic/eic_at32uc3l0256.h
)

add_executable(test_eic_at32uc3l0256
    ${EIC_TEST_SOURCE}
    ${CMAKE_SOURCE_DIR}/platforms/windows/test_main.cpp
)

target_link_libraries(test_eic_at32uc3l0256 PRIVATE
    eic_at32uc3l0256_lib
    CppUTest::CppUTest
    CppUTestExt
)

add_test(NAME test_eic_at32uc3l0256 COMMAND test_eic_at32uc3l0256)
