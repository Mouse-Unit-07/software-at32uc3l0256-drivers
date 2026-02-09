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
struct eic_handle {
    uint32_t eic_index;
};

extern const struct eic_handle encoder_1_channel_a;
extern const struct eic_handle encoder_2_channel_a;
extern const struct eic_handle config_pushbutton;

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void init_eic_at32uc3l0256(void);
void deinit_eic_at32uc3l0256(void);
void set_external_callback_at32uc3l0256(const struct eic_handle *handle,
        void (*callback)(void));

#ifdef WINDOWS_BUILD /* ISRs exposed just when testing */
void encoder_1_channel_a_isr(void);
void encoder_2_channel_a_isr(void);
void config_pushbutton_isr(void);
#endif

#endif /* EIC_AT32UC3L0256_H_ */
