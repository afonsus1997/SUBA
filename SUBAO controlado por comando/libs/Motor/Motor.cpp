/*
  Motor.cpp - Library for simple DC Motor usage.
  Created by Ruben Capitao, 2 March 2014.
*/

#include "Arduino.h"
#include "Motor.h"

void Motor::attach(int pin1, int pin2)
{
  _pin1 = pin1;
  _pin2 = pin2;
}

void Motor::setSpeed(int dir, int speed)
{
  if(dir){
    analogWrite(_pin1, speed);
    analogWrite(_pin2, 0);
  }else{
    analogWrite(_pin2, speed);
    analogWrite(_pin1, 0);
  }
}
