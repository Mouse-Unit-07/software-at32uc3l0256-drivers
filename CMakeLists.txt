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
add_subdirectory(hal_at32uc3l0256)
add_subdirectory(hal_at32uc3l0256_config)

if(TARGET_WINDOWS)
    if(SUPPORTS_WINDOWS)
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

add_library(hal_lib INTERFACE)

target_link_libraries(hal_lib INTERFACE
    asf_lib
    hal_at32uc3l0256_lib
    hal_at32uc3l0256_config_lib
)
