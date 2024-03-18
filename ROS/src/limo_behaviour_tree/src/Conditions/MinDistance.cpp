#include "MinDistance.h"
MinDistance::MinDistance(const std::string& name, const BT::NodeConfiguration& conf)
    :BT::ConditionNode(name, conf)
{

}
BT::NodeStatus MinDistance::tick()
{
    return BT::NodeStatus::SUCCESS;
}