/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : gpio_mock.h                                           */
/*                                                                            */
/* Bare minimum interface/definitions from ASF library to get GPIO hal        */
/* implementation to build on Windows.                                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef GPIO_MOCK_H_
#define GPIO_MOCK_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
enum
{
    AVR32_PIN_PB11 = 43,
    AVR32_PIN_PB06 = 38,
    AVR32_PIN_PA22 = 22,
    AVR32_PIN_PB03 = 35,
    AVR32_PIN_PB02 = 34,
    AVR32_PIN_PB00 = 32,
    AVR32_PIN_PB04 = 36,
    AVR32_PIN_PB10 = 42,
    AVR32_PIN_PB01 = 33,
    AVR32_PIN_PA07 = 7,
    AVR32_PIN_PA21 = 21,
    AVR32_PIN_PA20 = 20,
    AVR32_PIN_PA04 = 4,
    AVR32_PIN_PA11 = 11,
};

enum
{
    GPIO_DIR_INPUT  = (0 << 0),
    GPIO_DIR_OUTPUT = (1 << 0),
    GPIO_INIT_LOW   = (0 << 1),
    GPIO_PULL_UP    = (1 << 2)
};

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void gpio_configure_pin(uint32_t pin, uint32_t flags);
bool gpio_get_pin_value(uint32_t pin);
void gpio_set_gpio_pin(uint32_t pin);
void gpio_clr_gpio_pin(uint32_t pin);

#endif /* GPIO_MOCK_H_ */
