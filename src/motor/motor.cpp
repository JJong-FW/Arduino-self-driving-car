#include "motor.h"

const int leftMotorPower = 10;
const int leftMotorBack = 9;
const int leftMotorForward = 8;

const int rightMotorPower = 5;
const int rightMotorBack = 7;
const int rightMotorForward = 6;

void motorInit(void)
{
    pinMode(leftMotorPower, OUTPUT);
    pinMode(leftMotorBack, OUTPUT);
    pinMode(leftMotorForward, OUTPUT);

    pinMode(rightMotorPower, OUTPUT);
    pinMode(rightMotorBack, OUTPUT);
    pinMode(rightMotorForward, OUTPUT);
}

void motorStop(void)
{
    analogWrite(leftMotorPower, 0);
    digitalWrite(leftMotorBack, LOW);
    digitalWrite(leftMotorForward, LOW);

    analogWrite(rightMotorPower, 0);
    digitalWrite(rightMotorBack, LOW);
    digitalWrite(rightMotorForward, LOW);
}

void motorControl(int L_Speed, int R_Speed)
{
    L_Speed = constrain(L_Speed, -255, 255);
    R_Speed = constrain(R_Speed, -255, 255);

    if (L_Speed >= 0)
    {
        analogWrite(leftMotorPower, L_Speed);
        digitalWrite(leftMotorBack, LOW);
        digitalWrite(leftMotorForward, HIGH);
    }
    else
    {
        analogWrite(leftMotorPower, -L_Speed);
        digitalWrite(leftMotorBack, HIGH);
        digitalWrite(leftMotorForward, LOW);
    }

    if (R_Speed >= 0)
    {
        analogWrite(rightMotorPower, R_Speed);
        digitalWrite(rightMotorBack, LOW);
        digitalWrite(rightMotorForward, HIGH);
    }
    else
    {
        analogWrite(rightMotorPower, -R_Speed);
        digitalWrite(rightMotorBack, HIGH);
        digitalWrite(rightMotorForward, LOW);
    }
}

int parkingMode(int onOff)
{
    static int parkingModeSet;

    if (onOff != RETURN)
    {
        parkingModeSet = onOff;
    }

    return parkingModeSet;
}
