#include "roboy_system_notification/roboySystemNotification.hpp"

RoboySystemNotification::RoboySystemNotification() {
    nh = ros::NodeHandlePtr(new ros::NodeHandle);

    // TODO: what happens if multiple instances are created? Maybe we should check if there is still a not publishing the things
    warning_notification_pub = nh->advertise<roboy_communication_control::SystemNotification>("/roboy/system_notification/warning", 1);
    error_notification_pub = nh->advertise<roboy_communication_control::SystemNotification>("/roboy/system_notification/error", 1);
    debug_notification_pub = nh->advertise<roboy_communication_control::SystemNotification>("/roboy/system_notification/log", 1);
    log_notification_pub = nh->advertise<roboy_communication_control::SystemNotification>("/roboy/system_notification/debug", 1);
};

void RoboySystemNotification::sendInfoMessage(uint32_t id, uint32_t objectId) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent info message!");

    roboy_communication_control::SystemNotification msg;
    msg.id = id;
    msg.objectId = objectId;

    log_notification_pub.publish(msg);
}

void RoboySystemNotification::sendDebugMessage(uint32_t id, uint32_t objectId) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent debug message!");

    roboy_communication_control::SystemNotification msg;
    msg.id = id;
    msg.objectId = objectId;

    debug_notification_pub.publish(msg);
}

void RoboySystemNotification::sendWarningMessage(uint32_t id, uint32_t objectId) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent warning message!");

    roboy_communication_control::SystemNotification msg;
    msg.id = id;
    msg.objectId = objectId;

    warning_notification_pub.publish(msg);
}

void RoboySystemNotification::sendErrorMessage(uint32_t id, uint32_t objectId) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent error message!");

    roboy_communication_control::SystemNotification msg;
    msg.id = id;
    msg.objectId = objectId;

    error_notification_pub.publish(msg);
}