#include <ros/ros.h>
#include <ros/package.h>
#include "behaviortree_cpp_v3/bt_factory.h"
#include "Brake.h"
#include "EmergencyBrake.h"
#include "MoveBack.h"
#include "MoveToTarget.h"
#include "RotateAround.h"
#include "TrackObject.h"
#include "BatteryCheck.h"
#include "CloseEnoughToTarget.h"
#include "MinDistance.h"
#include "SpeedNotZero.h"
#include "SpeedZero.h"
#include "TargetFound.h"
#include "ToCloseToTarget.h"
int main(int argc, char* argv[])
{
    ros::init(argc, argv,"limo_behaviour_tree");
    
    ros::NodeHandle nh;
    
    BehaviorTreeFactory factory;

    factory.registerNodeType<Brake>("Brake");
    factory.registerNodeType<EmergencyBrake>("EmergencyBrake");
    factory.registerNodeType<MoveBack>("MoveBack");
    factory.registerNodeType<MoveToTarget>("MoveToTarget");
    factory.registerNodeType<RotateAround>("RotateAround");
    factory.registerNodeType<TrackObject>("TrackObject");
    factory.registerNodeType<BatteryCheck>("BatteryCheck");
    factory.registerNodeType<CloseEnoughToTarget>("CloseEnoughToTarget");
    factory.registerNodeType<MinDistance>("MinDistance");
    factory.registerNodeType<SpeedNotZero>("SpeedNotZero");
    factory.registerNodeType<SpeedZero>("SpeedZero");
    factory.registerNodeType<TargetFound>("TargetFound");
    factory.registerNodeType<ToCloseToTarget>("ToCloseToTarget");

    factory.registerBehaviorTreeFromFile(ros::package::getPath("limo_behaviour_tree") + "/tree.xml");
    

    //tree.tickRootWhileRunning();


    ros::spin();
}