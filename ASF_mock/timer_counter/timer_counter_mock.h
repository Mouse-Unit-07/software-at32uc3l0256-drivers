/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : timer_counter_mock.h                                  */
/*                                                                            */
/* Bare minimum interface/definitions from ASF library to get timer counter   */
/* hal implementation to build on Windows.                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef TIMER_COUNTER_MOCK_H_
#define TIMER_COUNTER_MOCK_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
typedef struct
{
    unsigned int channel       ;
    unsigned int bswtrg     : 2;
    unsigned int beevt      : 2;
    unsigned int bcpc       : 2;
    unsigned int bcpb       : 2;
    unsigned int aswtrg     : 2;
    unsigned int aeevt      : 2;
    unsigned int acpc       : 2;
    unsigned int acpa       : 2;
    unsigned int            : 1;
    unsigned int wavsel     : 2;
    unsigned int enetrg     : 1;
    unsigned int eevt       : 2;
    unsigned int eevtedg    : 2;
    unsigned int cpcdis     : 1;
    unsigned int cpcstop    : 1;
    unsigned int burst      : 2;
    unsigned int clki       : 1;
    unsigned int tcclks     : 3;
} tc_waveform_opt_t;

enum
{
    AVR32_TC_NONE = 0x00000000,
    TC_EVT_EFFECT_NOOP = AVR32_TC_NONE,
    AVR32_TC_WAVSEL_UP_AUTO = 0x00000002,
    TC_WAVEFORM_SEL_UP_MODE_RC_TRIGGER = AVR32_TC_WAVSEL_UP_AUTO,
    AVR32_TC_EEVTEDG_NO_EDGE = 0x00000000,
    TC_SEL_NO_EDGE = AVR32_TC_EEVTEDG_NO_EDGE,
    AVR32_TC_TCCLKS_TIMER_CLOCK3 = 0x00000002,
    TC_CLOCK_SOURCE_TC3 = AVR32_TC_TCCLKS_TIMER_CLOCK3
};

enum
{
    TC_INVALID_ARGUMENT = -1
};

enum
{
    AVR32_TC1_ADDRESS = 0xFFFF5C00,

};

typedef struct avr32_tc_ccr_t
{
    unsigned int                 :29;
    unsigned int swtrg           : 1;
    unsigned int clkdis          : 1;
    unsigned int clken           : 1;
} avr32_tc_ccr_t;

typedef union avr32_tc_cmr_t
{
  struct {
    unsigned int                 :12;
    unsigned int ldrb            : 2;
    unsigned int ldra            : 2;
    unsigned int wave            : 1;
    unsigned int cpctrg          : 1;
    unsigned int                 : 3;
    unsigned int abetrg          : 1;
    unsigned int etrgedg         : 2;
    unsigned int ldbdis          : 1;
    unsigned int ldbstop         : 1;
    unsigned int burst           : 2;
    unsigned int clki            : 1;
    unsigned int tcclks          : 3;
  } capture;
  struct {
    unsigned int bswtrg          : 2;
    unsigned int beevt           : 2;
    unsigned int bcpc            : 2;
    unsigned int bcpb            : 2;
    unsigned int aswtrg          : 2;
    unsigned int aeevt           : 2;
    unsigned int acpc            : 2;
    unsigned int acpa            : 2;
    unsigned int wave            : 1;
    unsigned int wavsel          : 2;
    unsigned int enetrg          : 1;
    unsigned int eevt            : 2;
    unsigned int eevtedg         : 2;
    unsigned int cpcdis          : 1;
    unsigned int cpcstop         : 1;
    unsigned int burst           : 2;
    unsigned int clki            : 1;
    unsigned int tcclks          : 3;
  } waveform;
} avr32_tc_cmr_t;

typedef struct avr32_tc_cv_t
{
    unsigned int                 :16;
    unsigned int cv              :16;
} avr32_tc_cv_t;

typedef struct avr32_tc_ra_t
{
    unsigned int                 :16;
    unsigned int ra              :16;
} avr32_tc_ra_t;

typedef struct avr32_tc_rb_t
{
    unsigned int                 :16;
    unsigned int rb              :16;
} avr32_tc_rb_t;

typedef struct avr32_tc_rc_t
{
    unsigned int                 :16;
    unsigned int rc              :16;
} avr32_tc_rc_t;

typedef struct avr32_tc_sr_t
{
    unsigned int                 :13;
    unsigned int mtiob           : 1;
    unsigned int mtioa           : 1;
    unsigned int clksta          : 1;
    unsigned int                 : 8;
    unsigned int etrgs           : 1;
    unsigned int ldrbs           : 1;
    unsigned int ldras           : 1;
    unsigned int cpcs            : 1;
    unsigned int cpbs            : 1;
    unsigned int cpas            : 1;
    unsigned int lovrs           : 1;
    unsigned int covfs           : 1;
} avr32_tc_sr_t;

typedef struct avr32_tc_ier_t
{
    unsigned int                 :24;
    unsigned int etrgs           : 1;
    unsigned int ldrbs           : 1;
    unsigned int ldras           : 1;
    unsigned int cpcs            : 1;
    unsigned int cpbs            : 1;
    unsigned int cpas            : 1;
    unsigned int lovrs           : 1;
    unsigned int covfs           : 1;
} avr32_tc_ier_t;

typedef struct avr32_tc_idr_t
{
    unsigned int                 :24;
    unsigned int etrgs           : 1;
    unsigned int ldrbs           : 1;
    unsigned int ldras           : 1;
    unsigned int cpcs            : 1;
    unsigned int cpbs            : 1;
    unsigned int cpas            : 1;
    unsigned int lovrs           : 1;
    unsigned int covfs           : 1;
} avr32_tc_idr_t;

typedef struct avr32_tc_imr_t
{
    unsigned int                 :24;
    unsigned int etrgs           : 1;
    unsigned int ldrbs           : 1;
    unsigned int ldras           : 1;
    unsigned int cpcs            : 1;
    unsigned int cpbs            : 1;
    unsigned int cpas            : 1;
    unsigned int lovrs           : 1;
    unsigned int covfs           : 1;
} avr32_tc_imr_t;

typedef struct avr32_tc_channel_t
{
  union {
          unsigned long                  ccr       ;//0x0000
          avr32_tc_ccr_t                 CCR       ;
  };
  union {
          unsigned long                  cmr       ;//0x0004
          avr32_tc_cmr_t                 CMR       ;
  };
          unsigned int                   :32       ;//0x0008
          unsigned int                   :32       ;//0x000c
  union {
    const unsigned long                  cv        ;//0x0010
    const avr32_tc_cv_t                  CV        ;
  };
  union {
          unsigned long                  ra        ;//0x0014
          avr32_tc_ra_t                  RA        ;
  };
  union {
          unsigned long                  rb        ;//0x0018
          avr32_tc_rb_t                  RB        ;
  };
  union {
          unsigned long                  rc        ;//0x001c
          avr32_tc_rc_t                  RC        ;
  };
  union {
    const unsigned long                  sr        ;//0x0020
    const avr32_tc_sr_t                  SR        ;
  };
  union {
          unsigned long                  ier       ;//0x0024
          avr32_tc_ier_t                 IER       ;
  };
  union {
          unsigned long                  idr       ;//0x0028
          avr32_tc_idr_t                 IDR       ;
  };
  union {
    const unsigned long                  imr       ;//0x002c
    const avr32_tc_imr_t                 IMR       ;
  };
          unsigned int                   :32       ;//0x0030
          unsigned int                   :32       ;//0x0034
          unsigned int                   :32       ;//0x0038
          unsigned int                   :32       ;//0x003c
} avr32_tc_channel_t;

typedef struct avr32_tc_bcr_t
{
    unsigned int                 :31;
    unsigned int sync            : 1;
} avr32_tc_bcr_t;

typedef struct avr32_tc_bmr_t
{
    unsigned int                 :26;
    unsigned int tc2xc2s         : 2;
    unsigned int tc1xc1s         : 2;
    unsigned int tc0xc0s         : 2;
} avr32_tc_bmr_t;

typedef struct avr32_tc_version_t
{
    unsigned int                 :12;
    unsigned int variant         : 4;
    unsigned int                 : 4;
    unsigned int version         :12;
} avr32_tc_version_t;

typedef struct avr32_tc_t
{
    avr32_tc_channel_t channel[3];
    union {
            unsigned long                  bcr       ;
            avr32_tc_bcr_t                 BCR       ;
    };
    union {
            unsigned long                  bmr       ;
            avr32_tc_bmr_t                 BMR       ;
    };
            unsigned int                   :32       ;
            unsigned int                   :32       ;
            unsigned int                   :32       ;
            unsigned int                   :32       ;
            unsigned int                   :32       ;
            unsigned int                   :32       ;
            unsigned int                   :32       ;
            unsigned int                   :32       ;
            unsigned int                   :32       ;
            unsigned int                   :32       ;
            unsigned int                   :32       ;
            unsigned int                   :32       ;
            unsigned int                   :32       ;
    union {
      const unsigned long                  version   ;
      const avr32_tc_version_t             VERSION   ;
    };
} avr32_tc_t;

#define AVR32_TC1    (*((volatile avr32_tc_t*)AVR32_TC1_ADDRESS))

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
int tc_init_waveform(volatile avr32_tc_t *tc, const tc_waveform_opt_t *opt);
int tc_write_rc(volatile avr32_tc_t *tc, unsigned int channel, unsigned short value);

#endif /* TIMER_COUNTER_MOCK_H_ */
