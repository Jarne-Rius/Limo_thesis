#include "behaviortree_cpp/bt_factory.h"

using namespace BT;


class Brake: public BT::SyncActionNode
{
private:
    
public:
  BT::NodeStatus tick() override;

  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<std::string>("message")};
  }
  Brake(const std::string& name, const BT::NodeConfig& config);
};