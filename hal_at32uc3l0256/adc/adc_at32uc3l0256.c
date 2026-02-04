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
#include "adc_at32uc3l0256.h"

/*----------------------------------------------------------------------------*/
/*                                 Debug Space                                */
/*----------------------------------------------------------------------------*/
/* keep empty */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Interrupt Service Routines                         */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
static uint32_t init_adc_pins(void);

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
void init_adc_at32uc3l0256(void)
{
    sysclk_init();
    
    init_adc_pins();
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
