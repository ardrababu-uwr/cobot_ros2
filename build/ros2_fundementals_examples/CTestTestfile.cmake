# CMake generated Testfile for 
# Source directory: /home/ardra/ros2_tut/src/ros2_fundementals_examples
# Build directory: /home/ardra/ros2_tut/build/ros2_fundementals_examples
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cpp_minimal_publisher_test "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/ardra/ros2_tut/build/ros2_fundementals_examples/test_results/ros2_fundementals_examples/cpp_minimal_publisher_test.gtest.xml" "--package-name" "ros2_fundementals_examples" "--output-file" "/home/ardra/ros2_tut/build/ros2_fundementals_examples/ament_cmake_gtest/cpp_minimal_publisher_test.txt" "--command" "/home/ardra/ros2_tut/build/ros2_fundementals_examples/cpp_minimal_publisher_test" "--gtest_output=xml:/home/ardra/ros2_tut/build/ros2_fundementals_examples/test_results/ros2_fundementals_examples/cpp_minimal_publisher_test.gtest.xml")
set_tests_properties(cpp_minimal_publisher_test PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/ardra/ros2_tut/build/ros2_fundementals_examples/cpp_minimal_publisher_test" TIMEOUT "60" WORKING_DIRECTORY "/home/ardra/ros2_tut/build/ros2_fundementals_examples" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;95;ament_add_test;/opt/ros/jazzy/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/ardra/ros2_tut/src/ros2_fundementals_examples/CMakeLists.txt;94;ament_add_gtest;/home/ardra/ros2_tut/src/ros2_fundementals_examples/CMakeLists.txt;0;")
subdirs("gtest")
