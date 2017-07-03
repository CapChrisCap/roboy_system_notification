PROJECT(roboy_system_notification C CXX)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.7)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0 -g ")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

#==============================================================================
# Dependencies
#==============================================================================

# ros
find_package(catkin REQUIRED COMPONENTS roboy_communication_control roscpp std_msgs)
catkin_package( CATKIN_DEPENDS message_runtime roboy_communication_control INCLUDE_DIRS include)
include_directories(${catkin_INCLUDE_DIRS} )

INCLUDE_DIRECTORIES(
        include/
)

#==============================================================================
# Application
#==============================================================================
add_library(roboy_system_notification src/roboySystemNotification.cpp)
add_dependencies(roboy_system_notification roboy_communication_control_gencpp)
target_link_libraries(roboy_system_notification ${catkin_LIBRARIES})

add_executable(roboy_system_notification_test src/main.cpp )
add_dependencies(roboy_system_notification_test roboy_communication_control_gencpp)
target_link_libraries(roboy_system_notification_test ${catkin_LIBRARIES} roboy_system_notification)