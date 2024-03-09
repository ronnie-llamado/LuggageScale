#ifndef FAKE_DIO_H
#define FAKE_DIO_H

#include "DIO.h"

void FakeDIO_LoadBitPattern(DIO * self, uint32_t bitPattern);
uint32_t FakeDIO_GetNumberOfReads(DIO * self);
uint32_t FakeDIO_GetNumberOfWrites(DIO * self);
uint32_t FakeDIO_GetLastWrittenPinState(DIO * self);

#endif // FAKE_DIO_H
