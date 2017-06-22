cmake_minimum_required(VERSION 2.8.3)

project(roboy_system_notifications)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.7)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0 -g ")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

#==============================================================================
# Dependencies
#==============================================================================

find_package(catkin REQUIRED COMPONENTS roscpp controller_interface hardware_interface pluginlib
        roboy_communication_middleware ecl_geometry common_utilities)
catkin_package(CATKIN_DEPENDS message_runtime roboy_communication_middleware common_utilities INCLUDE_DIRS include)

include_directories(
        include
        ${catkin_INCLUDE_DIRS}
)

#==============================================================================
# Application
#==============================================================================

add_executable(roboy_system_notifications src/main.cpp src/roboySystemNotification.cpp)
add_dependencies(roboy_communication_control_gencpp)
target_link_libraries(roboy_system_notifications ${catkin_LIBRARIES})

#==============================================================================
# Installation
#==============================================================================
install(TARGETS
        roboy_system_notifications
        DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
        )

install(FILES
        package.xml
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
        )