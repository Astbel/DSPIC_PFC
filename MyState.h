#ifndef __MYSTATE_H_
#define __MYSTATE_H_

//PFC 狀態
typedef enum
{
   IDLE,
   Ramp_UP,
   PFC_ON,
   Shut_Down, 
}My_STATE;

//struct enum 聲明
extern My_STATE my_state;



//擴充方法聲明
inline void PFC_Task_Handle(My_STATE my_state);
inline void Idle_State_handle(void);
inline void Ramp_up_Handle(void);
inline void PFC_ON_Handle(void);
inline void Shut_Down_Handle(void);












#endif
