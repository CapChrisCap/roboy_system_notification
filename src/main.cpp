#include "roboy_system_notification/roboySystemNotification.hpp"

int main(int argc, char* argv[])
{
    if (!ros::isInitialized()) {
        int argc = 0;
        char **argv = NULL;
        ros::init(argc, argv, "roboySystemNotification");
    }

    ros::NodeHandlePtr nh = ros::NodeHandlePtr(new ros::NodeHandle);
    RoboySystemNotification notifier(nh);

    // wait to prevent closing topic again
    while (ros::ok()) {
        // send exemplary messages
        notifier.sendInfoMessage(5, "This is a dummy info message", 2); // send info message with code=5 and objectId=2
        notifier.sendDebugMessage(6, "This is a dummy debug message without an objectId"); // send debug message with code=6 and objectId=Default(0)
        notifier.sendWarningMessage(7, "This is a dummy warning message"); // send warning message with code=7 and objectId=2
        notifier.sendErrorMessage(8, "This is a dummy error message"); // send error message with code=8 and objectId=3
        
        ROS_INFO_THROTTLE(5, "Roboy System Notification is alive!");
    }

    return 0;
}