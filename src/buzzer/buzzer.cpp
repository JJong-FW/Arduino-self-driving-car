
#include "buzzer.h"

const int buzzer = 2;

void buzzerInit(void)
{
    pinMode(buzzer, OUTPUT);
}

void warningBuzzer(int sound, int timmer)
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

void parkingBuzzer(void)
{
    static int buzzerCnt;
    static int buzzerStep;

    switch (buzzerStep)
    {
    case 0:
        noTone(buzzer);
        buzzerStep = 1;
        break;

    case 1:
        tone(buzzer, 32);

        if (++buzzerCnt > TIME_1S)
        {
            buzzerCnt = 0;
            buzzerStep = 2;
        }
        break;

    case 2:
        noTone(buzzer);

        if (++buzzerCnt > TIME_1S)
        {
            buzzerCnt = 0;
            buzzerStep = 3;
        }
        break;

    case 3:
        tone(buzzer, 165);

        if (++buzzerCnt > TIME_1S)
        {
            buzzerCnt = 0;
            buzzerStep = 4;
        }
        break;

    case 4:
        noTone(buzzer);
        if (++buzzerCnt > TIME_500MS)
        {
            buzzerCnt = 0;
            buzzerStep = 5;
        }
        break;

    case 5:
        tone(buzzer, 250);

        if (++buzzerCnt > TIME_1S)
        {
            buzzerCnt = 0;
            buzzerStep = 6;
        }
        break;

    case 6:
        noTone(buzzer);
        if (++buzzerCnt > TIME_500MS)
        {
            buzzerCnt = 0;
            buzzerStep = 0;
        }
        break;
    }
}

void buzzerStop(void)
{
    noTone(buzzer);
}