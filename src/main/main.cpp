
#include "main.h"

int L_Speed;
int R_Speed;

void selfDrivingCarControl(void)
{
    int L_dis = calculateDistance(FRONT_LEFT);
    int R_dis = calculateDistance(FRONT_RIGHT);
    int BR_dis = calculateDistance(BACK_RIGHT);
    int F_dis = calculateDistance(FRONT_CENTER);

    static byte blueDetectFlag;
    static int blueOffCnt;

    if (F_dis < 180)    //I think the car is going to hit!!
    {
        static int humanGangCnt;

        Serial.println("front detect Motor Stop");

        if (camSignal() == 1)  //If the red floor and the person are detected together 
        {
            ledModeSet(LED_HUMAN_GANG);
            humanGangCnt = 0;
        }
        else
        {
            if (++humanGangCnt > TIME_3S)   //Determine if parking is available for 3 seconds
            {
                parkingBuzzer();
                ledModeSet(LED_STOP);
            }
        }

        motorControl(0, 0);
        return;
    }

    buzzerStop();
    /********************************************************/
    if (R_dis > 110)
    {
        L_Speed = MAX_SPEED;
        R_Speed = -(R_dis / 3);
    }
    else if (R_dis > 90)
    {
        L_Speed = MAX_SPEED + ((R_dis - 100) *3);
        R_Speed = MAX_SPEED + ((100 - R_dis) * 3);
    }
    else
    {
        L_Speed = -(R_dis / 1.8);
        R_Speed = MAX_SPEED;
    }
    
    /*****************************************************/
    if (camSignal() == CAM_RED)
    {
        if (yCoordValue() < 70) //Is the top red?       //If the floor is red, ignore it
        {
            ledModeSet(LED_STOP);
            L_Speed = 0;
            R_Speed = 0;
        }
    }
    else if (camSignal() == CAM_BLUE)   //Vehicle Breaker Detection
    {
        blueDetectFlag = 1; //Flag On
    }
    else
    {
        if (cdsReturn() > 100)  //Is this a tunnel?
        {
            L_Speed = L_Speed * 0.7;
            R_Speed = R_Speed * 0.7;
            ledModeSet(LED_TUNNEL);
        }
        else
        {
            ledModeSet(LED_OFF);
        }
    }

    if (blueDetectFlag)
    {
        ledModeSet(LED_STOP);
        L_Speed = 0;
        R_Speed = 0;

        if (camSignal() != CAM_BLUE)   //Has the car breaker been released?
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



// void parkingControl(void)
// {
//     static byte parkingStep;
//     static long parkingCnt;
//     static int counter;

//     int F_dis = calculateDistance(FRONT_CENTER);

//     if (++counter > TIME_1S)
//     {
//         Serial.println(parkingStep);
//         Serial.println(getBackDistance());
//         counter = 0;
//     }

//     switch (parkingStep)
//     {
//     case 0:
//         if (F_dis > 150)
//         {
//             if (++parkingCnt > TIME_300MS)
//             {
//                 motorControl(0, 0);
//                 parkingCnt = 0;
//                 parkingStep = 1;
//             }
//         }
//         else
//         {
//             motorControl(-255, 255);
//         }

//         break;
//     case 1:
//         ledModeSet(LED_STOP);

//         if (++parkingCnt > TIME_5S)
//         {
//             parkingMode(OFF);
//             parkingStep = 0;
//             parkingCnt = 0;
//         }
//         break;
//     }
// }
