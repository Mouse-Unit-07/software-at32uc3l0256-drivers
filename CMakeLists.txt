#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# Top level CMakeLists.txt file (for this software repo)                       #
#                                                                              #
#------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 4.0.2)
project(at32uc3l0256_drivers_project LANGUAGES C ASM)

include(FetchContent)

FetchContent_Declare(
    hardware_abstraction_layer
    GIT_REPOSITORY git@github.com:Mouse-Unit-07/software-hardware-abstraction-layer.git
    GIT_TAG main
)
FetchContent_MakeAvailable(hardware_abstraction_layer)

FetchContent_Declare(
    runtime_diagnostics
    GIT_REPOSITORY git@github.com:Mouse-Unit-07/software-runtime-diagnostics.git
    GIT_TAG main
)
FetchContent_MakeAvailable(runtime_diagnostics)

add_subdirectory(ASF)
add_subdirectory(ASF_mock)
add_subdirectory(hal_at32uc3l0256/adc)
add_subdirectory(hal_at32uc3l0256/clock)
add_subdirectory(hal_at32uc3l0256/eic)
add_subdirectory(hal_at32uc3l0256/gpio)
add_subdirectory(hal_at32uc3l0256/iic)
add_subdirectory(hal_at32uc3l0256/pwm)
add_subdirectory(hal_at32uc3l0256/timer_counter)
add_subdirectory(hal_at32uc3l0256/usart)
add_subdirectory(hal_at32uc3l0256_config/adc)
add_subdirectory(hal_at32uc3l0256_config/clock)
add_subdirectory(hal_at32uc3l0256_config/eic)
add_subdirectory(hal_at32uc3l0256_config/gpio)
add_subdirectory(hal_at32uc3l0256_config/iic)
add_subdirectory(hal_at32uc3l0256_config/pwm)
add_subdirectory(hal_at32uc3l0256_config/timer_counter)
add_subdirectory(hal_at32uc3l0256_config/usart)

option(ENABLE_HAL_AT32UC3L0256_TESTS "Build/enable HAL AT32UC3L0256 tests" OFF)

if(TARGET_WINDOWS AND SUPPORTS_WINDOWS)
    if(ENABLE_HAL_AT32UC3L0256_TESTS)
        add_subdirectory(hal_at32uc3l0256/adc/tests)
        add_subdirectory(hal_at32uc3l0256/clock/tests)
        add_subdirectory(hal_at32uc3l0256/eic/tests)
        add_subdirectory(hal_at32uc3l0256/gpio/tests)
        add_subdirectory(hal_at32uc3l0256/iic/tests)
        add_subdirectory(hal_at32uc3l0256/pwm/tests)
        add_subdirectory(hal_at32uc3l0256/timer_counter/tests)
        add_subdirectory(hal_at32uc3l0256/usart/tests)

        add_subdirectory(hal_at32uc3l0256_config/adc/tests)
        add_subdirectory(hal_at32uc3l0256_config/clock/tests)
        add_subdirectory(hal_at32uc3l0256_config/eic/tests)
        add_subdirectory(hal_at32uc3l0256_config/gpio/tests)
        add_subdirectory(hal_at32uc3l0256_config/iic/tests)
        add_subdirectory(hal_at32uc3l0256_config/pwm/tests)
        add_subdirectory(hal_at32uc3l0256_config/timer_counter/tests)
        add_subdirectory(hal_at32uc3l0256_config/usart/tests)
    endif()
endif()

add_library(hal_config_lib INTERFACE)

target_link_libraries(hal_config_lib INTERFACE
    adc_at32uc3l0256_config_lib
    clock_at32uc3l0256_config_lib
    eic_at32uc3l0256_config_lib
    gpio_at32uc3l0256_config_lib
    iic_at32uc3l0256_config_lib
    pwm_at32uc3l0256_config_lib
    timer_counter_at32uc3l0256_config_lib
    usart_at32uc3l0256_config_lib
)
