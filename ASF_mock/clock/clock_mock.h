/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : clock_mock.h                                          */
/*                                                                            */
/* Bare minimum interface/definitions to get clock hal implementation to      */
/* build on Windows                                                           */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef CLOCK_MOCK_H_
#define CLOCK_MOCK_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
/* ASF constants and struct definitions */
enum
{
    AVR32_PM_MCSEL_DFLL0 = 2,
    SYSCLK_SRC_DFLL = AVR32_PM_MCSEL_DFLL0
};

enum
{
    OSC_ID_RC120M = 3
}; 

struct genclk_config {
    uint32_t ctrl;
};

struct dfll_config {
    struct genclk_config    ref_cfg;        //!< Reference clock
    uint32_t                conf;           //!< DFLLnCONF
    uint32_t                mul;            //!< DFLLnMUL
    uint32_t                step;           //!< DFLLnSTEP
    uint32_t                ssg;            //!< DFLLnSSG
};

/* untestable static inline functions in ASF headers */
static inline void dfll_config_init_open_loop_mode(struct dfll_config *cfg) {}
static inline void dfll_config_tune_for_target_hz(struct dfll_config *cfg, 
                                                    uint32_t target_hz) {}
static inline void osc_disable(uint8_t id) {}

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
void dfll_enable_open_loop(const struct dfll_config *cfg, unsigned int dfll_id);
void sysclk_set_prescalers(unsigned int cpu_shift,
                            unsigned int pba_shift, unsigned int pbb_shift);
void sysclk_set_source(uint_fast8_t src);

#endif /* CLOCK_MOCK_H_ */
