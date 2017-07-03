#include "roboy_system_notification/roboySystemNotification.hpp"

RoboySystemNotification::RoboySystemNotification() {
};

RoboySystemNotification::RoboySystemNotification(ros::NodeHandlePtr nh) {
    setNodeHandler(nh);
};

void RoboySystemNotification::setNodeHandler(ros::NodeHandlePtr nh) {
    // TODO: what happens if multiple instances are created? Maybe we should check if there is still a not publishing the things
    danger_notification_pub = nh->advertise<roboy_communication_control::SystemNotification>(topicAddresses[DANGER_LEVEL], 1);
    error_notification_pub = nh->advertise<roboy_communication_control::SystemNotification>(topicAddresses[ERROR_LEVEL], 1);
    warning_notification_pub = nh->advertise<roboy_communication_control::SystemNotification>(topicAddresses[WARNING_LEVEL], 1);
    debug_notification_pub = nh->advertise<roboy_communication_control::SystemNotification>(topicAddresses[DEBUG_LEVEL], 1);
    info_notification_pub = nh->advertise<roboy_communication_control::SystemNotification>(topicAddresses[INFO_LEVEL], 1);
}

void RoboySystemNotification::sendInfoMessage(uint32_t id, uint32_t objectId) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent info message!");

    roboy_communication_control::SystemNotification msg;
    msg.id = id;
    msg.objectId = objectId;

    info_notification_pub.publish(msg);
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

void RoboySystemNotification::sendDangerMessage(uint32_t id, uint32_t objectId) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent danger message!");

    roboy_communication_control::SystemNotification msg;
    msg.id = id;
    msg.objectId = objectId;

    danger_notification_pub.publish(msg);
}
