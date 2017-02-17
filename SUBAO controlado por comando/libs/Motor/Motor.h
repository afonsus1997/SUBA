/*
  Motor.h - Library for simple DC Motor usage.
  Created by Ruben Capitao, 2 March 2014.
*/
#ifndef Motor_h
#define Motor_h

#define FORWARD 0
#define BACKWARD 1

#include "Arduino.h"

class Motor
{
  public:
    void attach(int pin1, int pin2);
    void setSpeed(int dir, int speed);
  private:
    int _pin1, _pin2;
};

#endif
