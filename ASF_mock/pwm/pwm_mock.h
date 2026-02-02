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

enum
{
    AVR32_SCIF_GCLK_PWMA = 3,
    AVR32_SCIF_GC_USES_CLK_PBA = 7
};

#define div_ceil(a, b)	(((a) + (b) - 1) / (b))

enum genclk_source {
	GENCLK_SRC_RCSYS        = 0,    //!< System RC oscillator
	GENCLK_SRC_OSC32K       = 1,    //!< 32 kHz oscillator
	GENCLK_SRC_DFLL         = 2,    //!< DFLL
	GENCLK_SRC_OSC0         = 3,    //!< Oscillator 0
	GENCLK_SRC_RC120M       = 4,    //!< 120 MHz RC oscillator
	GENCLK_SRC_CLK_CPU      = 5,    //!< CPU clock
	GENCLK_SRC_CLK_HSB      = 6,    //!< High Speed Bus clock
	GENCLK_SRC_CLK_PBA      = 7,    //!< Peripheral Bus A clock
	GENCLK_SRC_CLK_PBB      = 8,    //!< Peripheral Bus B clock
	GENCLK_SRC_RC32K        = 9,    //!< 32 kHz RC oscillator
	GENCLK_SRC_CLK_1K       = 11,   //!< 1 kHz output from OSC32K

#if ( UC3L0128 || UC3L0256 || UC3L3_L4 )
	GENCLK_SRC_PLL0         = 12    //!< PLL0
#endif
};

/* untestable static inline functions in ASF headers */
static inline uint32_t sysclk_get_pba_hz(void) { return 1; }
static inline void genclk_enable_config(unsigned int id, enum genclk_source src, unsigned int divider) {}

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
uint32_t gpio_enable_module(const gpio_map_t gpiomap, uint32_t size);

#endif /* PWM_MOCK_H_ */
