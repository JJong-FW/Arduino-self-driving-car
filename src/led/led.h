#ifndef __LED_H
#define __LED_H

#include "../def/def.h"
#include "Adafruit_NeoPixel.h"

#define LED_OFF     10
#define LED_ON      20
#define LED_STOP    30

extern void ledInit(void);
extern void ledModeSet(int mode);

extern void frontRihgtLedSet(byte red, byte green, byte blue);
extern void frontLeftLedSet(byte red, byte green, byte blue);
extern void tailLedSet(byte red, byte green, byte blue);
#endif
