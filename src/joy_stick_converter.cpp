#include "joy_stick_converter/joy_stick_converter.h"

void Joy::joyCallback(const sensor_msgs::Joy::ConstPtr &data) {
    linear = data->axes[1];
    angular = data->axes[0];
    
    acker_.drive.speed = linear * 0.5;
    acker_.drive.steering_angle_velocity = angular * 1.2;

	cout << "##############" << endl;
	cout << "linear  : " << linear << endl;
	cout << "angular : " << angular << endl;
	cout << "##############" << endl;

    acker_pub_.publish(acker_);
    
}

void Joy::initSetup() {
    joy_sub_ = nh_.subscribe("/joy", 10, &Joy::joyCallback, this);
    acker_pub_ = nh_.advertise<ackermann_msgs::AckermannDriveStamped>("/ctrl_cmd",10);
}

int main(int argc, char ** argv) {
    ros::init(argc, argv, "joy_stick_converter");
    Joy joy;
    ros::spin();
    return 0; 
}
