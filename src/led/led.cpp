#include "led.h"

Adafruit_NeoPixel frontRightLed = Adafruit_NeoPixel(8, 12, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel frontLeftLed = Adafruit_NeoPixel(8, 13, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel backLed = Adafruit_NeoPixel(16, 3, NEO_GRB + NEO_KHZ800);

void ledInit(void)
{
    frontRightLed.begin();
    frontRightLed.setBrightness(150);

    frontLeftLed.begin();
    frontLeftLed.setBrightness(150);

    backLed.begin();
    backLed.setBrightness(150);
}

void frontRihgtLedSet(byte red, byte green, byte blue)
{
    for (int i = 0; i < frontRightLed.numPixels(); i++)
    {
        frontRightLed.setPixelColor(i, red, green, blue);
    }
    noInterrupts();
    frontRightLed.show();
    interrupts();
}

void frontLeftLedSet(byte red, byte green, byte blue)
{
    for (int i = 0; i < frontLeftLed.numPixels(); i++)
    {
        frontLeftLed.setPixelColor(i, red, green, blue);
    }

    noInterrupts();
    frontLeftLed.show();
    interrupts();
}

void humanGangFrontLed(byte red, byte green, byte blue)
{
    for (int i = 0; i < 2; i++)
    {
        frontLeftLed.setPixelColor(i, red, green, blue);
    }

    for (int i = 0; i < 2; i++)
    {
        frontRightLed.setPixelColor(i, red, green, blue);
    }

    noInterrupts();
    frontLeftLed.show();
    frontRightLed.show();
    interrupts();
}

void tailLedPartSet(byte red, byte green, byte blue)
{
    for (int i = 3; i < 13; i++)
    {
        backLed.setPixelColor(i, red, green, blue);
    }

    noInterrupts();
    backLed.show();
    interrupts();
}

void tailLedFullSet(byte red, byte green, byte blue)
{
    for (int i = 3; i < 13; i++)
    {
        backLed.setPixelColor(i, red, green, blue);
    }

    noInterrupts();
    backLed.show();
    interrupts();
}

void ledModeSet(int mode)
{
    static long ledCnt;
    static long ledMainCnt;
    static byte ledSubStep;
    static int preMode;

    if (preMode != mode)
    {
        frontLeftLedSet(0, 0, 0);
        frontRihgtLedSet(0, 0, 0);
        tailLedPartSet(0, 0, 0);
        tailLedFullSet(0, 0, 0);

        ledSubStep = 0;
        preMode = mode;
    }
    else
    {
        return;
    }

    switch (mode)
    {
    case LED_OFF:
        frontLeftLedSet(0, 0, 0);
        frontRihgtLedSet(0, 0, 0);
        tailLedFullSet(0, 0, 0);
        return;

    case LED_TUNNEL:
        frontLeftLedSet(255, 255, 255);
        frontRihgtLedSet(255, 255, 255);
        tailLedFullSet(255, 255, 255);
        return;

    case LED_STOP:
        tailLedPartSet(255, 0, 0);
        return;

    case LED_HUMAN_GANG:
        humanGangFrontLed(255, 255, 0);
        tailLedPartSet(255, 0, 0);
        return;
    }
}