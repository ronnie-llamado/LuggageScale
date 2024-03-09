#ifndef HX711_H
#define HX711_H

#include <stdint.h>

#include "DIO.h"
#include "Timer.h"

typedef struct HX711Struct HX711;

typedef enum
{
    HX711_CHAN_A_GAIN_128 = 0,
    HX711_CHAN_B_GAIN_32 = 1,
    HX711_CHAN_A_GAIN_64 = 2,
} HX711_Channel_Gain;

HX711 * HX711_Create(DIO * dioSCK, DIO * dioDOUT, Timer * timerUs);
void HX711_Destroy(HX711 * self);
void HX711_Init(HX711 * self);
void HX711_Enable(HX711 * self);
void HX711_Disable(HX711 * self);
void HX711_SetChannelAndGain(HX711 * self, HX711_Channel_Gain channelAndGain);
int32_t HX711_ReadData_Cnt(HX711 * self);

#endif // HX711_H
