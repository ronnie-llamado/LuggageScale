
#include <stdlib.h>
#include "LoadCell.h"

typedef struct LoadCellStruct
{
    // Replace with CircularBuffer
    int32_t * buffer;
    uint32_t bufferSize;

    int32_t offset;
    int32_t (* LoadCell_Read)(void);
} LoadCell;

LoadCell * LoadCell_Create(void)
{
    LoadCell * self = (LoadCell *)malloc(sizeof(LoadCell));

    LoadCell_Init(self);

    return self;
}

void LoadCell_Destroy(LoadCell * self)
{
    free(self);
}

void LoadCell_Init(LoadCell * self)
{
    self->offset = 0;
}

void LoadCell_Tare(LoadCell * self)
{
}

int32_t LoadCell_Measure(LoadCell * self)
{
    int32_t value = (self->LoadCell_Read() + self->offset);
    return value;
}

void LoadCell_AddReadCallback(LoadCell * self, int32_t (* pLoadCell_Read)(void))
{
    self->LoadCell_Read = pLoadCell_Read;
}

void LoadCell_SetOffset(LoadCell * self, int32_t offset)
{
    self->offset = offset;
}
