/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : clock_hal_config.h                                    */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for clock HAL handler            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef CLOCK_HAL_CONFIG_H_
#define CLOCK_HAL_CONFIG_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
const struct clock_hal_handler *get_clock_hal_handler(void);

#endif /* CLOCK_HAL_CONFIG_H_ */
