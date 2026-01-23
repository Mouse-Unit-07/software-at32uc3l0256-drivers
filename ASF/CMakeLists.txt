#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# CMakeLists.txt file for ASF source files                                     #
#                                                                              #
#------------------------------------------------------------------------------#
target_sources(at32uc3l0256_drivers_lib PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/adcifb/adcifb.c
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/eic/eic.c
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/flashcdw/flashcdw.c
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/gpio/gpio.c
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/intc/intc.c
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/pwma/pwma.c
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/tc/tc.c
    ${CMAKE_CURRENT_LIST_DIR}/common/boards/user_board/init.c
    ${CMAKE_CURRENT_LIST_DIR}/common/services/clock/uc3l/dfll.c
    ${CMAKE_CURRENT_LIST_DIR}/common/services/clock/uc3l/osc.c
    ${CMAKE_CURRENT_LIST_DIR}/common/services/clock/uc3l/pll.c
    ${CMAKE_CURRENT_LIST_DIR}/avr32/drivers/intc/exception.S
    ${CMAKE_CURRENT_LIST_DIR}/avr32/utils/startup/startup_uc3.S
    ${CMAKE_CURRENT_LIST_DIR}/avr32/utils/startup/trampoline_uc3.S
)

target_include_directories(at32uc3l0256_drivers_lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)
