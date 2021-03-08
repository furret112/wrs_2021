To use esp8266 communication 
1. roscore

In your workspace
3. . devel/setup.bash
2. rosrun wifi_connect master.py
3. rosrun wifi_connect recieve_esp1.py
4. press the button and master.py will recieve number of the table

p.s
the esp8266 need to upload "WRS_recieve_to_uno.ino" file
the arduino Uno need to upload "WRS_uno_to_ros.ino" file
and "pin 2"(Uno) connect to "pin D2"(esp) & "pin 3"(Uno) connect to "pin D3"(esp)
