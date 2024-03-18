#include "MoveBack.h"
MoveBack::MoveBack(const std::string& name, const BT::NodeConfiguration& conf)
: BT::ActionNodeBase(name, conf)
{}
BT::NodeStatus MoveBack::tick()
{
    return BT::NodeStatus::SUCCESS;
}
void MoveBack::halt(){
    std::cout << "test" << std::endl;
  }