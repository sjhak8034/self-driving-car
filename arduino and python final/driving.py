import cv2
import numpy as np
import datetime
import pandas as pd
import get_data_coor_and_speed

import time
# 웹캠 스트림 열기
data = pd.read_csv("data.csv",encoding='utf-8-sig')
# dataframe으로 가져온 데이터를 numpy array로 변환
data = data.to_numpy().tolist()

cap = cv2.VideoCapture(0)  # 0은 기본 웹캠을 나타냅니다. 다른 비디오 소스를 사용할 경우 경로를 제공하세요.
prevTime = 0 
ser = get_data_coor_and_speed.libARDUINO()
ser.init('COM6',9600)

count = 0
while True:
    
    ret, frame = cap.read()  # 프레임 읽기
    curTime = time.time()
    FPS = int(1./(curTime - prevTime ))

    if not ret:
        break
   
 
    
    speed, coor = data[count]
    ser.send_speed_coor(speed,coor)
    
  
    # 텍스트를 비디오 프레임에 추가
    cv2.putText(frame,"speed:" + str(speed) +"coor:"+ str(coor)+"FPS:"+str(FPS), (10, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
    
    # data.append(get_data())
    # 프레임 표시
    cv2.imshow("Video with Data", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    prevTime = curTime
    count+=1
   

cap.release()
cv2.destroyAllWindows()