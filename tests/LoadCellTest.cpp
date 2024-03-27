
#include "CppUTest/TestHarness.h"

extern "C"
{
    #include "CircularBuffer.h"
    #include "FakeHX711.h"
    #include "LoadCell.h"

    static HX711 * hx711;
}

TEST_GROUP(LoadCell)
{
    CircularBuffer * circularBuffer;
    const uint8_t bufferSize = 10;

    LoadCell * loadCell;

    static int32_t readHx711(void)
    {
	    return HX711_ReadData_Cnt(hx711);
    }

    // setup runs before each test
    void setup()
    {
	    circularBuffer = CircularBuffer_Create(bufferSize);
	    hx711 = HX711_Create(NULL, NULL, NULL);
	
	    loadCell = LoadCell_Create();
	    LoadCell_Init(loadCell);
	    LoadCell_AddReadCallback(loadCell, readHx711);
    }

    // teardown runs after each test
    void teardown()
    {
    }
};

TEST(LoadCell, test_measure)
{
	int32_t buffer[1] = { 8 };
	FakeHX711_SetReadDataBuffer(hx711, buffer);

	LONGS_EQUAL(8, LoadCell_Measure(loadCell));
}

TEST(LoadCell, test_set_offset_positive)
{
	int32_t buffer[1] = { 8 };
	FakeHX711_SetReadDataBuffer(hx711, buffer);

	LoadCell_SetOffset(loadCell, 8);
	LONGS_EQUAL(16, LoadCell_Measure(loadCell));
}

TEST(LoadCell, test_set_offset_negative)
{
	int32_t buffer[1] = { 8 };
	FakeHX711_SetReadDataBuffer(hx711, buffer);

	LoadCell_SetOffset(loadCell, -8);
	LONGS_EQUAL(0, LoadCell_Measure(loadCell));
}

TEST(LoadCell, test_tare)
{
	int32_t buffer[1] = { 8 };
	FakeHX711_SetReadDataBuffer(hx711, buffer);

	LoadCell_SetOffset(loadCell, -8);
}
