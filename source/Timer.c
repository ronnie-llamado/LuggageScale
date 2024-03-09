
#include <stdlib.h>

#include "Timer.h"

typedef struct TimerStruct
{

} Timer;

Timer * Timer_Create(void)
{
    Timer * self = (Timer *)malloc(sizeof(Timer));
    return self;
}

void Timer_Destroy(Timer * self)
{
    free(self);
}

void Timer_Init(Timer * self)
{
}

void Timer_Delay(Timer * self, uint16_t count)
{
}
