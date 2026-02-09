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