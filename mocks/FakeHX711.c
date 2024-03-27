
#include <stdlib.h>
#include "FakeHX711.h"

typedef struct HX711Struct
{
	int32_t * nextDataBuffer;
} HX711;

HX711 * HX711_Create(DIO * dioSCK, DIO * dioDOUT, Timer * timerUs)
{
	HX711 * self = (HX711 *)malloc(sizeof(HX711));
	return self;
}

void HX711_Destroy(HX711 * self)
{
}

void HX711_Init(HX711 * self)
{
}

void HX711_Enable(HX711 * self)
{
}

void HX711_Disable(HX711 * self)
{
}

void HX711_SetChannelAndGain(HX711 * self, HX711_Channel_Gain channelAndGain)
{
}

int32_t HX711_ReadData_Cnt(HX711 * self)
{
	return *self->nextDataBuffer;
}

void FakeHX711_SetReadDataBuffer(HX711 * self, int32_t * data)
{
	self->nextDataBuffer = data;	
}
