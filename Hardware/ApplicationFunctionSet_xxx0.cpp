#include "DeviceDriverSet_xxx0.h"

extern DeviceDriverSet_Motor AppMotor;

/*运动方向控制序列*/
enum SmartRobotCarMotionControl
{
  Forward,       //(1)
  Backward,      //(2)
  Left,          //(3)
  Right,         //(4)
  Dance,   //(5)
  LeftBackward,  //(6)
  RightForward,  //(7)
  RightBackward, //(8)
  stop_it        //(9)
};               //direction方向:（1）、（2）、 （3）、（4）、（5）、（6）

struct Application_xxx
{
  SmartRobotCarMotionControl Motion_Control;
};

extern Application_xxx Application_SmartRobotCarxxx0;

static void ApplicationFunctionSet_SmartRobotCarMotionControl(SmartRobotCarMotionControl direction, uint8_t is_speed)
{
  static uint8_t directionRecord = 0;
  uint8_t Kp, UpperLimit;
  uint8_t speed = is_speed;
  switch (direction)
  {
  case /* constant-expression */
      Forward:
    /* code */
      AppMotor.DeviceDriverSet_Motor_control(/*direction_A*/ direction_just, /*speed_A*/ speed,
                                             /*direction_B*/ direction_just, /*speed_B*/ speed, /*controlED*/ control_enable); //Motor control
    break;
  case /* constant-expression */ Backward:
    /* code */

      AppMotor.DeviceDriverSet_Motor_control(/*direction_A*/ direction_back, /*speed_A*/ speed,
                                             /*direction_B*/ direction_back, /*speed_B*/ speed, /*controlED*/ control_enable); //Motor control
    break;
  case /* constant-expression */ Left:
   
    AppMotor.DeviceDriverSet_Motor_control(/*direction_A*/ direction_just, /*speed_A*/ speed,
                                           /*direction_B*/ direction_back, /*speed_B*/ speed, /*controlED*/ control_enable); //Motor control
    break;
  case /* constant-expression */ Right:
    
    AppMotor.DeviceDriverSet_Motor_control(/*direction_A*/ direction_back, /*speed_A*/ speed,
                                           /*direction_B*/ direction_just, /*speed_B*/ speed, /*controlED*/ control_enable); //Motor control
    break;
    case Dance:
{
    uint8_t s        = speed;           // your incoming speed
    const uint32_t t = 200;             // “beat” length in ms

    // keep dancing until a new character arrives
    while (true) {
      // if another key is pressed, escape immediately
      if (Serial.available() > 0) break;

      // 1) pivot-left
      AppMotor.DeviceDriverSet_Motor_control(
        direction_just, s,
        direction_back, s,
        control_enable
      );
      delay(t);
      if (Serial.available() > 0) break;

      // 2) pivot-right
      AppMotor.DeviceDriverSet_Motor_control(
        direction_back, s,
        direction_just, s,
        control_enable
      );
      delay(t);
      if (Serial.available() > 0) break;

      // 3) circle-left (left wheel only at 2s)
      AppMotor.DeviceDriverSet_Motor_control(
        direction_just, ((2*s)/3),
        direction_void, 0,
        control_enable
      );
      delay(2*t);
      if (Serial.available() > 0) break;

      // 4) pivot-right
      AppMotor.DeviceDriverSet_Motor_control(
        direction_back, s,
        direction_just, s,
        control_enable
      );
      delay(t);
      if (Serial.available() > 0) break;

      // 5) pivot-left
      AppMotor.DeviceDriverSet_Motor_control(
        direction_just, s,
        direction_back, s,
        control_enable
      );
      delay(t);
      if (Serial.available() > 0) break;

      // 6) circle-right (right wheel only at 2s)
      AppMotor.DeviceDriverSet_Motor_control(
        direction_void, 0,
        direction_just, ((2*s)/3),
        control_enable
      );
      delay(2*t);
      // loop back and repeat unless a key arrived
    }

    // make sure we come to a full stop before returning
    AppMotor.DeviceDriverSet_Motor_control(
      direction_void, 0,
      direction_void, 0,
      control_enable
    );
}
break;
  case /* constant-expression */ LeftBackward:
    AppMotor.DeviceDriverSet_Motor_control(/*direction_A*/ direction_back, /*speed_A*/ speed,
                                           /*direction_B*/ direction_back, /*speed_B*/ speed / 2, /*controlED*/ control_enable); //Motor control
    break;
  case /* constant-expression */ RightForward:
    AppMotor.DeviceDriverSet_Motor_control(/*direction_A*/ direction_just, /*speed_A*/ speed / 2,
                                           /*direction_B*/ direction_just, /*speed_B*/ speed, /*controlED*/ control_enable); //Motor control
    break;
  case /* constant-expression */ RightBackward:
    AppMotor.DeviceDriverSet_Motor_control(/*direction_A*/ direction_back, /*speed_A*/ speed / 2,
                                           /*direction_B*/ direction_back, /*speed_B*/ speed, /*controlED*/ control_enable); //Motor control
    break;
  case /* constant-expression */ stop_it:
    AppMotor.DeviceDriverSet_Motor_control(/*direction_A*/ direction_void, /*speed_A*/ 0,
                                           /*direction_B*/ direction_void, /*speed_B*/ 0, /*controlED*/ control_enable); //Motor control
    break;
  default:
    break;
  }
}
