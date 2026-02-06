/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : adc_hal_config.c                                      */
/*                                                                            */
/* AT32UC3L0256 implementation for analog to digital conversion HAL handler   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include "adc_hal.h"
#include "asf.h"
#include "adc_at32uc3l0256.h"
#include "adc_hal_config.h"

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
const struct adc_hal_handler adc_handler = 
{
    .init_adc = init_adc_at32uc3l0256,
    .deinit_adc = deinit_adc_at32uc3l0256,
    .read_adc_channel = read_adc_channel_at32uc3l0256
};

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
const struct adc_hal_handler *get_adc_hal_handler(void)
{
    return &adc_handler;
}

const struct adc_handle *get_ir_sensor_1_handle(void)
{
    return &ir_sensor_1;
}

const struct adc_handle *get_ir_sensor_2_handle(void)
{
    return &ir_sensor_2;
}

const struct adc_handle *get_ir_sensor_3_handle(void)
{
    return &ir_sensor_3;
}

const struct adc_handle *get_ir_sensor_4_handle(void)
{
    return &ir_sensor_4;
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
/* none */
