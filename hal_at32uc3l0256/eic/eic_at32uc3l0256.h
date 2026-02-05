/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : eic_at32uc3l0256.h                                    */
/*                                                                            */
/* Interface for AT32UC3L0256 implementation for external interrupt           */
/* controller HAL                                                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef EIC_AT32UC3L0256_H_
#define EIC_AT32UC3L0256_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
struct eic_handle;

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void init_eic_at32uc3l0256(void);
void deinit_eic_at32uc3l0256(void);
void set_external_callback_at32uc3l0256(const struct eic_handle *handle,
        void (*callback)(void));

#endif /* EIC_AT32UC3L0256_H_ */
