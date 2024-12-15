#include "cds.h"

#include "../def/def.h"

const int cds = A7;

void cdsInit(void)
{
    pinMode(cds, INPUT);
}

int cdsReturn(void)
{
    int cdsValue = analogRead(cds); //Illuminance sensor value

    return cdsValue; 
}
