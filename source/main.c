
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "DIO.h"
#include "HX711.h"
#include "LoadCell.h"
#include "Timer.h"
#include "UART.h"

static DIO * dio_SCK;
static DIO * dio_DOUT;
static Timer * timer_uS;
static HX711 * hx711;
static LoadCell * loadCell;
static UART * uart;

int32_t hx711_readData(void);

int main(void)
{
    dio_SCK = DIO_Create();
    dio_DOUT = DIO_Create();
    timer_uS = Timer_Create();

    hx711 = HX711_Create(dio_SCK, dio_DOUT, timer_uS);

    loadCell = LoadCell_Create();
    LoadCell_Init(loadCell);
    LoadCell_AddReadCallback(loadCell, hx711_readData);

    uart = UART_Create();

    int32_t value = 0;

    for(uint8_t i = 0; i < 10; i++)
    {
        value = LoadCell_Measure(loadCell);
        printf("Load Cell (cnt):\t%d\r\n", value);
    }

    LoadCell_SetOffset(loadCell, 1);

    for(uint8_t i = 0; i < 10; i++)
    {
        value = LoadCell_Measure(loadCell);
        printf("Load Cell (cnt):\t%d\r\n", value);
    }

    LoadCell_SetOffset(loadCell, -1);

    for(uint8_t i = 0; i < 10; i++)
    {
        value = LoadCell_Measure(loadCell);
        printf("Load Cell (cnt):\t%d\r\n", value);
    }
}

int32_t hx711_readData(void){
    return HX711_ReadData_Cnt(hx711);
}

