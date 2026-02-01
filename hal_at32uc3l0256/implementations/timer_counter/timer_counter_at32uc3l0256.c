/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : timer_counter_at32uc3l0256.c                          */
/*                                                                            */
/* AT32UC3L0256 implementation for timer counter HAL                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include "asf.h"
#include "runtime_diagnostics.h"
#include "clock_at32uc3l0256.h"
#include "timer_counter_at32uc3l0256.h"

/*----------------------------------------------------------------------------*/
/*                                 Debug Space                                */
/*----------------------------------------------------------------------------*/
/* keep empty */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
bool timer_counter_failed = false;

enum
{
    TIMER_COUNTER_CHANNEL = 0
};

enum
{
    TIMER_COUNTER_IRQ = AVR32_TC1_IRQ0,
    TIMER_COUNTER_IRQ_PRIORITY = AVR32_INTC_INT0
};

/* Can't define AVR32_TC1 w/ an enum- resolves to a macro w/ a custom type */
#define TIMER_COUNTER_BASE_ADDRESS (&AVR32_TC1)

/*----------------------------------------------------------------------------*/
/*                         Interrupt Service Routines                         */
/*----------------------------------------------------------------------------*/
#ifndef WINDOWS_BUILD /* need this ISR to build for testing */
__attribute__((__interrupt__))
#endif
static void tc_irq(void)
{
    /* empty for now */
}

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
void tc_runtime_error(const char *fail_message, uint32_t fail_value);
int call_asf_tc_init_waveform(void);
int call_asf_tc_write_rc(void);
int call_asf_tc_configure_interrupts(void);
int call_asf_tc_start(void);

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
void init_timer_counter_at32uc3l0256(void)
{
    int asf_return_value = 0;

    asf_return_value = call_asf_tc_init_waveform();
    if (asf_return_value == TC_INVALID_ARGUMENT) {
        tc_runtime_error("tc_init_waveform call failed", TC_INVALID_ARGUMENT);
        return;
    }

    asf_return_value = call_asf_tc_write_rc();
    if (asf_return_value == TC_INVALID_ARGUMENT) {
        tc_runtime_error("tc_write_rc call failed", TC_INVALID_ARGUMENT);
        return;
    }

    asf_return_value = call_asf_tc_configure_interrupts();
    if (asf_return_value == TC_INVALID_ARGUMENT) {
        tc_runtime_error("tc_configure_interrupts call failed", TC_INVALID_ARGUMENT);
        return;
    }

    asf_return_value = call_asf_tc_start();
    if (asf_return_value == TC_INVALID_ARGUMENT) {
        tc_runtime_error("tc_start call failed", TC_INVALID_ARGUMENT);
        return;
    }

    sysclk_enable_peripheral_clock(TIMER_COUNTER_BASE_ADDRESS);
    
#ifndef WINDOWS_BUILD
    /* can't build for testing- takes an AVR32 defined type as a parameter */
    INTC_register_interrupt(&tc_irq, TIMER_COUNTER_IRQ, TIMER_COUNTER_IRQ_PRIORITY);
#endif
}

void deinit_timer_counter_at32uc3l0256(void)
{

}

uint32_t get_timer_count_at32uc3l0256(void)
{
    return 0;
}

void restart_timer_at32uc3l0256(void)
{

}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
void tc_runtime_error(const char *fail_message, uint32_t fail_value)
{
    RUNTIME_ERROR(0, fail_message, fail_value);
    timer_counter_failed = true;
}

int call_asf_tc_init_waveform(void)
{
    /* Options for waveform generation */
    static const tc_waveform_opt_t waveform_opt = {
        .channel  = TIMER_COUNTER_CHANNEL,           /* Channel selection */
        .bswtrg   = TC_EVT_EFFECT_NOOP,                 /* Software trigger effect on TIOB */
        .beevt    = TC_EVT_EFFECT_NOOP,                 /* External event effect on TIOB */
        .bcpc     = TC_EVT_EFFECT_NOOP,                 /* RC compare effect on TIOB */
        .bcpb     = TC_EVT_EFFECT_NOOP,                 /* RB compare effect on TIOB */
        .aswtrg   = TC_EVT_EFFECT_NOOP,                 /* Software trigger effect on TIOA */
        .aeevt    = TC_EVT_EFFECT_NOOP,                 /* External event effect on TIOA */
        .acpc     = TC_EVT_EFFECT_NOOP,                 /* RC compare effect on TIOA */
        .acpa     = TC_EVT_EFFECT_NOOP,                 /* RA compare effect on TIOA (none, set and clear) */
        .wavsel   = TC_WAVEFORM_SEL_UP_MODE_RC_TRIGGER, /* Up mode w/ auto trigger(reset) on RC compare */
        .enetrg   = false,                              /* External event trigger enable */
        .eevt     = 0,                                  /* External event selection */
        .eevtedg  = TC_SEL_NO_EDGE,                     /* External event edge selection */
        .cpcdis   = false,                              /* Counter disable when RC compare */
        .cpcstop  = false,                              /* Counter clock stopped with RC compare */
        .burst    = false,                              /* Burst signal selection */
        .clki     = false,                              /* Clock inversion */ 
        .tcclks   = TC_CLOCK_SOURCE_TC3                 /* Internal source clock 3, connected to fPBA / 8 */
    };

    return tc_init_waveform(TIMER_COUNTER_BASE_ADDRESS, &waveform_opt);
}

int call_asf_tc_write_rc(void)
{
    /* Set the compare triggers */
    /* We configure it to count every 1 milliseconds */
    /* We want: (1 / (fPBA / 8)) * RC = 1 ms; RC = (fPBA / 8) / 1000 */
    /* to get an interrupt every 10 ms */
    return tc_write_rc(
        TIMER_COUNTER_BASE_ADDRESS, 
        TIMER_COUNTER_CHANNEL, 
        PBA_CLK_FREQ_HZ / 8 / 1000 * 4
    );
}

int call_asf_tc_configure_interrupts(void)
{
    /* Options for enabling TC interrupts */
    static const tc_interrupt_t tc_interrupt = {
        .etrgs = 0,
        .ldrbs = 0,
        .ldras = 0,
        .cpcs  = 1, /* Enable interrupt on RC compare alone */
        .cpbs  = 0,
        .cpas  = 0,
        .lovrs = 0,
        .covfs = 0
    };

    return tc_configure_interrupts(
        TIMER_COUNTER_BASE_ADDRESS, 
        TIMER_COUNTER_CHANNEL, 
        &tc_interrupt
    );
}

int call_asf_tc_start(void)
{
    return tc_start(
        TIMER_COUNTER_BASE_ADDRESS,
        TIMER_COUNTER_CHANNEL
    );
}
