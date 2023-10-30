import cv2
import numpy as np
import datetime
import pandas as pd
import get_data_coor_and_speed

import time
# 웹캠 스트림 열기
cap = cv2.VideoCapture(0)  # 0은 기본 웹캠을 나타냅니다. 다른 비디오 소스를 사용할 경우 경로를 제공하세요.
data = []
prevTime = 0 
ser = get_data_coor_and_speed.libARDUINO()
ser.init('COM6',9600)
while True:
    ret, frame = cap.read()  # 프레임 읽기
    curTime = time.time()
    FPS = int(1./(curTime - prevTime ))

    if not ret:
        break
   
    # 현재 날짜와 시간을 가져와서 텍스트로 변환
    
    ser.send_plz_signal()
    speed, coor = ser.get_data()


  
    # 텍스트를 비디오 프레임에 추가
    cv2.putText(frame,"speed:" + str(speed) +"coor:"+ str(coor)+"FPS:"+str(FPS), (10, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
    data.append([speed,coor])
    # data.append(get_data())
    # 프레임 표시
    cv2.imshow("Video with Data", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    prevTime = curTime
    cv2.waitKey(20)
data = pd.DataFrame(data)
data.to_csv('data.csv',encoding='utf-8-sig',index=False)
cap.release()
cv2.destroyAllWindows()