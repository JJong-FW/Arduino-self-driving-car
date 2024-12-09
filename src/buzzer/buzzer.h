#ifndef __BUZZER_H
#define __BUZZER_H

#include "../def/def.h"

extern void buzzerInit (void);

extern void warningBuzzer (int sound, int timmer);
extern void parkingBuzzer(void);
#endif
