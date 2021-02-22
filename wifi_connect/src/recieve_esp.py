#!/usr/bin/env python
import rospy
import serial 
from wifi_connect.srv import wifi_srv 

COM_PORT = '/dev/ttyUSB0'    
BAUD_RATES = 115200    
ser = serial.Serial(COM_PORT, BAUD_RATES)   

def recieve_data():      
    try: 
        while True:
            while ser.in_waiting:          
                try:
                    data = ser.readline().decode()
                    print('recieve data:', data)
                except UnicodeDecodeError:
                    data = ser.readline().decode()
                    print('recieve data:', data)

                if data != None:
                    for num in data:
                        if num.isdigit():
                            pass_esp8266_info_to_server(num)

    except KeyboardInterrupt:
        ser.close()    
        print('good bye!')

def pass_esp8266_info_to_server(data):
    rospy.wait_for_service('wifi_module')
    try:
        #create a server object
        val = rospy.ServiceProxy('wifi_module', wifi_srv)
        #val(arg) -> send a req to server
        resp = val(data)
    except rospy.ServiceException, e:
        print ('error')

if __name__ == "__main__":
    recieve_data()