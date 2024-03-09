#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

typedef struct TimerStruct Timer;

Timer * Timer_Create(void);
void Timer_Destroy(Timer * self);
void Timer_Init(Timer * self);
void Timer_Delay(Timer * self, uint16_t count);

#endif // TIMER_H
