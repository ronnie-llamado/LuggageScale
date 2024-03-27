#include <stdlib.h>
#include "CircularBuffer.h"

typedef struct CircularBufferStruct
{
    uint8_t capacity;

} CircularBuffer;

CircularBuffer * CircularBuffer_Create(uint8_t capacity)
{
    CircularBuffer * self = (CircularBuffer *)malloc(sizeof(CircularBuffer));

    self->capacity = capacity;

    return self;
}

void CircularBuffer_Destroy(CircularBuffer * self)
{
    free(self);
}

uint8_t CircularBuffer_IsEmpty(CircularBuffer * self)
{
    return 1;
}

uint8_t CircularBuffer_IsFull(CircularBuffer * self)
{
    return 0;
}

void CircularBuffer_Put(CircularBuffer * self, char value)
{
    self->capacity++;
}

char CircularBuffer_Get(CircularBuffer * self)
{
    self->capacity--;
    return 0;
}

uint8_t CircularBuffer_Capacity(CircularBuffer * self)
{
    return self->capacity;
}

