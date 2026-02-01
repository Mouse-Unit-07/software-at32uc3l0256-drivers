/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : gpio_at32uc3l0256.h                                   */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for GPIO HAL                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef GPIO_AT32UC3L0256_H_
#define GPIO_AT32UC3L0256_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
struct gpio_handle;

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void init_gpio_at32uc3l0256(void);
void deinit_gpio_at32uc3l0256(void);
uint32_t read_gpio_pin_at32uc3l0256(const struct gpio_handle *handle);
void write_gpio_pin_at32uc3l0256(const struct gpio_handle *handle);
void toggle_gpio_pin_at32uc3l0256(const struct gpio_handle *handle);

#endif /* GPIO_AT32UC3L0256_H_ */
