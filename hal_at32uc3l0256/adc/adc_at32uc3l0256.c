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

enum
{
    ADC_COUNT = 4
};

const struct adc_handle *const adc_handles[ADC_COUNT] = {
    &ir_sensor_1,
    &ir_sensor_2,
    &ir_sensor_3,
    &ir_sensor_4
};

/* pin selection related globals */
/* need unsigned constants for struct/array initializers (no enums or variables) */
#define IR_SENSOR_1_PIN (AVR32_ADCIFB_AD_1_PIN)
#define IR_SENSOR_1_PIN_FUNCTION (AVR32_ADCIFB_AD_1_FUNCTION)
#define IR_SENSOR_1_CHANNEL_MASK (1u << 1u)

#define IR_SENSOR_2_PIN (AVR32_ADCIFB_AD_2_PIN)
#define IR_SENSOR_2_PIN_FUNCTION (AVR32_ADCIFB_AD_2_FUNCTION)
#define IR_SENSOR_2_CHANNEL_MASK (1u << 2u)

#define IR_SENSOR_3_PIN (AVR32_ADCIFB_AD_5_PIN)
#define IR_SENSOR_3_PIN_FUNCTION (AVR32_ADCIFB_AD_5_FUNCTION)
#define IR_SENSOR_3_CHANNEL_MASK (1u << 5u)

#define IR_SENSOR_4_PIN (AVR32_ADCIFB_AD_4_PIN)
#define IR_SENSOR_4_PIN_FUNCTION (AVR32_ADCIFB_AD_4_FUNCTION)
#define IR_SENSOR_4_CHANNEL_MASK (1u << 4u)

/*----------------------------------------------------------------------------*/
/*                               Public Handles                               */
/*----------------------------------------------------------------------------*/
const struct adc_handle ir_sensor_1 = {
    .channel_mask = IR_SENSOR_1_CHANNEL_MASK
};

const struct adc_handle ir_sensor_2 = {
    .channel_mask = IR_SENSOR_2_CHANNEL_MASK
};

const struct adc_handle ir_sensor_3 = {
    .channel_mask = IR_SENSOR_3_CHANNEL_MASK
};

const struct adc_handle ir_sensor_4 = {
    .channel_mask = IR_SENSOR_4_CHANNEL_MASK
};

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
static int32_t configure_adc_except_trigger(void);
static int32_t configure_adc_trigger(void);
static void disable_adc_channel(uint32_t channel_mask);

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
        adc_runtime_error("adc init: init_adc_pins() failed", asf_return_value);
        return;
    }

    if (configure_adc_except_trigger() != PASS) {
        adc_runtime_error("adc init: configure_adc_except_trigger() failed", FAIL);
        return;
    }

    if (configure_adc_trigger() != PASS) {
        adc_runtime_error("adc init: configure_adc_trigger() failed", FAIL);
        return;
    }

    for (uint32_t i = 0; i < ADC_COUNT; i++) {
        disable_adc_channel(adc_handles[i]->channel_mask);
    }
}

void deinit_adc_at32uc3l0256(void)
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
        {IR_SENSOR_1_PIN, IR_SENSOR_1_PIN_FUNCTION},
        {IR_SENSOR_2_PIN, IR_SENSOR_2_PIN_FUNCTION},
        {IR_SENSOR_3_PIN, IR_SENSOR_3_PIN_FUNCTION},
        {IR_SENSOR_4_PIN, IR_SENSOR_4_PIN_FUNCTION}
    };

    return gpio_enable_module(ADCIFB_GPIO_MAP,
                        sizeof(ADCIFB_GPIO_MAP) / sizeof(ADCIFB_GPIO_MAP[0]));
}

static int32_t configure_adc_except_trigger(void)
{
    const uint32_t ADC_CLK_FREQ_HZ = 1500000u;
    adcifb_opt_t adcifb_opt = {
        .resolution = AVR32_ADCIFB_ACR_RES_10BIT,
        .shtim  = 15, /* Channels Sample & Hold Time in [0,15] */
        .ratio_clkadcifb_clkadc = (sysclk_get_pba_hz() / ADC_CLK_FREQ_HZ),
        .startup = 3, /* Startup time [0,127]; Tstartup = startup * 8 * Tclk_adc */
                      /* (assuming Tstartup ~ 15us max) */
        .sleep_mode_enable = false
    };

    return adcifb_configure(&AVR32_ADCIFB, &adcifb_opt);
}

static int32_t configure_adc_trigger(void)
{
    return adcifb_configure_trigger(&AVR32_ADCIFB, AVR32_ADCIFB_TRGMOD_NT, 0);
}

static void disable_adc_channel(uint32_t channel_mask)
{
    adcifb_channels_disable(&AVR32_ADCIFB, channel_mask);
}
