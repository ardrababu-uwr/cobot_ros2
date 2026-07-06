/**
 * @file test_publisher.cpp
 * @brief Unit tests for the ROS 2 minimal publisher node.
 *
 * This file contains test cases to verify the functionality of our minimal publisher.
 * We test two main things:
 * 1. That the node is created correctly with the right name and topic
 * 2. That it publishes the expected "Hello World!" message
 *
 * Testing Framework:
 *   Google Test (gtest) for C++ unit testing
 *
 * Tests:
 *   TestNodeCreation: Verifies node name and publisher setup
 *   TestMessageContent: Verifies published message format
 *
 * @author Ardra Babu
 * @date July 4th, 2026
*/

#include <gtest/gtest.h>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class MinimalPublisher;

#define TESTIND_EXCLUDE_MAIN
#include "../../src/cpp_minimal_publisher.cpp"


class TestMinimalPublisher : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        // Initialize ROS 2
        rclcpp::init(0, nullptr);
        // Create the publisher node
        node = std::make_shared<MinimalPublisher>();
    }

    void TearDown() override
    {
      node.reset(); // Reset the node to clean up resources
        // Shutdown ROS 2
        rclcpp::shutdown();
    }

    std::shared_ptr<MinimalPublisher> node;
};

TEST_F(TestMinimalPublisher, TestNodeCreation)
{
    // Verify that the node name is correct
    EXPECT_EQ(std::string(node->get_name()), std::string("minimal_publisher"));

    auto pub_endpoint = node->get_publishers_info_by_topic("/cpp_example_topic");

    // Verify that the publisher is created and is not null
    EXPECT_EQ(pub_endpoint.size(), 1u);
}

TEST_F(TestMinimalPublisher, TestMessageContent)
{
    // Create a publisher to capture the published message
    //auto test_publisher = node->create_publisher<std_msgs::msg::String>("/cpp_example_topic", 10);

    // Create a subscription to capture the published message
    std::shared_ptr<std_msgs::msg::String> received_message;
    auto subscription = node->create_subscription<std_msgs::msg::String>(
        "/cpp_example_topic",
        10,
        [&received_message](const std_msgs::msg::String::SharedPtr msg) {
            received_message = std::make_shared<std_msgs::msg::String>(*msg);
        });

    node->timer_callback(); // Manually trigger the timer callback to publish a message

    rclcpp::spin_some(node); // Process the callback to receive the message

    EXPECT_EQ(received_message->data.substr(0, 14), "Hello, world! ");
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
