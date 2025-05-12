#include <avr/wdt.h>
#include "DeviceDriverSet_xxx0.h"
#include "ApplicationFunctionSet_xxx0.cpp"

DeviceDriverSet_Motor AppMotor;
Application_xxx Application_SmartRobotCarxxx0;

void setup() {
  Serial.begin(9600);
  AppMotor.DeviceDriverSet_Motor_Init();
  delay(2000);
  // for (Application_SmartRobotCarxxx0.Motion_Control = 0; Application_SmartRobotCarxxx0.Motion_Control < 9; Application_SmartRobotCarxxx0.Motion_Control = Application_SmartRobotCarxxx0.Motion_Control + 1)
  // {
  //   ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control /*direction*/, 200 /*speed*/);
  //   delay(1000);
  // }
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == 'A') {
      ApplicationFunctionSet_SmartRobotCarMotionControl(Forward, 100);
    } else if (cmd == 'B') {
      ApplicationFunctionSet_SmartRobotCarMotionControl(Backward, 100);
    } else if (cmd == 'C') {
      ApplicationFunctionSet_SmartRobotCarMotionControl(stop_it, 100);
    } else if (cmd == 'D') {
      ApplicationFunctionSet_SmartRobotCarMotionControl(Right, 100);
    } else if (cmd == 'E') {
      ApplicationFunctionSet_SmartRobotCarMotionControl(Left, 100);
    } else if (cmd == 'F') {
      ApplicationFunctionSet_SmartRobotCarMotionControl(Dance, 100);
    }
  }
}


