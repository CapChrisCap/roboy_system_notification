#pragma once

#include <ros/ros.h>
#include <inttypes.h>
#include <string>
#include "common_utilities.hpp"
#include <roboy_communication_control/DebugNotification.h>
#include <roboy_communication_control/InfoNotification.h>
#include <roboy_communication_control/WarningNotification.h>
#include <roboy_communication_control/ErrorNotification.h>
#include <roboy_communication_control/DangerNotification.h>

using namespace std;

class RoboySystemNotification{
public:
    RoboySystemNotification();
    RoboySystemNotification(ros::NodeHandlePtr nh);

    /**
     * Set new node handler. Please take care that existing modifications or subscriptions are not removed from the
     * old node handler as well as not transferred to the newly created node handler
     *
     * @param nh new node handler instance
     */
    void setNodeHandler(ros::NodeHandlePtr nh);

    /**
     * Send a message over the system with the level "DEBUG"
     * @param code message code, which represents the meaning of the message
     * @param message message text
     * @param objectId optional object id, is often used to assign an object, like a motor, to the message
     */
    void sendDebugMessage(uint32_t code, std::string message, uint32_t objectId = 0);

    /**
     * Send a message over the system with the level "INFO"
     * @param code message code, which represents the meaning of the message
     * @param message message text
     * @param objectId optional object id, is often used to assign an object, like a motor, to the message
     */
    void sendInfoMessage(uint32_t code, std::string message, uint32_t objectId = 0);

    /**
     * Send a message over the system with the level "WARNING"
     * @param code message code, which represents the meaning of the message
     * @param message message text
     * @param objectId optional object id, is often used to assign an object, like a motor, to the message
     */
    void sendWarningMessage(uint32_t code, std::string message, uint32_t objectId = 0);

    /**
     * Send a message over the system with the level "ERROR"
     * @param code message code, which represents the meaning of the message
     * @param message message text
     * @param objectId optional object id, is often used to assign an object, like a motor, to the message
     */
    void sendErrorMessage(uint32_t code, std::string message, uint32_t objectId = 0);

    /**
     * Send a message over the system with the level "DANGER"
     * @param code message code, which represents the meaning of the message
     * @param message message text
     * @param objectId optional object id, is often used to assign an object, like a motor, to the message
     */
    void sendDangerMessage(uint32_t code, std::string message, uint32_t objectId = 0);

private:
    ros::Publisher info_notification_pub, warning_notification_pub, error_notification_pub, danger_notification_pub, debug_notification_pub;
};