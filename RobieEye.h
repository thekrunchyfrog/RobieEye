/*  RobieEye.h - Library for controlling Robie's eyes using the Adafruit
    PWM shield.
    Created by Richard D. Gregorio, Jr. - January 2, 3016
    Released into the public domain.
*/

#ifndef RobieEye_h
#define RobieEye_h

#include "Arduino.h"
#include "Adafruit_PWMServoDriver.h"

class RobieEye
{
    public:
        RobieEye(int channel);
        void setupPWM();
        void setColor(int red, int green, int blue);
    private:
        int _channel;
        int _red;
        int _green;
        int _blue;
};

#endif