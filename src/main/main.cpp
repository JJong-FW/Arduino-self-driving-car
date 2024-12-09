
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
    static byte blueDetectFlag;
    static int blueOffCnt;
    // printIntLog("front Dis", F_dis, logCnt[0]);

    if (F_dis < 130)
    {
        Serial.println("front detect Motor Stop");

        if (camSignal() == 1)
        {
            ledModeSet(LED_HUMAN_GANG);
        }
        else
        {
            parkingBuzzer();
            ledModeSet(LED_STOP);
        }

        motorControl(0, 0);
        return;
    }
    else if (R_dis > 110)
    {
        L_Speed = MAX_SPEED;
        R_Speed = -(MAX_SPEED / 5);
    }
    else if (R_dis > 90)
    {
        L_Speed = MAX_SPEED;
        R_Speed = MAX_SPEED;
    }
    else
    {
        L_Speed = -(MAX_SPEED / 5);
        R_Speed = MAX_SPEED;
    }

    if (camSignal() == 1)
    {
        if (yCoordValue() < 70)
        {
            printStringLog("Red or Blue detect", logCnt[1]);
            ledModeSet(LED_STOP);
            L_Speed = 0;
            R_Speed = 0;

            // Serial.println("red detect Motor Stop");
        }
    }
    else if (camSignal() == 3)
    {
        blueDetectFlag = 1;
        // Serial.println("blue detect Motor Stop");
    }
    else
    {
        if (cdsReturn() > 100)
        {
            printStringLog("LED: ON", ledLogCnt);
            L_Speed = MAX_SPEED * 0.8;
            R_Speed = MAX_SPEED * 0.8;
            ledModeSet(LED_TUNNEL);
        }
        else
        {
            printStringLog("LED: OFF", ledLogCnt);
            ledModeSet(LED_OFF);
        }
    }

    if (blueDetectFlag)
    {
        ledModeSet(LED_STOP);
        L_Speed = 0;
        R_Speed = 0;

        if (camSignal() != 3)
        {
            if (++blueOffCnt > TIME_1S)
            {
                blueDetectFlag = 0;
                blueOffCnt = 0;
            }
        }
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

        if (++parkingCnt > TIME_5S)
        {
            parkingMode(OFF);
            parkingStep = 0;
            parkingCnt = 0;
        }
        break;
    }
}
