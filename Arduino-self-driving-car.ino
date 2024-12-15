#include "TimerOne.h"

#include "src/def/def.h"
#include "src/main/main.h"
#include "src/led/led.h"
#include "src/buzzer/buzzer.h"
#include "src/ultrasonic/ultra.h"
#include "src/motor/motor.h"
#include "src/infrared/infrared.h"
#include "src/cdsSensor/cds.h"
#include "src/cam/cam.h"

Pixy2 pixy;

void setup()
{
  ledInit();
  motorInit();
  buzzerInit();
  infraredInit();
  ultraSonicInit();
  cdsInit();

  camInit();

  delay(1000);
  Serial.begin(115200);

  Timer1.initialize(INTERVAL);
  Timer1.attachInterrupt(timerCallback); // interupt handler
}

void timerCallback()
{
  static int camCnt;

  selfDrivingCarControl();

  if (++camCnt > TIME_200MS)  //Check the camera every 200 ms
  {
    camFunc();
    camCnt = 0;
  }
}

void loop()
{
}
