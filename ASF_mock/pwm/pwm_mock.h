/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : pwm_mock.h                                            */
/*                                                                            */
/* Bare minimum interface/definitions from ASF library to get pulse width     */
/* modulation hal implementation to build on Windows.                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef PWM_MOCK_H_
#define PWM_MOCK_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* ASF constants and struct definitions */
typedef struct {
	uint32_t pin;      /**< Module pin. */
	uint32_t function; /**< Module function. */
} gpio_map_t[];

enum
{
    AVR32_PWMA_28_PIN = 37,
    AVR32_PWMA_13_PIN = 13,
    AVR32_PWMA_31_PIN = 40,
    AVR32_PWMA_28_FUNCTION = 4,
    AVR32_PWMA_13_FUNCTION = 4,
    AVR32_PWMA_31_FUNCTION = 4
};

/* untestable static inline functions in ASF headers */
/* none so far */

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
uint32_t gpio_enable_module(const gpio_map_t gpiomap, uint32_t size);

#endif /* PWM_MOCK_H_ */
