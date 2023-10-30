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
        data = self.ser.readline()
        data = data.decode()
        
        data = data.strip('\r\n')
        data = data.split(',')

        speed = data[0]
        coor = data[1]
       
        return speed, coor
    def send_plz_signal(self):
        ser = self.ser
        start_signal = "g"
        data = "3"
        fin_signal = "f"
        data = start_signal + data + fin_signal 
        data = data.encode()
        ser.write(data)        
    def close(self):
        self.ser.close()
    def open(self): 
        self.ser.open()


# ser.get_data()
# ser.get_data()
# ser.get_data()

# speed, coor = ser.get_data()
# print(speed,coor)