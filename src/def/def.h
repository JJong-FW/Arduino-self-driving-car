#ifndef __DEF_H
#define __DEF_H

#include "Arduino.h"

#define VERSION_H   0
#define VERSION_M   0
#define VERSION_L   2

#define MAX_SPEED   150
#define RETURN  99

#define ON  1
#define OFF 0

#define INTERVAL 40000 // 2000us -> 2ms

#define TIME_100MS (100000 / INTERVAL)
#define TIME_200MS (TIME_100MS * 2)
#define TIME_300MS (TIME_100MS * 3)
#define TIME_400MS (TIME_100MS * 4)
#define TIME_500MS (TIME_100MS * 5)
#define TIME_800MS (TIME_100MS * 8)

#define TIME_1S (TIME_100MS * 10)
#define TIME_2S (TIME_1S * 2)
#define TIME_3S (TIME_1S * 3)
#define TIME_5S (TIME_1S * 5)

extern void printStringLog(const char* modeMessage, int& counter);
extern void printIntLog(const char* label, int value, int& counter);
#endif
