#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from action_msgs.msg import GoalStatusArray, GoalStatus
from unique_identifier_msgs.msg import UUID

class DebugStatusPub(Node):
    def __init__(self):
        super().__init__('debug_status_pub')
        self.pub = self.create_publisher(GoalStatusArray,
                                         '/navigate_to_pose/_action/status',
                                         10)
        # 1秒ごとに送信
        self.timer = self.create_timer(1.0, self.publish_succeeded)

    def publish_succeeded(self):
        msg = GoalStatusArray()
        goal_status = GoalStatus()
        goal_status.status = GoalStatus.STATUS_SUCCEEDED
        # UUID は 16 バイト必要
        uuid = UUID()
        uuid.uuid = [0]*15 + [1]
        goal_status.goal_id.stamp = self.get_clock().now().to_msg()
        goal_status.goal_id.id = uuid
        msg.status_list = [goal_status]
        self.pub.publish(msg)
        self.get_logger().info('<<SUCCEEDED>> メッセージをパブリッシュ')

def main():
    rclpy.init()
    node = DebugStatusPub()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
