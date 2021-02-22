#!/usr/bin/env python
import rospy
from html.msg import my_msg 


msg = my_msg()

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data)

def listener():
    rospy.init_node('listener', anonymous=True)
    rospy.Subscriber('Big_GG', my_msg, callback)
    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
