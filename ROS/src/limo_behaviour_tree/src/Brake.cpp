#include "Brake.h"
Brake::Brake(const std::string& name, const BT::NodeConfig& config)
:BT::SyncActionNode(name, config)
{
    
}
BT::NodeStatus Brake::tick()
{
    std::string msg;
    getInput("message", msg);
    std::cout << msg << std::endl;
    return BT::NodeStatus::SUCCESS;
}