#ifndef DIO_H
#define DIO_H

#include <stdint.h>

#define HIGH    1
#define LOW     0

typedef struct DIOStruct DIO;

typedef enum
{
    DIO_DIRECTION_INPUT,
    DIO_DIRECTION_OUTPUT
} DIO_Direction;

DIO * DIO_Create(void);
void DIO_Destroy(DIO * self);
void DIO_Init(DIO * self);
void DIO_SetDirection(DIO * self, DIO_Direction direction);
void DIO_Write(DIO * self, uint8_t state);
uint8_t DIO_Read(DIO * self);


#endif // DIO_H
