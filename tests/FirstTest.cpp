#include "CppUTest/TestHarness.h"

extern "C"
{
}

TEST_GROUP(FirstTestGroup)
{
	void setup()
	{
	}

	void teardown()
	{
	}
};

TEST(FirstTestGroup, FirstTest)
{
	FAIL("Fail me!");
}
