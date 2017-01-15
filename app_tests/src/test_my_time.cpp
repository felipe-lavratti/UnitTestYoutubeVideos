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
    #include <my_time.h>
}

TEST_GROUP(MyTime)
{
    void setup ()
    {
    }

    void teardown ()
    {
        mock().clear();
    }
};

TEST(MyTime, elapsed)
{
    CHECK_EQUAL (false, time_elapsed(10, 9, 100));
    CHECK_EQUAL (false, time_elapsed(109, 9, 100));
    CHECK_EQUAL (true, time_elapsed(110, 9, 100));

    CHECK_EQUAL (false, time_elapsed(0, UINT32_MAX, 4));
    CHECK_EQUAL (false, time_elapsed(1, UINT32_MAX, 4));
    CHECK_EQUAL (false, time_elapsed(3, UINT32_MAX, 4));
    CHECK_EQUAL (true, time_elapsed(4, UINT32_MAX, 4));
    CHECK_EQUAL (true, time_elapsed(5, UINT32_MAX, 4));
}
