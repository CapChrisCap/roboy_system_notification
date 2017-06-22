#include "roboy_system_notifications/roboySystemNotification.hpp"

int main(int argc, char* argv[])
{
    if (!ros::isInitialized()) {
        int argc = 0;
        char **argv = NULL;
        ros::init(argc, argv, "roboySystemNotification");
    }
    RoboySystemNotification notificatier;
    notificatier.sendLogMessage(1, 2); // send log message with id=1 and objectId=2
    notificatier.sendDebugMessage(2); // send debug message with id=2 and objectId=Default(0)
    notificatier.sendWarningMessage(3, 2); // send warning message with id=3 and objectId=2
    notificatier.sendErrorMessage(4, 3); // send error message with id=3 and objectId=3

    return 0;
}