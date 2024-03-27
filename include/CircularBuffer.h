#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>

// You should not change this file.
// The struct members go only in the .c file
// You need to implement each function

typedef struct CircularBufferStruct CircularBuffer;

CircularBuffer * CircularBuffer_Create(uint8_t capacity);
void CircularBuffer_Destroy(CircularBuffer * self);
uint8_t CircularBuffer_IsEmpty(CircularBuffer * self);
uint8_t CircularBuffer_IsFull(CircularBuffer * self);
void CircularBuffer_Put(CircularBuffer * self, char value);
char CircularBuffer_Get(CircularBuffer * self);
uint8_t CircularBuffer_Capacity(CircularBuffer * self);

#endif // CIRCULAR_BUFFER_H
