#include "TimerOne.h"

#include "src/def/def.h"
#include "src/main/main.h"
#include "src/led/led.h"
#include "src/buzzer/buzzer.h"
#include "src/ultrasonic/ultra.h"
#include "src/motor/motor.h"
#include "src/infrared/infrared.h"
#include "src/cdsSensor/cds.h"

void setup()
{
  Serial.begin(9600);

  delay(1000);

  ledInit();
  motorInit();
  buzzerInit();
  infraredInit();
  ultraSonicInit();
  cdsInit();

  Timer1.initialize(INTERVAL);
  Timer1.attachInterrupt(timerCallback); // interupt handler
}

void timerCallback()
{
  static int mainCnt;

  if (parkingMode(RETURN) == ON) // Is it parking? (Very far away from the right wall)
  {
    printStringLog("Mode: Parking", mainCnt);
    parkingControl();
  }
  else
  {
    printStringLog("Mode: Driving", mainCnt);
    selfDrivingCarControl();
  }
}

void loop()
{
}
