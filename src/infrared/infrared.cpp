#include "../def/def.h"
#include "infrared.h"

const int frontLeftInfraredSensor = A1;   
const int frontCentorInfraredSensor = A2; 
const int frontRightInfraredSensor = A3;  
const int BackLeftInfraredSensor = A4;    
const int BackRightInfraredSensor = A5;   

void infraredInit(void)
{
    pinMode(frontLeftInfraredSensor, INPUT);
    pinMode(frontCentorInfraredSensor, INPUT);
    pinMode(frontRightInfraredSensor, INPUT);
}

long calculateDistance(int sensorPin) // return mm
{
    int volt = map(analogRead(sensorPin), 0, 1023, 0, 5000);
    long distance = (27.61 / (volt - 0.1696)) * 10000;

    return distance;
}

long getInfraredDistance(int sensorName)
{
    switch (sensorName)
    {
    case FRONT_LEFT:
        return calculateDistance(frontLeftInfraredSensor);
    case FRONT_CENTER:
        return calculateDistance(frontCentorInfraredSensor);
    case FRONT_RIGHT:
        return calculateDistance(frontRightInfraredSensor);
    case BACK_LEFT:
        return calculateDistance(BackLeftInfraredSensor);
    case BACK_RIGHT:
        return calculateDistance(BackRightInfraredSensor);
    default:
        return -1; 
    }
}