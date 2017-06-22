#include "roboy_system_notification/roboySystemNotification.hpp"

RoboySystemNotification::RoboySystemNotification() {
    nh = ros::NodeHandlePtr(new ros::NodeHandle);

    warning_notification_pub = nh->advertise<roboy_communication_control::SystemNotification>("/roboy/system_notification/warning", 1);
    error_notification_pub = nh->advertise<roboy_communication_control::SystemNotification>("/roboy/system_notification/error", 1);
    debug_notification_pub = nh->advertise<roboy_communication_control::SystemNotification>("/roboy/system_notification/log", 1);
    log_notification_pub = nh->advertise<roboy_communication_control::SystemNotification>("/roboy/system_notification/debug", 1);
};

void RoboySystemNotification::sendLogMessage(uint_32 id, uint_32 objectId = 0) {
    // TODO: check for invalid input

    roboy_communication_control::SystemNotification msg;
    msg.id = id;
    msg.objectId = objectId;

    log_notification_pub.publish(msg);
}

void RoboySystemNotification::sendDebugMessage(uint_32 id, uint_32 objectId = 0) {
    // TODO: check for invalid input

    roboy_communication_control::SystemNotification msg;
    msg.id = id;
    msg.objectId = objectId;

    debug_notification_pub.publish(msg);
}

void RoboySystemNotification::sendWarningMessage(uint_32 id, uint_32 objectId = 0) {
    // TODO: check for invalid input

    roboy_communication_control::SystemNotification msg;
    msg.id = id;
    msg.objectId = objectId;

    warning_notification_pub.publish(msg);
}

void RoboySystemNotification::sendErrorMessage(uint_32 id, uint_32 objectId = 0) {
    // TODO: check for invalid input

    roboy_communication_control::SystemNotification msg;
    msg.id = id;
    msg.objectId = objectId;

    error_notification_pub.publish(msg);
}