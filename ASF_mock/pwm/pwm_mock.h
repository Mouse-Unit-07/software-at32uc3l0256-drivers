/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : pwm_mock.h                                            */
/*                                                                            */
/* Bare minimum interface/definitions from ASF library to get pulse width     */
/* modulation hal implementation to build on Windows.                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef PWM_MOCK_H_
#define PWM_MOCK_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* ASF constants and struct definitions */
enum
{
    AVR32_PWMA_28_PIN = 37,
    AVR32_PWMA_13_PIN = 13,
    AVR32_PWMA_31_PIN = 40,
    AVR32_PWMA_28_FUNCTION = 4,
    AVR32_PWMA_13_FUNCTION = 4,
    AVR32_PWMA_31_FUNCTION = 4
};

enum
{
    AVR32_SCIF_GCLK_PWMA = 3,
    AVR32_SCIF_GC_USES_CLK_PBA = 7
};

#define div_ceil(a, b)    (((a) + (b) - 1) / (b))

enum genclk_source {
    GENCLK_SRC_RCSYS        = 0,    //!< System RC oscillator
    GENCLK_SRC_OSC32K       = 1,    //!< 32 kHz oscillator
    GENCLK_SRC_DFLL         = 2,    //!< DFLL
    GENCLK_SRC_OSC0         = 3,    //!< Oscillator 0
    GENCLK_SRC_RC120M       = 4,    //!< 120 MHz RC oscillator
    GENCLK_SRC_CLK_CPU      = 5,    //!< CPU clock
    GENCLK_SRC_CLK_HSB      = 6,    //!< High Speed Bus clock
    GENCLK_SRC_CLK_PBA      = 7,    //!< Peripheral Bus A clock
    GENCLK_SRC_CLK_PBB      = 8,    //!< Peripheral Bus B clock
    GENCLK_SRC_RC32K        = 9,    //!< 32 kHz RC oscillator
    GENCLK_SRC_CLK_1K       = 11,   //!< 1 kHz output from OSC32K

#if ( UC3L0128 || UC3L0256 || UC3L3_L4 )
    GENCLK_SRC_PLL0         = 12    //!< PLL0
#endif
};

typedef struct avr32_pwma_chgroup_t {
          unsigned long                   ischset    ; // 0x0000
          unsigned long                   cherr      ; // 0x0004
          unsigned long                   cheer      ; // 0x0008
          unsigned long                   cwg        ; // 0x000c
} avr32_pwma_chgroup_t;

typedef struct avr32_pwma_cr_t {
       unsigned int                : 7;
       unsigned int spread         : 9;
       unsigned int top            : 8;
       unsigned int                : 6;
       unsigned int tclr           : 1;
       unsigned int en             : 1;
} avr32_pwma_cr_t;

typedef struct avr32_pwma_isduty_t {
       unsigned int                :20;
       unsigned int duty           :12;
} avr32_pwma_isduty_t;

typedef struct avr32_pwma_imduty_t {
       unsigned int duty3          : 8;
       unsigned int duty2          : 8;
       unsigned int duty1          : 8;
       unsigned int duty0          : 8;
} avr32_pwma_imduty_t;

typedef struct avr32_pwma_imchsel_t {
       unsigned int sel3           : 8;
       unsigned int sel2           : 8;
       unsigned int sel1           : 8;
       unsigned int sel0           : 8;
} avr32_pwma_imchsel_t;

typedef struct avr32_pwma_ier_t {
       unsigned int                :29;
       unsigned int ready          : 1;
       unsigned int                : 1;
       unsigned int tofl           : 1;
} avr32_pwma_ier_t;

typedef struct avr32_pwma_idr_t {
       unsigned int                :29;
       unsigned int ready          : 1;
       unsigned int                : 1;
       unsigned int tofl           : 1;
} avr32_pwma_idr_t;

typedef struct avr32_pwma_imr_t {
       unsigned int                :29;
       unsigned int ready          : 1;
       unsigned int                : 1;
       unsigned int tofl           : 1;
} avr32_pwma_imr_t;

typedef struct avr32_pwma_sr_t {
       unsigned int                :28;
       unsigned int busy           : 1;
       unsigned int ready          : 1;
       unsigned int                : 1;
       unsigned int tofl           : 1;
} avr32_pwma_sr_t;

