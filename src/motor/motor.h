#ifndef __MOTOR_H
#define __MOTOR_H

#include "../def/def.h"

#define FORWARD 1
#define BACKWARD 0

extern void motorInit();
extern void motorControl(int part);

extern void motorControl(int L_Speed, int R_Speed);
extern int parkingMode(int onOff);
#endif
