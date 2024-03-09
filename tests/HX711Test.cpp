
#include "CppUTest/TestHarness.h"

extern "C"
{
    #include "FakeDIO.h"
    #include "FakeTimer.h"
    #include "HX711.h"
}

TEST_GROUP(HX711)
{
    DIO * dioSCK = DIO_Create();
    DIO * dioDOUT = DIO_Create();
    Timer * timerUs = Timer_Create();

    HX711 * hx711;

    // setup runs before each test
    void setup()
    {
        hx711 = HX711_Create(dioSCK, dioDOUT, timerUs);
    }

    // teardown runs after each test
    void teardown()
    {
        HX711_Destroy(hx711);
        DIO_Destroy(dioSCK);
        DIO_Destroy(dioDOUT);
        Timer_Destroy(timerUs);
    }
};

TEST(HX711, test_create)
{
    CHECK(hx711 != NULL);
}

TEST(HX711, test_enable)
{
    HX711_Enable(hx711);
    LONGS_EQUAL(1, FakeDIO_GetNumberOfWrites(dioSCK));
    LONGS_EQUAL(0, FakeDIO_GetLastWrittenPinState(dioSCK));
}

TEST(HX711, test_disable)
{
    HX711_Disable(hx711);
    LONGS_EQUAL(1, FakeDIO_GetNumberOfWrites(dioSCK));
    LONGS_EQUAL(1, FakeDIO_GetLastWrittenPinState(dioSCK));
}

TEST(HX711, test_read_data_zero)
{
    FakeDIO_LoadBitPattern(dioDOUT, 0);
    LONGS_EQUAL(0, HX711_ReadData_Cnt(hx711));
    LONGS_EQUAL(24 + 1, FakeDIO_GetNumberOfReads(dioDOUT));
    LONGS_EQUAL(50, FakeDIO_GetNumberOfWrites(dioSCK));
}

TEST(HX711, test_read_data_one)
{
    uint32_t backwardsExpectedData = 0x800000 << 1;  // Shift left by one to account for IsDataReady check
    FakeDIO_LoadBitPattern(dioDOUT, backwardsExpectedData);
    LONGS_EQUAL(1, HX711_ReadData_Cnt(hx711));
    LONGS_EQUAL(24 + 1, FakeDIO_GetNumberOfReads(dioDOUT));
    LONGS_EQUAL(50, FakeDIO_GetNumberOfWrites(dioSCK));
}

TEST(HX711, test_read_data_max)
{
    uint32_t backwardsExpectedData = 0xFFFFFFFE << 1;  // Shift left by one to account for IsDataReady check
    FakeDIO_LoadBitPattern(dioDOUT, backwardsExpectedData);
    LONGS_EQUAL(0x7FFFFF, HX711_ReadData_Cnt(hx711));
    LONGS_EQUAL(24 + 1, FakeDIO_GetNumberOfReads(dioDOUT));
    LONGS_EQUAL(50, FakeDIO_GetNumberOfWrites(dioSCK));
}

TEST(HX711, test_set_channel_and_gain)
{
    HX711_SetChannelAndGain(hx711, HX711_CHAN_A_GAIN_64);
    HX711_ReadData_Cnt(hx711);
    LONGS_EQUAL(50 + 4, FakeDIO_GetNumberOfWrites(dioSCK));
}
