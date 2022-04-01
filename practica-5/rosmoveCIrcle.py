#! /usr/bin/env python3

import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import math
import time
import numpy as np
from std_srvs.srv import Empty

x = 0
y = 0
z = 0
theta = 0

def poseCallback(pose_message):
    global x
    global y
    global z
    global theta
    
    x = pose_message.x
    y = pose_message.y
    theta = pose_message.theta

def orientate (xgoal, ygoal):
    
	global x
	global y
	global theta

	velocity_message = Twist()
	cmd_vel_topic = '/turtle1/cmd_vel'

	while(True):
		ka = 1
		desired_angle_goal = math.atan2(ygoal-y, xgoal-x)
		
		if theta < 0:
			theta = theta + 2*math.pi
		
		if desired_angle_goal < 0:
			desired_angle_goal = desired_angle_goal + 2*math.pi	

		dtheta = desired_angle_goal - theta
		
		if (abs(dtheta) < 0.1):
			time.sleep(1)
			break

		
		angular_speed = ka * dtheta

		velocity_message.linear.x = 0.0
		velocity_message.angular.z = angular_speed
		velocity_publisher.publish(velocity_message)
        
def go_to_goal (xgoal, ygoal):
	 	
	global x
	global y
	global theta

	velocity_message = Twist()
	cmd_vel_topic = '/turtle1/cmd_vel'

         
	while(True):
		
		ka = 5.0
		desired_angle_goal = math.atan2(ygoal+0.01-y, xgoal+0.01-x)

		if (desired_angle_goal < 0.0):	
			desired_angle_goal = desired_angle_goal + 6.2831	

		dtheta = desired_angle_goal-theta     
		angular_speed = ka * (dtheta)	
		

		if (abs(angular_speed) < 0.5):	
			angular_speed = angular_speed
		else:
			angular_speed = 0.0

		kv = 1.0				
		distance = abs(math.sqrt(((xgoal-x)**2)+((ygoal-y)**2)))
		linear_speed = kv * distance
		
		if (distance < 0.1):
			time.sleep(1)
			break 
