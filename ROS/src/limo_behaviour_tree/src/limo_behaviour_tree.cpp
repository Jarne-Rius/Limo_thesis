#include <ros/ros.h>
#include <ros/package.h>
#include "behaviortree_cpp/bt_factory.h"
#include "Brake.h"

int main(int argc, char* argv[])
{
    ros::init(argc, argv,"limo_behaviour_tree");
    
    ros::NodeHandle nh;
    

    BehaviorTreeFactory factory;

    factory.registerNodeType<Brake>("Brake");
    auto tree = factory.createTreeFromFile(ros::package::getPath("limo_behaviour_tree") + "/tree.xml");

    tree.tickWhileRunning();

    ros::spin();
}