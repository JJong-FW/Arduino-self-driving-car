
#include "main.h"

int L_Speed;
int R_Speed;

void selfDrivingCarControl(void)
{
    int L_dis = calculateDistance(FRONT_LEFT);
    int R_dis = calculateDistance(FRONT_RIGHT);
    int BR_dis = calculateDistance(BACK_RIGHT);
    int F_dis = calculateDistance(FRONT_CENTER);

    static int ledLogCnt;
    static int logCnt[4];

    printIntLog("front Dis",F_dis,logCnt[0]);

    if (F_dis < 130)
    {
        parkingMode(ON);
        return;
    }
    else if (R_dis > 110)
    {
        L_Speed = MAX_SPEED;
        R_Speed = -20;
    }
    else if (R_dis >= 90 && R_dis <= 110)
    {
        L_Speed = MAX_SPEED;
        R_Speed = MAX_SPEED;
    }
    else
    {
        L_Speed = 0;
        R_Speed = MAX_SPEED;
    }

    if (cdsReturn() > 80)
    {
        printStringLog("LED: ON", ledLogCnt);
        ledModeSet(LED_ON);
    }
    else
    {
        printStringLog("LED: OFF", ledLogCnt);
        ledModeSet(LED_OFF);
    }
    

    motorControl(L_Speed, R_Speed);
}

void parkingControl(void)
{
    static byte parkingStep;
    static long parkingCnt;
    static int counter;

    int F_dis = calculateDistance(FRONT_CENTER);

    if (++counter > TIME_1S)
    {
        Serial.println(parkingStep);
        Serial.println(getBackDistance());
        counter = 0;
    }

    switch (parkingStep)
    {
    case 0:
        if (F_dis > 150)
        {
            if (++parkingCnt > TIME_300MS)
            {
                motorControl(0, 0);
                parkingCnt = 0;
                parkingStep = 1;
            }
        }
        else
        {
            motorControl(-255, 255);
        }

        break;
    case 1:
        ledModeSet(LED_STOP);
        if (++parkingCnt > TIME_3S)
        {
            parkingMode(OFF);
            parkingStep = 0;
            parkingCnt = 0;
        }

        break;
    }
}
