#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# Top level CMakeLists.txt file (for this software repo)                       #
#                                                                              #
#------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 4.0.2)
project(at32uc3l0256_drivers_lib LANGUAGES C ASM)

add_library(at32uc3l0256_drivers_lib STATIC)

add_subdirectory(ASF)
add_subdirectory(config)

target_include_directories(at32uc3l0256_drivers_lib PUBLIC
    ${AVR32_INCLUDE_LIBRARIES}
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/avr32/drivers/adcifb
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/avr32/drivers/cpu/cycle_counter
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/avr32/drivers/eic
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/avr32/drivers/flashcdw
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/avr32/drivers/gpio
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/avr32/drivers/intc
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/avr32/drivers/pwma
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/avr32/drivers/tc
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/avr32/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/avr32/utils/header_files
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/avr32/utils/preprocessor
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/avr32/utils/startup
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/common/boards
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/common/boards/user_board
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/common/services/clock
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/common/services/clock/uc3l
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/common/services/delay
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/common/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/ASF/common/utils/interrupt
    ${CMAKE_CURRENT_SOURCE_DIR}/config
)
