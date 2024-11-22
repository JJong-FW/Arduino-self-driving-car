#include "../def/def.h"
#include "ultra.h"

const int ultraTrig = 22; // ultrasonic tx
const int ultraEcho = 23; // ultrasonic rx

void ultraSonicInit(void)
{
    pinMode(ultraTrig, OUTPUT);
    pinMode(ultraEcho, INPUT);

    digitalWrite(ultraTrig, LOW);
}

long getBackDistance(void) // return mm
{
    digitalWrite(ultraTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(ultraTrig, LOW);

    long duration = pulseIn(ultraEcho, HIGH);
    long distance = ((340 * duration) / 1000 / 2);

    return distance;
}