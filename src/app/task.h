#ifndef APP_TASK_H
#define APP_TASK_H

#include <PR/ultratypes.h>

s32 taskInit(s32 classIdx, s32 vehicle, s32 testIdx, u16* map, u16*, u16*);
void taskLoad(void);
void taskDeinit(void);

#endif // APP_TASK_H
