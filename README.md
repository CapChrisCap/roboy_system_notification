# Roboy System Notifications Module

This module helps you to send system messages in a very easy way.

## Installation

### 0. Ensure that ROS master is running

For this package, you need a ROS master running. Therefore, you have to run it before processing the next steps. 
If you run your ROS core on the same host, you can run it with: 

```bash
roscore &
```

You can find more information about the ROS core here: [http://wiki.ros.org/roscore](http://wiki.ros.org/roscore)

### 1. IF NOT STILL DONE: Add dependency roboy_communication to workspace
```bash
cd YOUR_WORKSPACE_DIR/src
git clone -b feature/error-detection-msgs https://github.com/Roboy/roboy_communication
```

### 2. Add this repository to your workspace
```bash
cd YOUR_WORKSPACE_DIR/src
git clone https://github.com/CapChrisCap/roboy_system_notification
```

### 3. Source setup files
```bash
cd YOUR_WORKSPACE_DIR
source devel/setup.bash
```

For a ROS Kinetic: 
```bash
cd YOUR_WORKSPACE_DIR
source /opt/ros/kinetic/setup.bash 
```

### 4. Build the package
```bash
cd YOUR_WORKSPACE_DIR/src
catkin_make
```

### 5. Check if topics exist
To check if the installation was successful, execute the test main command 
of this repository to check, whether the topics are published: 
```bash
rosrun roboy_system_notification roboy_system_notification
```

Now, you should be able to see the publishers in your `rostopic list` output: 
```
/roboy/system_notification/debug
/roboy/system_notification/error
/roboy/system_notification/info
/roboy/system_notification/warning
```

As well as something like this: 
```txt
[ INFO] [1498942255.647170100]: Sent info message!
[ INFO] [1498942255.647471300]: Sent debug message!
[ INFO] [1498942255.647499700]: Sent warning message!
[ INFO] [1498942255.647508800]: Sent error message!
[ INFO] [1498942255.647521600]: Roboy System Notification is alive!
```

## Usage

After installing the package, you can now use the class within your own ROS package. The following steps 
describe the usage. 

### 1. Add this package to your ROS topic's dependency

#### a) Update `CMakeLists.txt` file

Now, add this package name (normally, it should be `roboy_system_notification`) to the 
`CMakeLists.txt` file of your project. Finally, it should look similar to this: 

```txt
[...]

find_package([...] roboy_system_notification [...])
catkin_package([...] roboy_system_notification [...])
[...]
```

#### b) Update `package.xml` file

Next, add the package name (normally, it should be `roboy_system_notification`) to your `package.json` file 
to mark it as a build and run dependency. After that, it will look similar to this: 

```txt
[...]
  <build_depend>roboy_system_notification</run_depend>
[...]
  <run_depend>roboy_system_notification</run_depend>
[...]
```

### 2. Use the `RoboySystemNotification` class within your project

#### API `RoboySystemNotification`

##### void sendErrorMessage(uint32_t id, uint32_t objectId = 0)

Publishes a error message over the channel `/roboy/system_notification/error` with the format [roboy_communication_control::SystemNotification](https://github.com/Roboy/roboy_communication/blob/master/roboy_communication_control/msg/SystemNotification.msg). 

 - The `id` is a [uniform message identifier](https://github.com/CapChrisCap/roboy_communication/blob/feature/error-detection-msgs/middleware/include/common_utilities/CommonDefinitions.h#L16)
 - The `objectId` is an extra, optional identifier of an object, which should be assigned to the error message (one use-case would be the motor ID of a robot).

##### void sendWarningMessage(uint32_t id, uint32_t objectId = 0)

Publishes a warning message over the channel `/roboy/system_notification/warning` with the format [roboy_communication_control::SystemNotification](https://github.com/Roboy/roboy_communication/blob/master/roboy_communication_control/msg/SystemNotification.msg). 

 - The `id` is a [uniform message identifier](https://github.com/CapChrisCap/roboy_communication/blob/feature/error-detection-msgs/middleware/include/common_utilities/CommonDefinitions.h#L16)
 - The `objectId` is an extra, optional identifier of an object, which should be assigned to the error message (one use-case would be the motor ID of a robot).

##### void sendInfoMessage(uint32_t id, uint32_t objectId = 0)

Publishes a info message over the channel `/roboy/system_notification/info` with the format [roboy_communication_control::SystemNotification](https://github.com/Roboy/roboy_communication/blob/master/roboy_communication_control/msg/SystemNotification.msg). 

 - The `id` is a [uniform message identifier](https://github.com/CapChrisCap/roboy_communication/blob/feature/error-detection-msgs/middleware/include/common_utilities/CommonDefinitions.h#L16)
 - The `objectId` is an extra, optional identifier of an object, which should be assigned to the error message (one use-case would be the motor ID of a robot).

##### void sendDebugMessage(uint32_t id, uint32_t objectId = 0)

Publishes a debug message over the channel `/roboy/system_notification/debug` with the format [roboy_communication_control::SystemNotification](https://github.com/Roboy/roboy_communication/blob/master/roboy_communication_control/msg/SystemNotification.msg). 

 - The `id` is a [uniform message identifier](https://github.com/CapChrisCap/roboy_communication/blob/feature/error-detection-msgs/middleware/include/common_utilities/CommonDefinitions.h#L16)
 - The `objectId` is an extra, optional identifier of an object, which should be assigned to the error message (one use-case would be the motor ID of a robot).


#### Example: 

```cpp
#include "roboy_system_notification/roboySystemNotification.hpp"

int main(int argc, char* argv[])
{
    if (!ros::isInitialized()) {
        int argc = 0;
        char **argv = NULL;
        ros::init(argc, argv, "roboySystemNotification");
    }
    RoboySystemNotification notifier;

    // wait to prevent closing topic again
    while (ros::ok()) {
        // send exemplary messages
        notifier.sendInfoMessage(1, 2); // send info message with id=1 and objectId=2
        notifier.sendDebugMessage(2); // send debug message with id=2 and objectId=Default(0)
        notifier.sendWarningMessage(3, 2); // send warning message with id=3 and objectId=2
        notifier.sendErrorMessage(4, 3); // send error message with id=3 and objectId=3
        
        ROS_INFO_THROTTLE(5, "Roboy System Notification is alive!");
    }

    return 0;
}
```

> Example taken from the [main.cpp file](./src/main.cpp)

