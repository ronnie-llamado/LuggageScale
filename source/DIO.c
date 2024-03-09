
#include <stdlib.h>
#include "DIO.h"

typedef struct DIOStruct
{
    DIO_Direction direction;
} DIO;

DIO * DIO_Create(void)
{
    DIO * self = (DIO *)malloc(sizeof(DIO));

    DIO_Init(self);

    return self;
}

void DIO_Destroy(DIO * self)
{
    free(self);
}

void DIO_Init(DIO * self)
{
}

void DIO_SetDirection(DIO * self, DIO_Direction direction)
{
}

void DIO_Write(DIO * self, uint8_t state)
{
}

uint8_t DIO_Read(DIO * self)
{
    return 0;
}

