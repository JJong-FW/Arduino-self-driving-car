#ifndef __CAM_H
#define __CAM_H

#include "../def/def.h"
#include "Pixy2.h"

#define CAM_RED     1
#define CAM_GREEN   2
#define CAM_BLUE    3

extern Pixy2 pixy;
extern void camInit(void);
extern void camFunc(void);
extern int redColorDetect(void);
extern int camSignal (void);
extern int yCoordValue (void);
#endif

