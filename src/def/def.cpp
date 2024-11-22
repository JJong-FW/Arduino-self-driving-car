#include "def.h"

void printStringLog(const char* modeMessage, int& counter)
{
    if (++counter > TIME_1S)
    {
        Serial.println(modeMessage);
        counter = 0;
    }
}

void printIntLog(const char* label, int value, int& counter)
{
    if (++counter > TIME_1S)
    {
        Serial.print(label);  
        Serial.print(": ");
        Serial.println(value);
        counter = 0;          
    }
}