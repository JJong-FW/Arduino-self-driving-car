#ifndef __MAIN_H
#define __MAIN_H

#include "../def/def.h"
#include "../ultrasonic/ultra.h"
#include "../buzzer/buzzer.h"
#include "../motor/motor.h"
#include "../led/led.h"
#include "../infrared/infrared.h"
#include "../cdsSensor/cds.h"
#include "../cam/cam.h"

extern void selfDrivingCarControl(void);

extern void parkingControl(void);
#endif

