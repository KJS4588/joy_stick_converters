#include "ros/ros.h"
#include "geometry_msgs/TwistStamped.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/Joy.h"
#include "ackermann_msgs/AckermannDriveStamped.h"

using namespace std;

class Joy {
private:
	ros::NodeHandle nh_;
	ros::Subscriber joy_sub_;
	ros::Publisher acker_pub_;

	ackermann_msgs::AckermannDriveStamped acker_;
	
	double linear = 0;
	double angular = 0;

public:
	Joy() {
		initSetup();
	}
	~Joy() {	
	}

	void initSetup();
	void joyCallback(const sensor_msgs::Joy::ConstPtr &data);
	void run();
};
