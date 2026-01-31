/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : clock_at32uc3l0256.h                                  */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for clock HAL                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef CLOCK_AT32UC3L0256_H_
#define CLOCK_AT32UC3L0256_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* Below constants are exposed for testing- no need to use them */
enum
{
    DFLL_FCPU_PRESCALER = 2, /* F_CPU = (DFLL base) / 2^2 = 35MHz */
    DFLL_PBA_PRESCALER = 1, /* PBA = (DFLL base) / 2^1 = 70MHz */
    DFLL_PBB_PRESCALER = 1 /* PBB = (DFLL base) / 2^1 = 70MHz */
};

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void init_clock_at32uc3l0256(void);
void deinit_clock_at32uc3l0256(void);
void delay_ms_at32uc3l0256(uint32_t delay_time);
void delay_us_at32uc3l0256(uint32_t delay_time);

#endif /* CLOCK_AT32UC3L0256_H_ */
