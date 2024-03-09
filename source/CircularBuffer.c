#include <stdlib.h>
#include "CircularBuffer.h"

typedef struct CircularBufferStruct
{
    unsigned int capacity;

} CircularBuffer;

CircularBuffer * CircularBuffer_Create(unsigned int capacity, int default_value)
{
    CircularBuffer * self = (CircularBuffer *)malloc(sizeof(CircularBuffer));

    self->capacity = capacity;

    return self;
}

void CircularBuffer_Destroy(CircularBuffer * self)
{
    free(self);
}

bool CircularBuffer_IsEmpty(CircularBuffer * self)
{
    return true;
}

bool CircularBuffer_IsFull(CircularBuffer * self)
{
    return false;
}

bool CircularBuffer_Put(CircularBuffer * self, int value)
{
    return false;
}

int CircularBuffer_Get(CircularBuffer * self)
{
    return 0;
}

unsigned int CircularBuffer_Capacity(CircularBuffer * self)
{
    return self->capacity;
}

