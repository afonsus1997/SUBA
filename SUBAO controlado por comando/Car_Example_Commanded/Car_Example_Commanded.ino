#include <Servo.h>
#include "Motor.h"
#include "Car.h"
#include "SoftwareSerial.h"

#define SPEED 255
#define TURN 90

Car car;
char command;

void setup(){
  Serial.begin(115200);
  Serial.println("--------------------");
  Serial.println("Controlo com comando");
  Serial.println("--------------------");
  Serial.println();
  Serial.println();
  Serial.println("Usa as setas e o joystick para controlar o carro");
  Serial.println("     Y - Frente");
  Serial.println("     X - Esquerda");
  Serial.println("     A - Tras");
  Serial.println("     B -Direita");
  car.attachMotor(5,6);
  car.attachServo(9);
}

void loop(){
  if(Serial.available()){
    command=Serial.read();
    if(command=='w' || command=='y'){
      car.setSpeed(FORWARD, SPEED);
    }else if(command=='x' || command=='u'){
       car.setSpeed(BACKWARD, SPEED);
    }else if(command=='e' || command=='t' || command=='z' || command=='f'){
       car.setSpeed(FORWARD, 0);
    }else if(command=='d' || command=='h'){
      car.turn(RIGHT, TURN);
    }else if(command=='a' || command=='j'){
      car.turn(LEFT, TURN);
    }else if(command=='c' || command=='r' || command=='q' || command=='n'){
      car.turn(RIGHT, 0);
    }
  }
}
