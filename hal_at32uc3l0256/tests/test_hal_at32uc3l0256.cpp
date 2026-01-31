/*================================ FILE INFO =================================*/
/* Filename           : test_hal_at32uc3l0256.cpp                             */
/*                                                                            */
/* Test implementation for hal_at32uc3l0256 library                           */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/

extern "C" {
#include <stdint.h>
#include "clock_at32uc3l0256.h"
}

#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

/*============================================================================*/
/*                             Public Definitions                             */
/*============================================================================*/
enum
{
    DFLL_FCPU_PRESCALER = 2, /* F_CPU = (DFLL base) / 2^2 = 35MHz */
    DFLL_PBA_PRESCALER = 1, /* PBA = (DFLL base) / 2^1 = 70MHz */
    DFLL_PBB_PRESCALER = 1 /* PBB = (DFLL base) / 2^1 = 70MHz */
};

/*============================================================================*/
/*                            Mock Implementations                            */
/*============================================================================*/
extern "C"
{
/* Clock */
void dfll_enable_open_loop(const struct dfll_config *cfg, unsigned int dfll_id)
{
    CHECK(cfg != NULL);
    mock().actualCall("dfll_enable_open_loop")
        .withUnsignedIntParameter("dfll_id", dfll_id);
}

void sysclk_set_prescalers(unsigned int cpu_shift,
                            unsigned int pba_shift, unsigned int pbb_shift)
{
    mock().actualCall("sysclk_set_prescalers")
        .withUnsignedIntParameter("cpu_shift", cpu_shift)
        .withUnsignedIntParameter("pba_shift", pba_shift)
        .withUnsignedIntParameter("pbb_shift", pbb_shift);
}

void sysclk_set_source(uint_fast8_t src)
{
    mock().actualCall("sysclk_set_source");
}

/* Untested- static inline functions in ASF headers:
dfll_config_init_open_loop_mode()
dfll_config_tune_for_target_hz()
osc_disable();
*/
/* ---------------------------------------------------------------------------*/

}

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(HalClockTests)
{
    void setup() override
    {
        mock().clear();
    }

    void teardown() override
    {
        mock().checkExpectations();
        mock().clear();
    }
};

/*============================================================================*/
/*                                    Tests                                   */
/*============================================================================*/
TEST(HalClockTests, InitClockCallsFunctionsWithCorrectArguments)
{
    mock().expectOneCall("dfll_enable_open_loop")
        .withUnsignedIntParameter("dfll_id", 0);
    mock().expectOneCall("sysclk_set_prescalers")
        .withUnsignedIntParameter("cpu_shift", DFLL_FCPU_PRESCALER)
        .withUnsignedIntParameter("pba_shift", DFLL_PBA_PRESCALER)
        .withUnsignedIntParameter("pbb_shift", DFLL_PBB_PRESCALER);
    mock().expectOneCall("sysclk_set_source");
    
    init_clock_at32uc3l0256();
}

TEST(HalClockTests, DeinitClock)
{
    deinit_clock_at32uc3l0256();
}
