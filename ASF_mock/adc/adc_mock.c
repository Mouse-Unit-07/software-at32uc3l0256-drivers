/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : adc_mock.c                                            */
/*                                                                            */
/* Empty implementations of functions to be mocked w/ CppUTest.               */
/* Needed for the config translation unit- compilation errors are thrown      */
/* when function pointers point to functions that are defined w/ calls to     */
/* functions that aren't defined.                                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include "adc_mock.h"

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
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
void sysclk_init(void)
{
    /* emtpy */
}

int32_t adcifb_configure(volatile avr32_adcifb_t *adcifb,
    const adcifb_opt_t *p_adcifb_opt)
{
    return 1;
}

int32_t adcifb_configure_trigger(volatile avr32_adcifb_t *adcifb,
    uint8_t trgmod, uint32_t trgper)
{
    return 1;
}

bool adcifb_is_ready(volatile avr32_adcifb_t *adcifb)
{
    return true;
}

bool adcifb_is_drdy(volatile avr32_adcifb_t *adcifb)
{
    return true;
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
/* none */
