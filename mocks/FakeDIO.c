
#include <stdlib.h>

#include "FakeDIO.h"

typedef struct DIOStruct
{
    uint32_t fakeBitPattern;
    uint32_t numberOfReads;
    uint32_t numberOfWrites;
    uint8_t lastWrittenPinState;
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
    self->fakeBitPattern = 0;
    self->numberOfReads = 0;
    self->numberOfWrites = 0;
    self->lastWrittenPinState = 0;
}

void DIO_SetDirection(DIO * self, DIO_Direction direction)
{
}

void DIO_Write(DIO * self, uint8_t state)
{
    self->lastWrittenPinState = state;
    self->numberOfWrites++;
}

uint8_t DIO_Read(DIO * self)
{
    uint8_t pinState = self->fakeBitPattern & 1;

    self->fakeBitPattern >>= 1;
    self->numberOfReads++;

    return pinState;
}

void FakeDIO_LoadBitPattern(DIO * self, uint32_t bitPattern)
{
    self->fakeBitPattern = bitPattern;
}

uint32_t FakeDIO_GetNumberOfWrites(DIO * self)
{
    return self->numberOfWrites;
}

uint32_t FakeDIO_GetNumberOfReads(DIO * self)
{
    return self->numberOfReads;
}

uint32_t FakeDIO_GetLastWrittenPinState(DIO * self)
{
    return self->lastWrittenPinState;
}
