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
    _red = red;
    _green = green;
    _blue = blue;

    int offPulse[] = {4096, 0};
    int onPulse[] = {0, 4096};

    if (_red > 0)
    {
        PWM.setPWM(_channel, onPulse[0], onPulse[1]);
    } 
    else
    {
        PWM.setPWM(_channel, offPulse[0], offPulse[1]);
    }

    if (_blue > 0)
    {
        PWM.setPWM((_channel+1), onPulse[0], onPulse[1]);
    } 
    else
    {
        PWM.setPWM((_channel+1), offPulse[0], offPulse[1]);
    }

    if (_green > 0)
    {
        PWM.setPWM((_channel+2), onPulse[0], onPulse[1]);
    } 
    else
    {
        PWM.setPWM((_channel+2), offPulse[0], offPulse[1]);
    }

}