typedef struct avr32_pwma_scr_t {
       unsigned int                :29;
       unsigned int ready          : 1;
       unsigned int                : 1;
       unsigned int tofl           : 1;
} avr32_pwma_scr_t;

typedef struct avr32_pwma_parameter_t {
       unsigned int                :24;
       unsigned int channels       : 8;
} avr32_pwma_parameter_t;

typedef struct avr32_pwma_version_t {
       unsigned int                :12;
       unsigned int variant        : 4;
       unsigned int                : 4;
       unsigned int version        :12;
} avr32_pwma_version_t;

typedef struct avr32_pwma_tvr_t {
       unsigned int                :20;
       unsigned int top            :12;
} avr32_pwma_tvr_t;

typedef struct avr32_pwma_duty0_t {
       unsigned int                :20;
       unsigned int duty           :12;
} avr32_pwma_duty0_t;

typedef struct avr32_pwma_duty1_t {
       unsigned int                :20;
       unsigned int duty           :12;
} avr32_pwma_duty1_t;

typedef struct avr32_pwma_duty2_t {
       unsigned int                :20;
       unsigned int duty           :12;
} avr32_pwma_duty2_t;

typedef struct avr32_pwma_duty3_t {
       unsigned int                :20;
       unsigned int duty           :12;
} avr32_pwma_duty3_t;

typedef struct avr32_pwma_t {
   union {
          unsigned long                   cr         ; // 0x0000
          avr32_pwma_cr_t                 CR         ;
   };
   union {
          unsigned long                   isduty     ; // 0x0004
          avr32_pwma_isduty_t             ISDUTY     ;
   };
   union {
          unsigned long                   imduty     ; // 0x0008
          avr32_pwma_imduty_t             IMDUTY     ;
   };
   union {
          unsigned long                   imchsel    ; // 0x000c
          avr32_pwma_imchsel_t            IMCHSEL    ;
   };
   union {
          unsigned long                   ier        ; // 0x0010
          avr32_pwma_ier_t                IER        ;
   };
   union {
          unsigned long                   idr        ; // 0x0014
          avr32_pwma_idr_t                IDR        ;
   };
   union {
    const unsigned long                   imr        ; // 0x0018
    const avr32_pwma_imr_t                IMR        ;
   };
   union {
    const unsigned long                   sr         ; // 0x001c
    const avr32_pwma_sr_t                 SR         ;
   };
   union {
          unsigned long                   scr        ; // 0x0020
          avr32_pwma_scr_t                SCR        ;
   };
   union {
    const unsigned long                   parameter  ; // 0x0024
    const avr32_pwma_parameter_t          PARAMETER  ;
   };
   union {
    const unsigned long                   version    ; // 0x0028
    const avr32_pwma_version_t            VERSION    ;
   };
   union {
          unsigned long                   tvr        ; // 0x002c
          avr32_pwma_tvr_t                TVR        ;
   };
   avr32_pwma_chgroup_t chgroup[5]                   ; // 0x0030
   union {
          unsigned long                   duty0      ; // 0x0080
          avr32_pwma_duty0_t              DUTY0      ;
   };
   union {
          unsigned long                   duty1      ; // 0x0084
          avr32_pwma_duty1_t              DUTY1      ;
   };
   union {
          unsigned long                   duty2      ; // 0x0088
          avr32_pwma_duty2_t              DUTY2      ;
   };
   union {
          unsigned long                   duty3      ; // 0x008c
          avr32_pwma_duty3_t              DUTY3      ;
   };
} avr32_pwma_t;

enum
{
    AVR32_PWMA_ADDRESS = 0xFFFF5400
};

/* this macro can't be an enum */
#define AVR32_PWMA    (*((volatile avr32_pwma_t*)AVR32_PWMA_ADDRESS))

enum
{
    PWMA_MAXIMUM_TOP = 0xff
};

/* untestable static inline functions in ASF headers */
static inline void genclk_enable_config(unsigned int id, enum genclk_source src, unsigned int divider) {}

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
bool pwma_config_enable(volatile avr32_pwma_t *pwma, uint32_t pwma_freq_hz,
                        uint32_t gclk_freq_hz, uint16_t spread);
bool pwma_set_multiple_values(volatile avr32_pwma_t *pwma, uint32_t channel_mask,
                        uint16_t *channel_duty_cycles);
bool pwma_write_top_value(volatile avr32_pwma_t *pwma, uint16_t top_value);

#endif /* PWM_MOCK_H_ */
