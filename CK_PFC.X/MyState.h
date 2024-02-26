#ifndef __MYSTATE_H_
#define __MYSTATE_H_

#include "Systemdefine.h"

// PFC 狀態
typedef enum
{
   IDLE,
   Ramp_UP,
   PFC_ON,
   Shut_Down,
} My_STATE;

// struct enum 聲明
extern My_STATE my_state;

// 擴充方法聲明
void PFC_Task_Handle(My_STATE my_state);
void Idle_State_handle(void);
void Ramp_up_Handle(void);
void PFC_ON_Handle(void);
void Shut_Down_Handle(void);

#endif
