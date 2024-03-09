
#include <stdlib.h>
#include "UART.h"

typedef struct UARTStruct
{
    uint32_t baudRate;
} UART;

UART * UART_Create(void)
{
    UART * self = (UART *)malloc(sizeof(UART));

    UART_Init(self);

    return self;
}

void UART_Destory(UART * self)
{
    free(self);
}

void UART_Init(UART * self)
{
}

void UART_Enable(UART * self)
{
}

void UART_Disable(UART * self)
{
}

void UART_SetBaudRate(UART * self, uint32_t baudRate)
{
}

void UART_SetParity(UART * self, UART_Parity parity)
{
}

void UART_SetStopBits(UART * self, UART_StopBits stopBits)
{
}

void UART_PutC(UART * self, const char byte)
{
}

void UART_PutS(UART * self, const char * string)
{
}

