/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : timer_counter_at32uc3l0256.h                          */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for timer counter HAL            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef TIMER_COUNTER_AT32UC3L0256_H_
#define TIMER_COUNTER_AT32UC3L0256_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void init_timer_counter_at32uc3l0256(void);
void deinit_timer_counter_at32uc3l0256(void);
uint32_t get_timer_count_at32uc3l0256(void);
void restart_timer_at32uc3l0256(void);

#ifdef WINDOWS_BUILD /* ISR exposed just when testing */
void tc_irq(void);
#endif

#endif /* TIMER_COUNTER_AT32UC3L0256_H_ */
