#!/usr/bin/env python
# To recieve message from html and send it to master.py
import rospy
from html.srv import html_srv
from html.msg import html_msg 

msg = html_msg()


def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data)
    pass_msg_to_server(data.id)

def listener():
    rospy.init_node('relay', anonymous=True)
    rospy.Subscriber('recieve_html', html_msg, callback)
    rospy.spin()

def pass_msg_to_server(msg):
    rospy.wait_for_service('html_module')
    try:
        val = rospy.ServiceProxy('html_module', html_srv)
        resp = val(msg)
        print('{}'.format(resp.num_res))
    except rospy.ServiceException, e:
        print error

if __name__ == "__main__":

    listener()
