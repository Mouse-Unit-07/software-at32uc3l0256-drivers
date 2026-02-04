/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : adc_at32uc3l0256.c                                    */
/*                                                                            */
/* AT32UC3L0256 implementation for analog to digital conversion HAL           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include "asf.h"
#include "runtime_diagnostics.h"
#include "adc_at32uc3l0256.h"

/*----------------------------------------------------------------------------*/
/*                                 Debug Space                                */
/*----------------------------------------------------------------------------*/
/* keep empty */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
static bool adc_failed = false;

/*----------------------------------------------------------------------------*/
/*                         Interrupt Service Routines                         */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
static void reset_adc_flags(void);
static void adc_runtime_error(const char *fail_message, uint32_t fail_value);
static uint32_t init_adc_pins(void);

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
void init_adc_at32uc3l0256(void)
{
    reset_adc_flags();

    sysclk_init();

    uint32_t asf_return_value = GPIO_INVALID_ARGUMENT;

    asf_return_value = init_adc_pins();
    if (asf_return_value != GPIO_SUCCESS) {
        adc_runtime_error("adc init: gpio_enable_module() failed", asf_return_value);
        return;
    }
}

void deinit_adc_at32uc3l0256(void)
{

}

void enable_adc_channel_at32uc3l0256(const struct adc_handle *handle)
{

}

void disable_adc_channel_at32uc3l0256(const struct adc_handle *handle)
{

}

uint32_t read_adc_channel_at32uc3l0256(const struct adc_handle *handle)
{
    return 1;
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
static void reset_adc_flags(void)
{
    adc_failed = false;
}

static void adc_runtime_error(const char *fail_message, uint32_t fail_value)
{
    RUNTIME_ERROR(0, fail_message, fail_value);
    adc_failed = true;
}

static uint32_t init_adc_pins(void)
{
    const gpio_map_t ADCIFB_GPIO_MAP = {
        {AVR32_ADCIFB_AD_1_PIN, AVR32_ADCIFB_AD_1_FUNCTION}, /* IR 1*/
        {AVR32_ADCIFB_AD_2_PIN, AVR32_ADCIFB_AD_2_FUNCTION}, /* IR 2*/
        {AVR32_ADCIFB_AD_5_PIN, AVR32_ADCIFB_AD_5_FUNCTION}, /* IR 3*/
        {AVR32_ADCIFB_AD_4_PIN, AVR32_ADCIFB_AD_4_FUNCTION}  /* IR 4*/
    };

    return gpio_enable_module(ADCIFB_GPIO_MAP,
                        sizeof(ADCIFB_GPIO_MAP) / sizeof(ADCIFB_GPIO_MAP[0]));
}
