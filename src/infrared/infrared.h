#ifndef __INFRARED__H
#define __INFRARED__H

#define FRONT_LEFT 1
#define FRONT_CENTER 2
#define FRONT_RIGHT 3
#define BACK_LEFT 4
#define BACK_RIGHT 5

extern void infraredInit(void);
extern long calculateDistance(int sensorPin);
extern long getInfraredDistance(int sensorName);
#endif
