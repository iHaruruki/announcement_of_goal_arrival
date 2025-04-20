#include <cstdlib>
#include <rclcpp/rclcpp.hpp>
#include <action_msgs/msg/goal_status_array.hpp>

using GoalStatusArray = action_msgs::msg::GoalStatusArray;

class ArrivedSpeech : public rclcpp::Node
{
public:
  ArrivedSpeech()
  : Node("arrived_speech")
  {
    sub_ = this->create_subscription<GoalStatusArray>(
      "/navigate_to_pose/_action/status", 10,
      std::bind(&ArrivedSpeech::status_callback, this, std::placeholders::_1));
    RCLCPP_INFO(this->get_logger(), "ArrivedSpeech ノードを起動しました");
  }

private:
  void status_callback(const GoalStatusArray::SharedPtr msg)
  {
    for (auto & s : msg->status_list) {
      // STATUS_SUCCEEDED = 4
      if (s.status == action_msgs::msg::GoalStatus::STATUS_SUCCEEDED) {
        // 合成音声を発生
        std::system("spd-say '到着しました'");
        RCLCPP_INFO(this->get_logger(), "到着しました を再生");
        // 一回だけ流せばよいなら break
        break;
      }
    }
  }

  rclcpp::Subscription<GoalStatusArray>::SharedPtr sub_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ArrivedSpeech>());
  rclcpp::shutdown();
  return 0;
}
