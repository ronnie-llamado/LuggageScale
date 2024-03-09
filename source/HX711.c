
#include <stdio.h>
#include <stdlib.h>

#include "DIO.h"
#include "HX711.h"

typedef struct HX711Struct
{
    DIO * DIO_SCK;
    DIO * DIO_DOUT;
    Timer * Timer_uS;
    HX711_Channel_Gain ChannelAndGain;
} HX711;

const uint8_t HX711_PowerDownTime_Us = 60;
const uint8_t HX711_BaseNumberOfSCKCycles = 24;
const uint16_t HX711_SCKHighTime_Us = 1000;
const uint16_t HX711_SCKLowTime_Us = 1000;
const uint16_t HX711_DOUTSampleTime_Us = 250;

uint8_t HX711_IsDataReady(HX711 * self);

HX711 * HX711_Create(DIO * dioSCK, DIO * dioDOUT, Timer * timerUs)
{
    HX711 * self = (HX711 *)malloc(sizeof(HX711));

    self->DIO_SCK = dioSCK;
    self->DIO_DOUT = dioDOUT;
    self->Timer_uS = timerUs;

    HX711_Init(self);

    return self;
}

void HX711_Destroy(HX711 * self)
{
    free(self);
}

void HX711_Init(HX711 * self)
{
    DIO_SetDirection(self->DIO_SCK, DIO_DIRECTION_OUTPUT);
    DIO_SetDirection(self->DIO_DOUT, DIO_DIRECTION_INPUT);
    HX711_SetChannelAndGain(self, HX711_CHAN_A_GAIN_128);
}

void HX711_Enable(HX711 * self)
{
    DIO_Write(self->DIO_SCK, 0);
}

void HX711_Disable(HX711 * self)
{
    DIO_Write(self->DIO_SCK, 1);
    Timer_Delay(self->Timer_uS, HX711_PowerDownTime_Us);
}

uint8_t HX711_IsDataReady(HX711 * self)
{
    return DIO_Read(self->DIO_DOUT) == 0;
}

void HX711_SetChannelAndGain(HX711 * self, HX711_Channel_Gain channelAndGain)
{
    self->ChannelAndGain = channelAndGain;

    // Channel and gain change does not take effect until next read_data.
}

int32_t HX711_ReadData_Cnt(HX711 * self)
{
    int32_t data = 0;

    while(HX711_IsDataReady(self) != 1);

    for (uint8_t i = 0; i < HX711_BaseNumberOfSCKCycles; i++)
    {
        data <<= 1;

        DIO_Write(self->DIO_SCK, 1);
        Timer_Delay(self->Timer_uS, HX711_SCKLowTime_Us);

        if (DIO_Read(self->DIO_DOUT) == 1)
        {
            data++;
        }

        Timer_Delay(self->Timer_uS, HX711_SCKHighTime_Us - HX711_DOUTSampleTime_Us);
        DIO_Write(self->DIO_SCK, 0);
        Timer_Delay(self->Timer_uS, HX711_SCKLowTime_Us);
    }

    DIO_Write(self->DIO_SCK, 1);
    Timer_Delay(self->Timer_uS, HX711_SCKHighTime_Us);
    DIO_Write(self->DIO_SCK, 0);

    uint8_t extraSckCycles = (uint8_t)self->ChannelAndGain;

    for (uint8_t i = 0; i < extraSckCycles; i++)
    {
        Timer_Delay(self->Timer_uS, HX711_SCKLowTime_Us);
        DIO_Write(self->DIO_SCK, 1);
        Timer_Delay(self->Timer_uS, HX711_SCKHighTime_Us);
        DIO_Write(self->DIO_SCK, 0);
    }

    return data++;
}
