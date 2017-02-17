#include <Servo.h>
#include "Motor.h"
#include "Car.h"
Car car;

void setup(){
  Serial.begin(115200);
  Serial.println("Connected!");
  car.attachMotor(6,5);
  car.attachServo(9);
  car.attachEncoder(0);
}

void loop(){
  car.turn(RIGHT, 20);
  car.setSpeed(FORWARD, 50);
  Serial.println(car.getSpeed());
  delay(200);
}
