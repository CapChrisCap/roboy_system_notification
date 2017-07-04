#include "roboy_system_notification/roboySystemNotification.hpp"

int current_msg_id = 0;

RoboySystemNotification::RoboySystemNotification() {
};

RoboySystemNotification::RoboySystemNotification(ros::NodeHandlePtr nh) {
    setNodeHandler(nh);
};

void RoboySystemNotification::setNodeHandler(ros::NodeHandlePtr nh) {
    ROS_INFO("Set ROS Node handler");

    // TODO: what happens if multiple instances are created? Maybe we should check if there is still a not publishing the things
    danger_notification_pub = nh->advertise<roboy_communication_control::DangerNotification>(topicAddresses[DANGER_LEVEL], 1000);
    error_notification_pub = nh->advertise<roboy_communication_control::ErrorNotification>(topicAddresses[ERROR_LEVEL], 1000);
    warning_notification_pub = nh->advertise<roboy_communication_control::WarningNotification>(topicAddresses[WARNING_LEVEL], 1000);
    debug_notification_pub = nh->advertise<roboy_communication_control::DebugNotification>(topicAddresses[DEBUG_LEVEL], 1000);
    info_notification_pub = nh->advertise<roboy_communication_control::InfoNotification>(topicAddresses[INFO_LEVEL], 1000);
}

void RoboySystemNotification::sendInfoMessage(uint32_t code, std::string message, uint32_t objectId) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent info message!");

    roboy_communication_control::InfoNotification msg;
    msg.id = current_msg_id++;
    msg.code = code;
    msg.msg = message;
    msg.objectId = objectId;

    info_notification_pub.publish(msg);
}

void RoboySystemNotification::sendDebugMessage(uint32_t code, std::string message, uint32_t objectId) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent debug message!");

    roboy_communication_control::DebugNotification msg;
    msg.id = current_msg_id++;
    msg.code = code;
    msg.msg = message;
    msg.objectId = objectId;

    debug_notification_pub.publish(msg);
}

void RoboySystemNotification::sendWarningMessage(uint32_t code, std::string message, uint32_t objectId) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent warning message!");

    roboy_communication_control::WarningNotification msg;
    msg.id = current_msg_id++;
    msg.code = code;
    msg.msg = message;
    msg.objectId = objectId;

    warning_notification_pub.publish(msg);
}

void RoboySystemNotification::sendErrorMessage(uint32_t code, std::string message, uint32_t objectId) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent error message!");

    roboy_communication_control::ErrorNotification msg;
    msg.id = current_msg_id++;
    msg.code = code;
    msg.msg = message;
    msg.objectId = objectId;

    error_notification_pub.publish(msg);
}

void RoboySystemNotification::sendDangerMessage(uint32_t code, std::string message, uint32_t objectId) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent danger message!");

    roboy_communication_control::DangerNotification msg;
    msg.id = current_msg_id++;
    msg.code = code;
    msg.msg = message;
    msg.objectId = objectId;

    danger_notification_pub.publish(msg);
}
