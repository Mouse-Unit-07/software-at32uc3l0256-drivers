/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : iic_hal_config.c                                      */
/*                                                                            */
/* AT32UC3L0256 implementation for internal interrupt controller HAL handler  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include "iic_hal.h"
#include "iic_at32uc3l0256.h"
#include "iic_hal_config.h"

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
const struct iic_hal_handler iic_handler = 
{
    .init_iic = init_iic_at32uc3l0256,
    .deinit_iic = deinit_iic_at32uc3l0256,
    .enable_global_interrupts = enable_global_interrupts_at32uc3l0256,
    .disable_global_interrupts = disable_global_interrupts_at32uc3l0256
};

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
const struct iic_hal_handler *get_iic_hal_handler(void)
{
    return &iic_handler;
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
/* none */
