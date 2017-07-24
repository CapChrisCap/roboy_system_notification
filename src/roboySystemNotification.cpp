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

void RoboySystemNotification::sendInfoMessage(uint32_t code, std::string message, std::string extra, std::string object) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent info message!");

    roboy_communication_control::InfoNotification msg;
    msg.code = code;
    msg.msg = message;
    msg.extra = extra;
    msg.object = object;

    info_notification_pub.publish(msg);
}

void RoboySystemNotification::sendDebugMessage(uint32_t code, std::string message, std::string extra, std::string object) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent debug message!");

    roboy_communication_control::DebugNotification msg;
    msg.code = code;
    msg.msg = message;
    msg.extra = extra;
    msg.object = object;

    debug_notification_pub.publish(msg);
}

void RoboySystemNotification::sendWarningMessage(uint32_t code, std::string message, std::string extra, std::string object) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent warning message!");

    roboy_communication_control::WarningNotification msg;
    msg.code = code;
    msg.msg = message;
    msg.extra = extra;
    msg.object = object;

    warning_notification_pub.publish(msg);
}

void RoboySystemNotification::sendErrorMessage(uint32_t code, std::string message, std::string extra, std::string object) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent error message!");

    roboy_communication_control::ErrorNotification msg;
    msg.code = code;
    msg.msg = message;
    msg.extra = extra;
    msg.object = object;

    error_notification_pub.publish(msg);
}

void RoboySystemNotification::sendDangerMessage(uint32_t code, std::string message, std::string extra, std::string object) {
    // TODO: check for invalid input
    ROS_INFO_THROTTLE(5, "Sent danger message!");

    roboy_communication_control::DangerNotification msg;
    msg.code = code;
    msg.msg = message;
    msg.extra = extra;
    msg.object = object;

    danger_notification_pub.publish(msg);
}
