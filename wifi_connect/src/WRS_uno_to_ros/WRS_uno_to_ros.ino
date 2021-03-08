/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

// Use the following line if you have a Leonardo or MKR1000
//#define USE_USBCON

#include <SoftwareSerial.h>
#include <ros.h> 
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>


SoftwareSerial ArduinoUno(3,2);

ros::NodeHandle nh;

std_msgs::String str_msg;
std_msgs::Int32 int_msg;

ros::Publisher chatter("esp_topic", &int_msg);

char hello[13] = "hello world!";
char cstr[4] = "0";

void setup()
{
  Serial.begin(115200);
  ArduinoUno.begin(4800);
  
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{
  while(ArduinoUno.available() > 0)
  {
    int val = ArduinoUno.parseInt();
    //if(ArduinoUno.read() == '\n');
    //{
      Serial.println(val);
      int_msg.data = val;
      chatter.publish( &int_msg );
      //}
    }
  
  nh.spinOnce(); 
}
