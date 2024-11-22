
#include "buzzer.h"

const int buzzer = 2;

void buzzerInit(void)
{
    pinMode(buzzer, OUTPUT);
}

void warningBuzzer (int sound, int timmer)
{
    static int buzzerCnt;
    static int buzzerStep;

    switch (buzzerStep)
    {
    case 0:
        tone(buzzer, sound);
        buzzerStep = 1;
        break;

    case 1:
        if (++buzzerCnt > timmer)
        {
            buzzerCnt = 0;
            buzzerStep = 2;
        }
        break;

    case 2:
        noTone(buzzer);
        buzzerStep = 3;
        break;

    case 3:
        if (++buzzerCnt > timmer)
        {
            buzzerCnt = 0;
            buzzerStep = 0;
        }
        break;
    }
}

