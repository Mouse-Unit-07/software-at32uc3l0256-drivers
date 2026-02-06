# AT32UC3L0256 Drivers

- Source and build configuration files to build a AT32UC3L0256 MCU drivers library w/ CMake
- The HAL implementation builds for both the MCU and on Windows for testing

## ASF_mock

- Not actual mocks- CppUMock is cleaner when there's no need for a lot of custom mocking behavior
- The drivers downloaded from Microchip Studio's ASF Wizard has assembly files, conditionally compiled headers, etc that only build w/ the AVR32 compiler
- We're going to implement/copy the bare minimum constants/function prototypes defined in the ASF library, and then use CppUMock for actual mocking

## Downloading AT32UC3L0256 Drivers

- TODO: 
  - add instructions for how to get these source files from Atmel/Microchip studio and migrate them over to this repo
