#include "cds.h"

#include "../def/def.h"

const int cds = A7;

void cdsInit(void)
{
    pinMode(cds, INPUT);
}

int cdsReturn(void)
{
    static int cdsCnt;
    int cdsValue = analogRead(cds); // 조도 센서 값 읽기

    if (++cdsCnt > TIME_1S)
    {
        Serial.print("Cds Value: ");
        Serial.println(cdsValue);
        cdsCnt = 0;
    }

    return cdsValue; // 읽은 조도 값 반환
}
