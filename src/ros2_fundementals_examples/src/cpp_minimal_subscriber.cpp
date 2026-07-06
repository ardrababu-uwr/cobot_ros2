/**
 * @file cpp_minimal_subscriber.cpp
 * @author Ardra Babu
 * @brief Demonstrates subscribing to messages on a ROS 2 topic
 * @version 0.1
 *
 * ------------
 * Subsription Topics:
 * String messages
 * /cpp example topic - std_msgs/String
 * ------------
 * Publishing Topics:
 * None
 *
 */

#include "rclcpp/rclcpp.hpp" // ROS 2 C++ client library
#include "std_msgs/msg/string.hpp" // Standard message type for strings

using std::placeholders::_1; // Placeholder for callback function arguments

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber() : Node("minimal_subscriber") // Initialize the node with the name "
  {
    subscriber_ = create_subscription<std_msgs::msg::String>
    (
      "/cpp_example_topic",
      10,
      std::bind(
        &MinimalSubscriber::topic_callback,
        this,
        _1
      )
    ); // Create a subscription to the topic "/cpp_example_topic" with a queue size of 10 and bind the callback function

  }

  void topic_callback(const std_msgs::msg::String & msg) const
  {
    RCLCPP_INFO_STREAM(get_logger(), "I heard: " << msg.data); // Log the received message
  }

private:
  //Member variables
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_; // Subscription for std_msgs::msg::String messages
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc,argv); // Initialize the ROS 2 system

  auto minimal_subscriber_node = std::make_shared<MinimalSubscriber>(); // Create an instance of the MinimalSubscriber node
  rclcpp::spin(minimal_subscriber_node); // Spin the node to process callbacks (e.g., topic callbacks)

  rclcpp::shutdown(); // Shutdown the ROS 2 system

  return 0;
}
