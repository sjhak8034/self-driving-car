// 방향 조향 code

// 모터 제어를 위한 핀 설정
int motorDirection1Pin = 8; // 모터 방향 핀 1
int motorDirection2Pin = 9; // 모터 방향 핀 2
//모터 회전 속도 최대 150, 최소 10
//int motorA1=8;
//int motorA2=9;
//int motorA3=10;
//int motorA4=11;

// 가변 저항을 읽기 위한 핀 설정
//int analogPin=A0;

void setup() {
  // 핀 모드 설정
  Serial.begin(9600)
  pinMode(motorDirection1Pin, OUTPUT);
  pinMode(motorDirection2Pin, OUTPUT);
}

void loop() {
  //int val=analogRead(analogPin);
  // int motorSpeed=map(val, 100, 130, ToLow, ToHigh);
  analogWrite(motorDirection1Pin, 100);
  analogWrite(motorDirection2Pin, 100);
  
  
  // 모터를 좌측으로 회전하도록 설정
  // digitalWrite(motorDirection1Pin, LOW); // 모터 방향 핀 1 설정 (전진)
  // digitalWrite(motorDirection2Pin, HIGH); // 모터 방향 핀 2 설정 (반대 방향)
  
   // 일정 시간 동안 회전
  delay(2000); // 2초 동안 회전

  analogWrite(motorDirection1Pin, 10);
  analogWrite(motorDirection2Pin, 10);
  
  // digitalWrite(motorDirection1Pin, HIGH); // 모터 방향 핀 1 설정 (전진)
  // digitalWrite(motorDirection2Pin, LOW); // 모터 방향 핀 2 설정 (반대 방향)

  // 일정 시간 동안 회전
  delay(2000); // 2초 동안 회전
}
