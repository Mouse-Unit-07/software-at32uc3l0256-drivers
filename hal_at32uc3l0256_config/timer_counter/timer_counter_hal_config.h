/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : timer_counter_hal_config.h                            */
/*                                                                            */
/* Interface for AT32UC3L0256 Implementation for timer counter HAL handler    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef TIMER_COUNTER_HAL_CONFIG_H_
#define TIMER_COUNTER_HAL_CONFIG_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
const struct tc_hal_handler *get_tc_hal_handler(void);

#endif /* TIMER_COUNTER_HAL_CONFIG_H_ */
