#!/usr/bin/env python
# To recieve what table has been select
from html.srv import html_srv
import rospy

def fun1(req):
    print('req is : {}'.format(req.num_req))
    return ["finish!"]

def main():
    rospy.init_node('server_html', anonymous = True)
    rospy.Service('html_module', html_srv, fun1)
    rospy.spin()

if __name__ == '__main__':
    main() 
