#ifndef UART_H
#define UART_H

#include <stdint.h>

typedef struct UARTStruct UART;

typedef enum {
    UART_PARITY_NONE,
    UART_PARITY_ODD,
    UART_PARITY_EVEN
} UART_Parity;

typedef enum {
    UART_STOPBITS_NONE,
    UART_STOPBITS_0_5,
    UART_STOPBITS_1,
    UART_STOPBITS_1_5,
    UART_STOPBITS_2
} UART_StopBits;

UART * UART_Create(void);
void UART_Destory(UART * self);
void UART_Init(UART * self);
void UART_Enable(UART * self);
void UART_Disable(UART * self);
void UART_SetBaudRate(UART * self, uint32_t baudRate);
void UART_SetParity(UART * self, UART_Parity parity);
void UART_SetStopBits(UART * self, UART_StopBits stopBits);
void UART_PutC(UART * self, const char byte);
void UART_PutS(UART * self, const char * string);

#endif // UART_H
