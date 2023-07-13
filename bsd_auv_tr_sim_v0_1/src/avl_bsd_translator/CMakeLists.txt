#===============================================================================
#  Autonomous Vehicle Library
#
#  Description: CMake file for the avl_bsd_translator ROS package.
#===============================================================================

# Required CMake version
cmake_minimum_required(VERSION 2.8.3)

# Package name
project(avl_bsd_translator)

# Compile as C++14, supported in ROS Melodic and newer
add_compile_options(-std=c++14)
add_compile_options(-Wall -Wextra -Wpedantic -Wno-unused-parameter)

if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  message("${PROJECT_NAME}: no build type specified, choosing Release")
  set(CMAKE_BUILD_TYPE Release)
endif()

#===============================================================================
#                              FIND DEPENDENCIES
#===============================================================================

# Find other Catkin packages required for build
find_package(catkin REQUIRED COMPONENTS
    roscpp
    message_generation
    pcl_ros
)

# Specify include directories
include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

#===============================================================================
#                           MESSAGES/SERVICES/ACTIONS
#===============================================================================
# Message files
add_message_files( FILES
    HeartbeatMsg.msg
    ActionMsg.msg
    ResponseMsg.msg
    CommandMsg.msg
    DeviceMsg.msg
    PassthroughMsg.msg
)

# Generate the language-specific message and service files
generate_messages(
	DEPENDENCIES
	std_msgs
)
#===============================================================================
#                              CONFIGURE PACKAGE
#===============================================================================

# Specify catkin-specific information to the build system
catkin_package(
    INCLUDE_DIRS
        include
    LIBRARIES
    CATKIN_DEPENDS
        roscpp
        message_runtime
    DEPENDS
    CFG_EXTRAS
)

# Create a variable for all exported targets for dependencies
set(EXPORTED_TARGETS ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

#===============================================================================
#                                BUILD LIBRARIES
#===============================================================================


#===============================================================================
#                                    INSTALL
#===============================================================================

# Mark header files for installation
install(DIRECTORY include/${PROJECT_NAME}/
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
        FILES_MATCHING PATTERN "*.h"
        PATTERN ".svn" EXCLUDE
)

#===============================================================================
#                               BUILD EXECUTABLES
#===============================================================================

# Nodes ------------------------------------------------------------------------

# BSD Receiver (uncomment when put on vehicle computer)
#add_executable(bsd_receiver src/node/bsd_receiver.cpp)
#add_dependencies(bsd_receiver ${EXPORTED_TARGETS})
#target_link_libraries(bsd_receiver node asio bsd_comms ${catkin_LIBRARIES})


# Example BSD
add_executable(bsd_example src/node/bsd_example.cpp)
add_dependencies(bsd_example ${EXPORTED_TARGETS})
target_link_libraries(bsd_example ${catkin_LIBRARIES})


#===============================================================================
#                                  BUILD TESTS
#===============================================================================
