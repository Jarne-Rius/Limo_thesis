#include "EmergencyBrake.h"
EmergencyBrake::EmergencyBrake(const std::string& name, const BT::NodeConfiguration& conf)
: BT::ActionNodeBase(name, conf)
{}
BT::NodeStatus EmergencyBrake::tick()
{
    std::string msg;
    getInput("message", msg);
    std::cout << msg << std::endl;
    return BT::NodeStatus::SUCCESS;
}
void EmergencyBrake::halt(){
    std::cout << "test" << std::endl;
  }