#include <string>

enum NotificationLevel {
    UNDEFINED_LEVEL = 0,
    DEBUG_LEVEL,
    INFO_LEVEL,
    WARNING_LEVEL,
    ERROR_LEVEL,
    DANGER_LEVEL
};

std::map<NotificationLevel, std::string> topicAddresses = {
        {DANGER_LEVEL, "/roboy/system_notification/danger"},
        {ERROR_LEVEL, "/roboy/system_notification/error"},
        {WARNING_LEVEL, "/roboy/system_notification/warning"},
        {INFO_LEVEL, "/roboy/system_notification/info"},
        {DEBUG_LEVEL, "/roboy/system_notification/debug"}
};