# announcement_of_goal_arrival
### Node and Topic
![](picture/rosgraph.png)
## Dependency
```
$ sudo apt install speech-dispatcher
```
## Setup
```
$ cd ~/ros2_ws/src  #Go to ros workspace
$ git clone https://github.com/iHaruruki/announcement_of_goal_arrival.git #clone this package
$ cd ~/ros2_ws
$ colcon build --symlink-install
$ source install/setup.bash
```

## Usage
```
$ ros2 run announcement_of_goal_arrival arrived_speech_node
```
## License
## Authors

## References
[How to use aplay and spd-say command in Linux](https://www.geeksforgeeks.org/how-to-use-aplay-and-spd-say-command-in-linux/)
