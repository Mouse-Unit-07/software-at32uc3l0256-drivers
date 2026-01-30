#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for ASF source files                                     #
#                                                                              #
#------------------------------------------------------------------------------#
add_library(asf_lib STATIC
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/adcifb/adcifb.c
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/eic/eic.c
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/flashcdw/flashcdw.c
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/gpio/gpio.c
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/intc/intc.c
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/pwma/pwma.c
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/tc/tc.c
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/usart/usart.c
    ${CMAKE_CURRENT_LIST_DIR}/common/boards/user_board/init.c
    ${CMAKE_CURRENT_LIST_DIR}/common/services/clock/uc3l/dfll.c
    ${CMAKE_CURRENT_LIST_DIR}/common/services/clock/uc3l/osc.c
    ${CMAKE_CURRENT_LIST_DIR}/common/services/clock/uc3l/pll.c
    ${CMAKE_CURRENT_LIST_DIR}/common/services/serial/usart_serial.c
    ${CMAKE_CURRENT_LIST_DIR}/common/utils/stdio/read.c
    ${CMAKE_CURRENT_LIST_DIR}/common/utils/stdio/write.c
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/intc/exception.S
    ${CMAKE_CURRENT_LIST_DIR}/avr32/utils/startup/startup_uc3.S
    ${CMAKE_CURRENT_LIST_DIR}/avr32/utils/startup/trampoline_uc3.S
)

target_include_directories(asf_lib PUBLIC
    ${AVR32_INCLUDE_LIBRARIES}
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/config
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/adcifb
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/cpu/cycle_counter
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/eic
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/flashcdw
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/gpio
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/intc
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/pwma
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/tc
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/usart
    ${CMAKE_CURRENT_LIST_DIR}/avr32/utils
    ${CMAKE_CURRENT_LIST_DIR}/avr32/utils/header_files
    ${CMAKE_CURRENT_LIST_DIR}/avr32/utils/preprocessor
    ${CMAKE_CURRENT_LIST_DIR}/avr32/utils/startup
    ${CMAKE_CURRENT_LIST_DIR}/common/boards
    ${CMAKE_CURRENT_LIST_DIR}/common/boards/user_board
    ${CMAKE_CURRENT_LIST_DIR}/common/services/clock
    ${CMAKE_CURRENT_LIST_DIR}/common/services/clock/uc3l
    ${CMAKE_CURRENT_LIST_DIR}/common/services/delay
    ${CMAKE_CURRENT_LIST_DIR}/common/services/serial
    ${CMAKE_CURRENT_LIST_DIR}/common/services/serial/uc3_usart
    ${CMAKE_CURRENT_LIST_DIR}/common/utils
    ${CMAKE_CURRENT_LIST_DIR}/common/utils/interrupt
    ${CMAKE_CURRENT_LIST_DIR}/common/utils/stdio/stdio_serial
)
