/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : eic_hal_config.c                                      */
/*                                                                            */
/* AT32UC3L0256 implementation for external interrupt controller HAL handler  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include "eic_hal.h"
#include "eic_at32uc3l0256.h"
#include "eic_hal_config.h"

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
const struct eic_hal_handler eic_handler = 
{
    .init_eic = init_eic_at32uc3l0256,
    .deinit_eic = deinit_eic_at32uc3l0256,
    .set_external_callback = set_external_callback_at32uc3l0256
};

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
const struct eic_hal_handler *get_eic_hal_handler(void)
{
    return &eic_handler;
}

const struct eic_handle *get_motor_1_encoder_handle(void)
{
    return &motor_1_encoder;
}

const struct eic_handle *get_motor_2_encoder_handle(void)
{
    return &motor_2_encoder;
}

const struct eic_handle *get_config_pushbutton_handle(void)
{
    return &config_pushbutton;
}


/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
/* none */
