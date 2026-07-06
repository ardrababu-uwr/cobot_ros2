#include "rclcpp/rclcpp.hpp" // ROS 2 C++ client library
#include "std_msgs/msg/string.hpp" // Standard message type for strings

using namespace std::chrono_literals; // Handle time duration.

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher() : Node("minimal_publisher"), count_(0) // Initialize the node with the name "minimal_publisher"
  {
    // Create a publisher that publishes messages of type std_msgs::msg::String on the topic "topic"
    publisher_ = create_publisher<std_msgs::msg::String>("/cpp_example_topic", 10);

    // Create a timer that calls the timer_callback function every 500 milliseconds
    timer_ = create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));

    RCLCPP_INFO(this->get_logger(), "Publishing at 2Hz");
  }

  void timer_callback()
  {
    // Create a new message of type std_msgs::msg::String
    auto message = std_msgs::msg::String();

    // Set the data of the message to "Hello, world!" followed by the current count
    message.data = "Hello, world! " + std::to_string(count_++);

    // Log the message being published
    //RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());

    // Publish the message on the topic
    publisher_->publish(message);
  }
private:
  size_t count_; // Counter for the number of messages published
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_; // Publisher for std_msgs::msg::String messages
  rclcpp::TimerBase::SharedPtr timer_; // Timer for periodic publishing
};

#if !defined(TESTIND_EXCLUDE_MAIN)
int main(int argc, char * argv[])
{
  // Initialize the ROS 2 system
  rclcpp::init(argc, argv);

  auto minimal_publisher_node = std::make_shared<MinimalPublisher>(); // Create an instance of the MinimalPublisher node

  // Spin the node to process callbacks (e.g., timer callbacks)
  rclcpp::spin(minimal_publisher_node);

  // Shutdown the ROS 2 system
  rclcpp::shutdown();

  return 0;
}
#endif