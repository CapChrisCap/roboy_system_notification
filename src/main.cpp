#include "roboy_system_notification/roboySystemNotification.hpp"

int main(int argc, char* argv[])
{
    if (!ros::isInitialized()) {
        int argc = 0;
        char **argv = NULL;
        ros::init(argc, argv, "roboySystemNotification");
    }
    RoboySystemNotification notifier;

    // wait to prevent closing topic again
    while (ros::ok()) {
        // send exemplary messages
        notifier.sendInfoMessage(1, 2); // send info message with id=1 and objectId=2
        notifier.sendDebugMessage(2); // send debug message with id=2 and objectId=Default(0)
        notifier.sendWarningMessage(3, 2); // send warning message with id=3 and objectId=2
        notifier.sendErrorMessage(4, 3); // send error message with id=3 and objectId=3
        
        ROS_INFO_THROTTLE(5, "Roboy System Notification is alive!");
    }

    return 0;
}