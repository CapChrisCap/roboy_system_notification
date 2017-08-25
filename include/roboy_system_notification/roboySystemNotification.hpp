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
     * @param extra extra message text, which should help the developer to understand or fix the notifications reason
     * @param object optional object id, is often used to assign an object, like a motor, to the message
     * @param durationOfValidity interval duration in which the message is valid after its content expires
     */
    void sendDebugMessage(uint32_t code, std::string message, std::string extra = "", std::string object = "", uint32_t durationOfValidity = 50);

    /**
     * Send a message over the system with the level "INFO"
     * @param code message code, which represents the meaning of the message
     * @param message message text
     * @param extra extra message text, which should help the developer to understand or fix the notifications reason
     * @param object optional object id, is often used to assign an object, like a motor, to the message
     * @param durationOfValidity interval duration in which the message is valid after its content expires
     */
    void sendInfoMessage(uint32_t code, std::string message, std::string extra, std::string object = "", uint32_t durationOfValidity = 50);

    /**
     * Send a message over the system with the level "WARNING"
     * @param code message code, which represents the meaning of the message
     * @param message message text
     * @param extra extra message text, which should help the developer to understand or fix the notifications reason
     * @param object optional object id, is often used to assign an object, like a motor, to the message
     * @param durationOfValidity interval duration in which the message is valid after its content expires
     */
    void sendWarningMessage(uint32_t code, std::string message, std::string extra = "", std::string object = "", uint32_t durationOfValidity = 50);

    /**
     * Send a message over the system with the level "ERROR"
     * @param code message code, which represents the meaning of the message
     * @param message message text
     * @param extra extra message text, which should help the developer to understand or fix the notifications reason
     * @param object optional object id, is often used to assign an object, like a motor, to the message
     * @param durationOfValidity interval duration in which the message is valid after its content expires
     */
    void sendErrorMessage(uint32_t code, std::string message, std::string extra = "", std::string object = "", uint32_t durationOfValidity = 50);

    /**
     * Send a message over the system with the level "DANGER"
     * @param code message code, which represents the meaning of the message
     * @param message message text
     * @param extra extra message text, which should help the developer to understand or fix the notifications reason
     * @param object optional object id, is often used to assign an object, like a motor, to the message
     * @param durationOfValidity interval duration in which the message is valid after its content expires
     */
    void sendDangerMessage(uint32_t code, std::string message, std::string extra = "", std::string object = "", uint32_t durationOfValidity = 50);

private:
    ros::Publisher info_notification_pub, warning_notification_pub, error_notification_pub, danger_notification_pub, debug_notification_pub;
};