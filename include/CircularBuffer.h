#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>

// You should not change this file.
// The struct members go only in the .c file
// You need to implement each function

typedef struct CircularBufferStruct CircularBuffer;

CircularBuffer * CircularBuffer_Create(unsigned int capacity, int default_value);
void CircularBuffer_Destroy(CircularBuffer *);
bool CircularBuffer_IsEmpty(CircularBuffer *);
bool CircularBuffer_IsFull(CircularBuffer *);
bool CircularBuffer_Put(CircularBuffer *, int);
int CircularBuffer_Get(CircularBuffer *);
unsigned int CircularBuffer_Capacity(CircularBuffer *);

#endif // CIRCULAR_BUFFER_H
