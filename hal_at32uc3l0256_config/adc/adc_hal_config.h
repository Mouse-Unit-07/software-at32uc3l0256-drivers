/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : adc_hal_config.h                                      */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for analog to digital conversion */
/* HAL handler                                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef ADC_HAL_CONFIG_H_
#define ADC_HAL_CONFIG_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
const struct adc_hal_handler *get_adc_hal_handler(void);
const struct adc_handle *get_ir_sensor_1_handle(void);
const struct adc_handle *get_ir_sensor_2_handle(void);
const struct adc_handle *get_ir_sensor_3_handle(void);
const struct adc_handle *get_ir_sensor_4_handle(void);

#endif /* ADC_HAL_CONFIG_H_ */
