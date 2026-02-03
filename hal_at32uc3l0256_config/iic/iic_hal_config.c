/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : iic_hal_config.c                                      */
/*                                                                            */
/* AT32UC3L0256 Implementation for internal interrupt controller HAL handler  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include "internal_interrupt_controller_hal.h"
#include "asf.h"
#include "iic_at32uc3l0256.h"
#include "iic_hal_config.h"

/*----------------------------------------------------------------------------*/
/*                                 Debug Space                                */
/*----------------------------------------------------------------------------*/
/* keep empty */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
const struct iic_hal_handler iic_handler = 
{
    .init_internal_interrupt_controller = init_internal_interrupt_controller_at32uc3l0256,
    .deinit_internal_interrupt_controller = deinit_internal_interrupt_controller_at32uc3l0256,
    .enable_global_interrupts = enable_global_interrupts_at32uc3l0256,
    .disable_global_interrupts = disable_global_interrupts_at32uc3l0256
};

/*----------------------------------------------------------------------------*/
/*                         Interrupt Service Routines                         */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
/* none */

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
