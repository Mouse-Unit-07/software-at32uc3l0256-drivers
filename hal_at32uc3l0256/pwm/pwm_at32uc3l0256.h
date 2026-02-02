/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : pwm_at32uc3l0256.h                                    */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for pulse width modulation HAL   */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef PWM_AT32UC3L0256_H_
#define PWM_AT32UC3L0256_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
struct pwm_handle {
    uint32_t index;
};

extern const struct pwm_handle wheel_motor_1;
extern const struct pwm_handle wheel_motor_2;
extern const struct pwm_handle vacuum_motor;

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void init_pwm_at32uc3l0256(void);
void deinit_pwm_at32uc3l0256(void);
void set_pwm_duty_cycle_percent_at32uc3l0256(struct pwm_handle *handle, uint32_t percent);

#endif /* PWM_AT32UC3L0256_H_ */
