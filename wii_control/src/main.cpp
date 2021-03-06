#include "wii_lib/wii_lib.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "teleop_wii");
    wii_lib teleop_wii;

    ros::Rate loop_rate(50);

    static int count = 0;

    while(ros::ok())
    {

        teleop_wii.wii_communication_pub.publish(teleop_wii.wii_state_);
	teleop_wii.nh_.setParam("WII_BUTTON_B_PRESSED",teleop_wii.b_pressed);
	//ROS_INFO("Debug message!");
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}


