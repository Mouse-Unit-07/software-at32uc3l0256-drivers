/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : eic_at32uc3l0256.c                                    */
/*                                                                            */
/* AT32UC3L0256 implementation for external interrupt controller HAL          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include "asf.h"
#include "eic_at32uc3l0256.h"

/*----------------------------------------------------------------------------*/
/*                                 Debug Space                                */
/*----------------------------------------------------------------------------*/
/* keep empty */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
/* pin selection related globals */
/* need unsigned constants for struct/array initializers (no enums or variables) */
#define MOTOR_1_ENCODER_PIN (AVR32_EIC_EXTINT_1_1_PIN)
#define MOTOR_1_ENCODER_PIN_FUNCTION (AVR32_EIC_EXTINT_1_1_FUNCTION)
static const uint32_t MOTOR_1_ENCODER_EIC_LINE = AVR32_EIC_INT1;

#define MOTOR_2_ENCODER_PIN (AVR32_EIC_EXTINT_3_1_PIN)
#define MOTOR_2_ENCODER_PIN_FUNCTION (AVR32_EIC_EXTINT_3_1_FUNCTION)
static const uint32_t MOTOR_2_ENCODER_EIC_LINE = AVR32_EIC_INT3;

#define CONFIG_PUSHBUTTON_PIN (6u) /* can't find ASF mask */
#define CONFIG_PUSHBUTTON_PIN_FUNCTION (5u) /* can't find ASF mask */
static const uint32_t CONFIG_PUSHBUTTON_EIC_LINE = AVR32_EIC_INT2;

#ifndef WINDOWS_BUILD /* not needed for testing */
static const uint32_t CONFIG_PUSHBUTTON_EIC_IRQ_LINE = AVR32_EIC_IRQ_2;
static const uint32_t MOTOR_2_ENCODER_EIC_IRQ_LINE = AVR32_EIC_IRQ_3;
static const uint32_t MOTOR_1_ENCODER_EIC_IRQ_LINE = AVR32_EIC_IRQ_1;
#endif

/*----------------------------------------------------------------------------*/
/*                         Interrupt Service Routines                         */
/*----------------------------------------------------------------------------*/
#ifndef WINDOWS_BUILD /* need this ISR to build for testing */
__attribute__((__interrupt__))
#endif
void motor_1_encoder_isr(void)
{
    eic_clear_interrupt_line(&AVR32_EIC, MOTOR_1_ENCODER_EIC_LINE);
}

#ifndef WINDOWS_BUILD /* need this ISR to build for testing */
__attribute__((__interrupt__))
#endif
void motor_2_encoder_isr(void)
{
    eic_clear_interrupt_line(&AVR32_EIC, MOTOR_2_ENCODER_EIC_LINE);
}

#ifndef WINDOWS_BUILD /* need this ISR to build for testing */
__attribute__((__interrupt__))
#endif
void config_pushbutton_isr(void)
{
    eic_clear_interrupt_line(&AVR32_EIC, CONFIG_PUSHBUTTON_EIC_LINE);
}

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
void init_eic_pins(void);
void configure_eic(void);

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
void init_eic_at32uc3l0256(void)
{
    init_eic_pins();
    configure_eic();
}

void deinit_eic_at32uc3l0256(void)
{

}

