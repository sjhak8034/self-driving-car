import serial
import time
import re
WAIT_TIME = 3  # second unit
# 'COM3' 부분에 환경에 맞는 포트 입력
class libARDUINO(object):
    def __init__(self):
        self.port = None
        self.baudrate = None
        self.wait_time = WAIT_TIME  # second unit
        self.ser = None
    # Arduino Serial USB Port Setting
    def init(self, port, baudrate):
        self.ser = serial.Serial()
        self.ser.port, self.port = port, port
        self.ser.baudrate, self.baudrate = baudrate, baudrate
        self.ser.open()
        time.sleep(self.wait_time)
        return self.ser
    def get_data(self):
        get_signal = "g"
        get_signal = get_signal.encode()
        self.ser.write(get_signal)
        data = self.ser.readline()
        data = data.decode()
        
        data = data.strip('\r\n')
        data = data.split(',')

        speed = data[0]
        coor = data[1]
 
       
        return speed, coor
    # def send_plz_signal(self,data):
    #     # 
    #     ser = self.ser
    #     start_signal = "g"
        
    #     fin_signal = "f"
    #     data = start_signal + data + fin_signal 
    #     data = data.encode()
    #     ser.write(data)        
    def close(self):
        self.ser.close()
    def open(self): 
        self.ser.open()
    def send_speed_coor(self,speed,coor):
        ser = self.ser
        ser = self.ser
        start_signal = "s"
        fin_signal = "f"
        speed = str(speed)
        coor = str(coor)
        data = start_signal + speed + "," + coor + fin_signal
        data = data.encode()
        ser.write(data)

