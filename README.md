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

2.
