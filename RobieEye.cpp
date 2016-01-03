#include "Arduino.h"
#include "RobieEye.h"
#include "Adafruit_PWMServoDriver.h"
#define PWM Adafruit_PWMServoDriver(0x43)

RobieEye::RobieEye(int channel)
{
    _channel = channel;
}

void RobieEye::setupPWM()
{
   PWM.begin();
   PWM.setPWMFreq(100);
}

void RobieEye::setColor(int red, int green, int blue)
{
    _red = map(red, 0, 255, 0, 4096);
    _green = map(green, 0, 255, 0, 4096);
    _blue = map(blue, 0, 255, 0, 4096);
    
    PWM.setPin(_channel, _red,1);
    PWM.setPin((_channel+1), _blue,1);
    PWM.setPin((_channel+2), _green,1);

}