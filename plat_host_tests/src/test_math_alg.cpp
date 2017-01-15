#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

/*
 * Basic testing guideline:
 * 1) Test all functionalities
 * 2) Test buffer boundaries
 * 3) Test invalid arguments
 */

extern "C"
{
    #include <math_algorithms.h>
}

TEST_GROUP(MathAlg)
{
    void setup ()
    {
    }

    void teardown ()
    {
        mock().clear();
    }
};

const double alg_input[] = {
    0.00,
    0.10,
    0.20,
    0.30,
    0.40,
    0.50,
    0.60,
    0.70,
    0.80,
    0.90,
    1.00
};

const double alg_output[] = {
    1.00,
    1.01,
    1.04,
    1.09,
    1.16000000000000014211,
    1.25,
    1.35999999999999987566,
    1.49,
    1.64000000000000012434,
    1.81,
    2.00
};

#define ARRAY_SIZE(__arr) (sizeof(__arr)/sizeof(0[__arr]))

TEST(MathAlg, MyAlgInputOutput)
{
    for (int i = 0; i < (int)ARRAY_SIZE(alg_input); i++)
    {
        const double x = alg_input[i];
        const double y = my_alg(x);
        CHECK_EQUAL(alg_output[i], y);
    }
}

const uint16_t raw2c_input[] = {
    0x0000,
    0x0010,
    0x0100,
    0xFFFF,
};

const double raw2c_output[] = {
    -50.0,
    0x0010 / 100.0 - 50.0,
    0x0100 / 100.0 - 50.0,
    0xFFFF / 100.0 - 50.0,
};

TEST(MathAlg, RawToCelciusInputOutput)
{
    for (int i = 0; i < (int)ARRAY_SIZE(raw2c_input); i++)
    {
        const uint16_t x = raw2c_input[i];
        const double y = raw_to_celcius (x);
        CHECK_EQUAL(raw2c_output[i], y);
    }
}

TEST(MathAlg, RawToCelciusRange)
{
    uint16_t n = UINT16_MAX;

    for (int i = 0; i < (int)n; i++)
    {
        const double y = raw_to_celcius ((uint16_t)i);
        CHECK_TRUE (y <= 605.34000);
        CHECK_TRUE (y >= -50);
    }
}
