#ifndef PARKING_H
#define PARKING_H

#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "std_msgs/Int16.h"
#include "std_msgs/Int16MultiArray.h"
#include <sensor_msgs/LaserScan.h>
#include <math.h>

#define PI                     3.14159265
#define CAR_LENGTH              0.355
#define SCALE_FAKTOR_STEERING   500

class parking
{
public:
	parking();


	ros::NodeHandle n;
// variables
	std_msgs::Int16 control_Mode;
	geometry_msgs::Twist cmd_parking;

	ros::Subscriber laser_back_sub;
	ros::Subscriber wii_communication_sub;

	ros::Publisher cmd_parking_pub;

	const float *rangesPtr;
	float range_array[500];
	bool laser_back_changed;

	bool park;

// functions
	void LaserBackCallback(const sensor_msgs::LaserScan::ConstPtr& msg);
	void wiiCommunicationCallback(const std_msgs::Int16MultiArray::ConstPtr& msg);


};
#endif // PARKING_H