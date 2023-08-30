# ROS-Practice

1.Client_node.cpp

  Client implementation for the "add_two_ints" ROS service.
  

    1.First, the necessary header files are included - "ros/ros.h" for the ROS system and "beginner_tutorials/AddTwoInts.h" for the service message definition.
    2.Then, the main function initializes the ROS node with the given arguments and name.
    3.It checks if the client has been provided with two additional command-line arguments. If not, it displays the correct usage and returns an error.
    4.A ROS node handle is created to communicate with the ROS system.
    5.A service client object is created to connect to the "add_two_ints" service. The type of the service is specified as "beginner_tutorials::AddTwoInts", which is generated from the add_two_ints.srv service file.
    6.An instance of the service message, "beginner_tutorials::AddTwoInts::Request", is created to store the request data.
    7.The two command-line arguments are converted from strings to long integers using "atoll()" and are assigned to the request message.
    8.The client calls the service with the request message.
    9.If the service call is successful, the response message is received and the sum is printed.
    10.If the service call fails, an error message is printed and the program returns an error.
    11.Finally, the main function returns 0 to indicate a successful execution of the program.

   This code is responsible for creating a client that calls the "add_two_ints" service with two integer arguments and prints the sum received from the service response.

2.college_info.h

This code defines a struct called CollegeInfo in the header file college_info.h.

The CollegeInfo struct has three members:

    collegeName is a string that represents the name of the college.
    course is a string that represents the course or major in which the student is enrolled.
    year is an integer that represents the year or grade level of the student.

The #ifndef, #define, and #endif are known as include guards. They prevent the contents of the header file from being included more than once in the same translation unit, which helps to avoid duplicate definitions and potential compilation errors.This will be called in the publisher2_node.cpp and the subscriber2_node.cpp.

3.publisher2_node.cpp

   This code is a ROS node that publishes information about a college in the form of a std_msgs::String message.

Explanation of the code:

    1.#include <ros/ros.h>: This line includes the necessary ROS header file for using ROS functions.
    2.#include <std_msgs/String.h>: This line includes the std_msgs/String header file for using the std_msgs::String message type.
    3.#include "college_info.h": This line includes a user-defined header file called "college_info.h", which contains a struct definition for storing college information.
    4.int main(int argc, char** argv): The main function of the program.
    5.ros::init(argc, argv, "college_pub"): Initializes the ROS node with the name "college_pub".
    6.ros::NodeHandle nh: Creates a NodeHandle object for interacting with the ROS system.
    7.ros::Publisher pub = nh.advertise<std_msgs::String>("college_info", 10): Creates a publisher object that publishes messages of type std_msgs::String on the "college_info" topic with a queue size of 10.
    8.ros::Rate loop_rate(1): Specifies the frequency at which the loop in the code should run. In this case, it runs at a frequency of 1 Hz.
    9.CollegeInfo college: Creates an instance of the CollegeInfo struct.
    10.college.collegeName = "VIT University Chennai": Assigns the value "VIT University Chennai" to the collegeName member of the CollegeInfo struct.
    11.college.course = "Computer Science": Assigns the value "Computer Science" to the course member of the CollegeInfo struct.
    12.college.year = 2021: Assigns the value 2021 to the year member of the CollegeInfo struct.
    13.while (ros::ok()): Enters a loop that runs as long as the ROS system is running.
    14.std_msgs::String msg: Creates an instance of the std_msgs::String message.
    15.std::stringstream ss: Creates a stringstream object for concatenating the college information.
    16.ss << "College Name: " << college.collegeName << " | ": Appends the college name to the stringstream.
    17.ss << "Course: " << college.course << " | ": Appends the course name to the stringstream.
    18.ss << "Year: " << college.year: Appends the year to the stringstream.
    19.msg.data = ss.str(): Copies the contents of the stringstream to the data member of the std_msgs::String message.
    20.pub.publish(msg): Publishes the std_msgs::String message on the "college_info" topic.
    21.ros::spinOnce(): Allows ROS to process any incoming messages.
    22.loop_rate.sleep(): Causes the program to sleep for a duration that ensures a loop rate of 1 Hz.
    23.return 0: Indicates successful program execution.


4.publisher_node.cpp

Explanation present in the code in the for of comments.

5.server_node.cpp

This code is an example of a ROS service server node that adds two integers.

    The code starts by including the necessary ROS headers: "ros/ros.h" for ROS functionality and "beginner_tutorials/AddTwoInts.h" for the custom service message definition.
    Then, there is a function called "add" that is used as the callback function for the service. This function takes a request object of type       "beginner_tutorials::AddTwoInts::Request" and a response object of type "beginner_tutorials::AddTwoInts::Response". Inside this function, it adds the values of "req.a" and "req.b" and stores the result in "res.sum". It also prints out the values of "req.a" and "req.b" using ROS_INFO, and the value of "res.sum" as the response.
    The main function initializes the ROS node with the provided command-line arguments, sets up a NodeHandle, and then creates a ServiceServer object called "service" using the advertiseService method. The advertiseService method takes two arguments: the name of the service ("add_two_ints") and the callback function ("add").
    After setting up the service, it prints out a message indicating that the server is ready to add two integers. Finally, the program enters a loop using ros::spin() to process incoming service requests.
    Overall, this code sets up a ROS service server node that listens for requests to add two integers and provides the result as the response.

6.subscriber2_node.cpp

This code is a simple ROS (Robot Operating System) node that subscribes to a topic called "college_info" and listens for messages of type std_msgs/String.

    In the main function, it first initializes the ROS node with ros::init, giving it a name "college_sub". It then creates a NodeHandle object nh, which is used to interact with the ROS system.
    Next, it creates a Subscriber object sub by calling nh.subscribe, passing in the topic name "college_info", the queue size 10, and the callback function collegeInfoCallback. The callback function is executed whenever a new message is received on the subscribed topic.
    Finally, ros::spin() is called, which enters into a loop and continuously processes any incoming messages. The node will keep running until it receives a shutdown signal from the ROS system or is terminated by some external factor.
    The collegeInfoCallback function is defined outside of the main function. It takes a single argument of type std_msgs::String::ConstPtr, which is a smart pointer to the received message. Inside the callback function, it prints out the received college information using ROS_INFO macro, which internally publishes the message to the console.


7.subscriber_node.cpp

Explanation present in the code in the for of comments.
