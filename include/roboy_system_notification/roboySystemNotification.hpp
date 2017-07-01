#pragma once

#include <ros/ros.h>
#include <inttypes.h>
#include <roboy_communication_control/SystemNotification.h>

using namespace std;

class RoboySystemNotification{
public:
    RoboySystemNotification();

    /**
     * Send a message over the system with the level "DEBUG"
     * @param id message id, which is unique and represents a special message
     * @param objectId optional object id, is often used to assign an object, like a motor, to the message
     */
    void sendDebugMessage(uint32_t id, uint32_t objectId = 0);

    /**
     * Send a message over the system with the level "INFO"
     * @param id message id, which is unique and represents a special message
     * @param objectId optional object id, is often used to assign an object, like a motor, to the message
     */
    void sendInfoMessage(uint32_t id, uint32_t objectId = 0);

    /**
     * Send a message over the system with the level "WARNING"
     * @param id message id, which is unique and represents a special message
     * @param objectId optional object id, is often used to assign an object, like a motor, to the message
     */
    void sendWarningMessage(uint32_t id, uint32_t objectId = 0);

    /**
     * Send a message over the system with the level "ERROR"
     * @param id message id, which is unique and represents a special message
     * @param objectId optional object id, is often used to assign an object, like a motor, to the message
     */
    void sendErrorMessage(uint32_t id, uint32_t objectId = 0);

private:
    ros::NodeHandlePtr nh;
    ros::NodeHandle n;
    ros::Publisher log_notification_pub, warning_notification_pub, error_notification_pub, debug_notification_pub;
};