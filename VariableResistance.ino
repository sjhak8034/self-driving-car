// 가변저항 읽는 코드

#include <Car_Library.h>

int analogPin=A0; //가변저항 output pin

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val;
  val=potentiometer_Read(analogPin); //가변저항 저항값 읽어옴
  Serial.println(val);
}
