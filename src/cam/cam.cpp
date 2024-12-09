#include "cam.h"

int signal;
int yCoord;

void camInit(void)
{
    pixy.init();
    pixy.setLamp(0, 0);
}

void camFunc(void)
{
    int i;
    static int camCnt;

    pixy.ccc.getBlocks();

    if (pixy.ccc.numBlocks > 0)
    {
        // Serial.print("Detected ");
        // Serial.println(pixy.ccc.numBlocks);

        for (i = 0; i < pixy.ccc.numBlocks; i++)
        {
            Serial.print(" block ");
            Serial.print(i);
            Serial.print(": ");
            pixy.ccc.blocks[i].print();
            signal = pixy.ccc.blocks[i].m_signature;
            yCoord = pixy.ccc.blocks[i].m_y;
        }
    }
    else
    {
        signal = 0;
    }
}

int camSignal(void)
{
    return signal;
}

int yCoordValue (void)
{
    return yCoord;
}
