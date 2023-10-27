#include <Car_Library.h>

int motorA1=8;
int motorA2=9;
int motorA3=10;
int motorA4=11;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorA3, OUTPUT);
  pinMode(motorA4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Forward
  Serial.println("Motor Forward");
  motor_forward(motorA1, motorA2, 75);
  motor_forward(motorA3, motorA4, 75);
  delay(3000);

  //Backward
  Serial.println("Motor Backward");
  motor_backward(motorA1, motorA2, 150);
  motor_backward(motorA3, motorA4, 150);
  delay(3000);

  //Hold
  Serial.println("Motor Hold");
  motor_hold(motorA1, motorA2);
  motor_hold(motorA3, motorA4);
  delay(3000);
}
