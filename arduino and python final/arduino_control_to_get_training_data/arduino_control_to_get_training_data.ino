#include <Car_Library.h>
String data = "";
char wait = 'i';
int car_speed = 50;
int car_coor = 130;
int motorA1=6;
int motorA2=7;
int motorA3=11;
int motorA4=10;
int analogPin=A0; //가변저항 output pin
int motorDirection1Pin = 8; // 모터 방향 핀 1
int motorDirection2Pin = 9; // 모터 방향 핀 2
int val = 100;
int data_length = 0;
String temp = "";
String temp_2 = "";

// 파이썬으로부터 오는 data는 char 형식으로 한글자씩만 들어옴
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorA3, OUTPUT);
  pinMode(motorA4, OUTPUT);
  pinMode(motorDirection1Pin, OUTPUT);
  pinMode(motorDirection2Pin, OUTPUT);
  pinMode(analogPin,INPUT);
}

void loop() {
  // 직접 핸들을 조정한 값을 가져옴
   car_coor = potentiometer_Read(analogPin);
       //신호가 들어올때까지 대기하기 위함
    while(Serial.available()) 
   {
     char wait = Serial.read();
     data.concat(wait);
     data_length = data.length();
   } 
  
   if (data[0] == 'g'){
    // if first word is g send current coor and speed value
    
    Serial.println(car_speed+(String)","+car_coor);  
    data = "";
 
   }


 
  
  // speed control
  motor_forward(motorA1, motorA2, car_speed);
  motor_forward(motorA3, motorA4, car_speed);
  
  


  
}
