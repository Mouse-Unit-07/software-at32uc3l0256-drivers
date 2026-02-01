/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : timer_counter_mock.c                                  */
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
#include "timer_counter_mock.h"

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
int tc_init_waveform(volatile avr32_tc_t *tc, const tc_waveform_opt_t *opt)
{
    return 1;
}

int tc_write_rc(volatile avr32_tc_t *tc, unsigned int channel, unsigned short value)
{
    return 1;
}

int tc_configure_interrupts(volatile avr32_tc_t *tc, unsigned int channel, const tc_interrupt_t *bitfield)
{
    return 1;
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
/* none */
