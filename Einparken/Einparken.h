#ifndef EINPARKEN_H
#define EINPARKEN_H

#include "ros/ros.h"
#include <math.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>

#include "std_msgs/Int16.h"
#include "std_msgs/Int16MultiArray.h"
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Twist.h>


#define PI                     3.14159265
#define CAR_LENGTH              0.355
#define SCALE_FAKTOR_STEERING   500

class Einparken
{
public:
    Einparken();

    ros::NodeHandle parking;
    ros::Subscriber cmd_sub_;
    ros::Subscriber odom_sub_;
    ros::Subscriber laser_back_sub_;
    ros::Subscriber wii_communication_sub;
    ros::Publisher control_servo_pub_;





    std_msgs::Int16 parking_Mode; /* flag for car mode: driving or parking */

    std::vector<float> laserscan_back[];

    std_msgs::Int16 control_Brake; /* flag for brake */
    std_msgs::Int16 control_Mode; /* flag for car mode: manual or autonomous */

    double cmd_linearVelocity;
    double cmd_angularVelocity;
    double cmd_steeringAngle;

    double odom_linearVelocity;
    double odom_angularVelocity;
    double odom_steeringAngle;
    
    void Einparken::start_parking();

private:
    /* subscribe the cmd message from move_base */
    void cmdCallback(const geometry_msgs::Twist::ConstPtr& msg);

    /* subscribe the virtual odom message as a feedback for controller */
    void odomCallback(const geometry_msgs::Twist::ConstPtr& msg);

    /* check the wii states and switch the flag for manual mode and autonomous mode */
    void wiiCommunicationCallback(const std_msgs::Int16MultiArray::ConstPtr& msg);

    /*Scan Back auslesen*/
    void Einparken::ScanBackCallback(const sensor_msgs::LaserScan::ConstPtr& msg);
};

#endif // EINPARKEN_H
