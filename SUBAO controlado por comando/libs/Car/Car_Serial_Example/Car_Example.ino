#include <Servo.h>
#include "Motor.h"
#include "Car.h"
Car car;
char device, mode;
int value;

void setup(){
  Serial.begin(115200);
  Serial.println("Connected!");
  car.attachMotor(5,6);
  car.attachServo(9);
  car.attachEncoder(0);
}

void loop(){
  if(Serial.available()){
    delay(1);
    device=Serial.read();
    mode=Serial.read();
    value=Serial.parseInt();
    
    Serial.print(device);
    Serial.print(mode);
    Serial.println(value);
    switch(device){
      case 'm':
        if(mode=='f')
          car.setSpeed(FORWARD, value);
        else
          car.setSpeed(BACKWARD, value);
      break;
      case 's':
        if(mode=='r')
          car.turn(RIGHT, value);
        else
          car.turn(LEFT, value);
      break;
    }
  }
}
