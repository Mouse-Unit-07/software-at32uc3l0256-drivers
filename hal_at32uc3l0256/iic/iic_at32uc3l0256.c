/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : iic_at32uc3l0256.c                                    */
/*                                                                            */
/* AT32UC3L0256 implementation for internal interrupt controller HAL          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include "asf.h"
#include "iic_at32uc3l0256.h"

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
void init_iic_at32uc3l0256(void)
{
    INTC_init_interrupts();
}

void deinit_iic_at32uc3l0256(void)
{
    /* nothing to clear/reset */
}

void enable_global_interrupts_at32uc3l0256(void)
{
#ifndef WINDOWS_BUILD
cpu_irq_enable(); /* untestable macro */
#endif
}

void disable_global_interrupts_at32uc3l0256(void)
{
#ifndef WINDOWS_BUILD
cpu_irq_disable(); /* untestable macro */
#endif
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
/* none */
