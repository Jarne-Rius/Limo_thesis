#include "BatteryCheck.h"
BatteryCheck::BatteryCheck(const std::string& name, const BT::NodeConfiguration& conf)
    :BT::ConditionNode(name, conf)
{

}
BT::NodeStatus BatteryCheck::tick()
{
    return BT::NodeStatus::SUCCESS;
}