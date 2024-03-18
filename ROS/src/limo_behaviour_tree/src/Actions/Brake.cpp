#include "Brake.h"
Brake::Brake(const std::string& name, const BT::NodeConfiguration& conf)
: BT::ActionNodeBase(name, conf)
{}
BT::NodeStatus Brake::tick()
{
    std::string msg;
    getInput("message", msg);
    std::cout << msg << std::endl;
    return BT::NodeStatus::SUCCESS;
}
void Brake::halt(){
    std::cout << "test" << std::endl;
  }