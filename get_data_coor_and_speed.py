import serial
import pandas as pd

# port 정해줘야함

def get_data():
    ser = serial.Serial('COM1', 9600)
    received_data = ser.readline()
    return received_data
