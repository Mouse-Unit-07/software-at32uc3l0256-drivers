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
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
void init_eic_at32uc3l0256(void)
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
/* none */
