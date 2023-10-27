// 방향 조향 code

#include <Car_Library.h>

int analogPin=A0; //가변저항 output pin

// 모터 제어를 위한 핀 설정
int motorDirection1Pin = 8; // 모터 방향 핀 1
int motorDirection2Pin = 9; // 모터 방향 핀 2
//모터 회전 속도 최대 150, 최소 10


void setup() {
  // 핀 모드 설정
  Serial.begin(9600);
  pinMode(motorDirection1Pin, OUTPUT);
  pinMode(motorDirection2Pin, OUTPUT);
}

void loop() {  
  
  // Analogwrite
  int val = potentiometer_Read(analogPin); //가변저항 저항값 읽어옴
  Serial.println("First:");
  Serial.println(val);

  while(val<120)
  {
  Serial.println("while");
  Serial.println(val);
  val = potentiometer_Read(analogPin); //가변저항 저항값 읽어옴
  analogWrite(motorDirection1Pin, LOW);
  analogWrite(motorDirection2Pin, 50);
  Serial.println("MIDDLE");
  
  };
  analogWrite(motorDirection1Pin, LOW);
  analogWrite(motorDirection2Pin, LOW);
  
  val = potentiometer_Read(analogPin);
  Serial.println(val);
  // 모터를 좌측으로 회전하도록 설정
  // digitalWrite(motorDirection1Pin, LOW); // 모터 방향 핀 1 설정 (전진)
  // digitalWrite(motorDirection2Pin, HIGH); // 모터 방향 핀 2 설정 (반대 방향)
  
   // 일정 시간 동안 회전
  delay(2000); // 2초 동안 회전
  val = potentiometer_Read(analogPin);

  analogWrite(motorDirection1Pin, LOW);
  analogWrite(motorDirection2Pin, 100);

  val = potentiometer_Read(analogPin);
  Serial.println(val);
  Serial.println("Last:");
  Serial.println("\n");
  
  // digitalWrite(motorDirection1Pin, HIGH); // 모터 방향 핀 1 설정 (전진)
  // digitalWrite(motorDirection2Pin, LOW); // 모터 방향 핀 2 설정 (반대 방향)  
  delay(2000); // 2초 동안 회전
  
  analogWrite(motorDirection1Pin, 100);
  analogWrite(motorDirection2Pin, LOW);
  delay(2000);
}