void set_external_callback_at32uc3l0256(const struct eic_handle *handle,
        void (*callback)(void))
{
    
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
void init_eic_pins(void)
{
    static const gpio_map_t EIC_ENCODER_MAP = {
        {MOTOR_1_ENCODER_PIN, MOTOR_1_ENCODER_PIN_FUNCTION},
        {MOTOR_2_ENCODER_PIN, MOTOR_2_ENCODER_PIN_FUNCTION}
    };
    gpio_enable_module(EIC_ENCODER_MAP,
        sizeof(EIC_ENCODER_MAP) / sizeof(EIC_ENCODER_MAP[0]));
    
    static const gpio_map_t EIC_PUSHBUTTON_MAP = {
        {CONFIG_PUSHBUTTON_PIN, CONFIG_PUSHBUTTON_PIN_FUNCTION}
    };
    gpio_enable_module(EIC_PUSHBUTTON_MAP, 
        sizeof(EIC_PUSHBUTTON_MAP) / sizeof(EIC_PUSHBUTTON_MAP[0]));
}

void configure_eic(void)
{
    eic_options_t eic_encoder_options[2] = {{0}};
    eic_options_t eic_pushbutton_options[1] = {{0}};

    const unsigned char MOTOR_1_ENCODER_EIC_MODE = EIC_MODE_EDGE_TRIGGERED;
    const unsigned char MOTOR_1_ENCODER_EIC_EDGE = AVR32_EIC_RISING_EDGE;
    const unsigned char MOTOR_1_ENCODER_EIC_SYNC = EIC_SYNCH_MODE;

    const unsigned char MOTOR_2_ENCODER_EIC_MODE = EIC_MODE_EDGE_TRIGGERED;
    const unsigned char MOTOR_2_ENCODER_EIC_EDGE = AVR32_EIC_RISING_EDGE;
    const unsigned char MOTOR_2_ENCODER_EIC_SYNC = EIC_SYNCH_MODE;

    const unsigned char CONFIG_PUSHBUTTON_EIC_MODE = EIC_MODE_EDGE_TRIGGERED;
    const unsigned char CONFIG_PUSHBUTTON_EIC_EDGE = AVR32_EIC_FALLING_EDGE;
    const unsigned char CONFIG_PUSHBUTTON_EIC_SYNC = EIC_SYNCH_MODE;

    /* motor 1 */
    eic_encoder_options[0].eic_mode  = MOTOR_1_ENCODER_EIC_MODE;
    eic_encoder_options[0].eic_edge  = MOTOR_1_ENCODER_EIC_EDGE;
    eic_encoder_options[0].eic_async = MOTOR_1_ENCODER_EIC_SYNC;
    eic_encoder_options[0].eic_line  = MOTOR_1_ENCODER_EIC_LINE;
    
    /* motor 2 */
    eic_encoder_options[1].eic_mode  = MOTOR_2_ENCODER_EIC_MODE;
    eic_encoder_options[1].eic_edge  = MOTOR_2_ENCODER_EIC_EDGE;
    eic_encoder_options[1].eic_async = MOTOR_2_ENCODER_EIC_SYNC;
    eic_encoder_options[1].eic_line  = MOTOR_2_ENCODER_EIC_LINE;

    eic_pushbutton_options[0].eic_mode  = CONFIG_PUSHBUTTON_EIC_MODE;
    eic_pushbutton_options[0].eic_edge  = CONFIG_PUSHBUTTON_EIC_EDGE;
    eic_pushbutton_options[0].eic_async = CONFIG_PUSHBUTTON_EIC_SYNC;
    eic_pushbutton_options[0].eic_line  = CONFIG_PUSHBUTTON_EIC_LINE;

#ifndef WINDOWS_BUILD /* can't test- AVR32 defined type parameter */
    const uint32_t INTC_LEVEL = AVR32_INTC_INT3;
    INTC_register_interrupt(&motor_1_encoder_isr,
        MOTOR_1_ENCODER_EIC_IRQ_LINE, INTC_LEVEL);
    INTC_register_interrupt(&motor_2_encoder_isr,
        MOTOR_2_ENCODER_EIC_IRQ_LINE, INTC_LEVEL);
    INTC_register_interrupt(&config_pushbutton_isr,
        CONFIG_PUSHBUTTON_EIC_IRQ_LINE, INTC_LEVEL);
#endif

    eic_init(&AVR32_EIC, eic_encoder_options, 2);
    eic_init(&AVR32_EIC, eic_pushbutton_options, 1);

    eic_enable_lines(&AVR32_EIC,
        (1 << eic_encoder_options[1].eic_line) | (1 << eic_encoder_options[0].eic_line));
    eic_enable_lines(&AVR32_EIC, (1 << eic_pushbutton_options[0].eic_line));

    eic_enable_interrupt_lines(&AVR32_EIC,
        (1 << eic_encoder_options[1].eic_line) | (1 << eic_encoder_options[0].eic_line));
    eic_enable_interrupt_lines(&AVR32_EIC, (1 << eic_pushbutton_options[0].eic_line));
}