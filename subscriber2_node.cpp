#include <ros/ros.h>
#include <std_msgs/String.h>

void collegeInfoCallback(const std_msgs::String::ConstPtr& msg) {
  ROS_INFO("Received College Info: %s", msg->data.c_str());
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "college_sub");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("college_info", 10, collegeInfoCallback);
  
  ros::spin();

  return 0;
}
