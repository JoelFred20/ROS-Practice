#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include "college_info.h"

int main(int argc, char** argv) {
  ros::init(argc, argv, "college_pub");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<std_msgs::String>("college_info", 10);
  ros::Rate loop_rate(1);
  
  CollegeInfo college;
  college.collegeName = "ABC College";
  college.course = "Computer Science";
  college.year = 2022;

  while (ros::ok()) {
    std_msgs::String msg;
    std::stringstream ss;
    
    // Publishing the college info
    ss << "College Name: " << college.collegeName << " | ";
    ss << "Course: " << college.course << " | ";
    ss << "Year: " << college.year;
    msg.data = ss.str();
    pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
