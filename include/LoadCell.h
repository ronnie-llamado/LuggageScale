#ifndef LOAD_CELL_H
#define LOAD_CELL_H

#include <stdint.h>

#define LOAD_CELL_BUFFER_SIZE 10

typedef struct LoadCellStruct LoadCell;

LoadCell * LoadCell_Create(void);
void LoadCell_Destroy(LoadCell * self);
void LoadCell_Init(LoadCell * self);
void LoadCell_Tare(LoadCell * self);
int32_t LoadCell_Measure(LoadCell * self);
void LoadCell_AddReadCallback(LoadCell * self, int32_t (* pLoadCell_Read)(void));
void LoadCell_SetOffset(LoadCell * self, int32_t offset);

#endif // LOAD_CELL_H
