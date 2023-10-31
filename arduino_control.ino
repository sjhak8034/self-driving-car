String data = "";
char wait = 'i';
int count = 0;
// 파이썬으로부터 오는 data는 char 형식으로 한글자씩만 들어옴
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
   
      // 신호가 들어올때까지 대기하기 위함
    while(Serial.available()) 
   {
     count ++;
     char wait = Serial.read();
     data.concat(wait);
   } 
  
   if (data[0] == 'g'){
   if (data[count-1] == 'f')
   {
    Serial.println(1+(String)","+data.substring(1,count-1));  
    data = "";
    count = 0;
   }
 
   
  }
 


  
}
