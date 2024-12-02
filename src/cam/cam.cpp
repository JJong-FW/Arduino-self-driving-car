#include "cam.h"

int signal;

void camInit(void)
{
    pixy.init();
    pixy.setLamp(0, 0);
}

void camFunc(void)
{
    int i;

    pixy.ccc.getBlocks();

    if (pixy.ccc.numBlocks > 0)
    {
        // Serial.print("Detected ");
        // Serial.println(pixy.ccc.numBlocks);

        for (i = 0; i < pixy.ccc.numBlocks; i++)
        {
            // Serial.print(" block ");
            // Serial.print(i);
            // Serial.print(": ");
            // pixy.ccc.blocks[i].print();
            signal = pixy.ccc.blocks[i].m_signature;
        }
    }
    else
    {
        signal = 0;
    }
}

void camSignal (void)
{
    return signal;
}