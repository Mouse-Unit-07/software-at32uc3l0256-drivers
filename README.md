# AT32UC3L0256 Drivers

- Source and build configuration files to build a AT32UC3L0256 MCU drivers library w/ CMake

## Downloading AT32UC3L0256 Drivers

- TODO: 
  - add instructions for how to get these source files from Atmel/Microchip studio and migrate them over to this repo
  - add notes about how this repo doesn't have tests

## ASF_mock

- The drivers downloaded from Microchip Studio's ASF Wizard has assembly files, conditionally compiled headers, etc that only build w/ the AVR32 compiler
- We're going to implement/copy the bare minimum constants/function prototypes defined in the ASF library, and then use CppUMock for actual mocking
