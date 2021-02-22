#!/usr/bin/env python
#-*- coding:utf-8 -*-
############################
#File Name: client.py
#Author: Wang
#Mail: wang@hotmail.com
#Created Time:2017-09-25 18:25:25
############################

import rospy
from html.srv import test_srv

def main():
    rospy.wait_for_service('test')
    try:
        val = rospy.ServiceProxy('test', test_srv)
        resp = val(False)
        print('resp is : {}'.format(resp.num_res))
    except rospy.ServiceException, e:
        print e

if __name__ == "__main__":
    main()

#feedback:
    #True dsdf
