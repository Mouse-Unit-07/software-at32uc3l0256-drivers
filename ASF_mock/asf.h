/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : asf.h                                                 */
/*                                                                            */
/* Header to include all other bare minimum interfaces/definitions to get     */
/* hal implementations to build on Windows                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef ASF_H_
#define ASF_H_

#include "clock/clock_mock.h"
#include "gpio/gpio_mock.h"
#include "timer_counter/timer_counter_mock.h"
#include "pwm/pwm_mock.h"
#include "iic/iic_mock.h"
#include "adc/adc_mock.h"

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
enum
{
    PASS = 0,
    FAIL = 1
};

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
/* none */

#endif /* ASF_H_ */
