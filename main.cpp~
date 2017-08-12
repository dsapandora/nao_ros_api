#include <iostream>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <unistd.h>



using namespace std;

int main(int argc, char **argv)
{
  std::string robotIp = "192.168.0.101";
//  std::string robotIp = "127.0.0.1:55560";


  AL::ALMotionProxy motion(robotIp);
  AL::ALRobotPostureProxy robotPosture(robotIp);

  

  motion.wakeUp();

  // Example showing how to open the right hand.
  std::string handName = "RHand", LhandName = "LHand";

//  motion.setWalkArmsEnabled(true, true);


  motion.openHand(handName); 


  motion.openHand(LhandName);

  sleep(1);
  motion.closeHand(LhandName);   
  motion.closeHand(handName);

  std::string effectorName  = "LArm";
  int space                 = 2; // FRAME_ROBOT
  std::vector<float> positionChange(6, 0.0f);
  positionChange[0] = 0.05f;	
  
  std::vector<float> positionChangeR(6, 0.0f);
  positionChangeR[0] = -0.05f;	
  
  float fractionMaxSpeed    = 1.0f;
  int axisMask              = 7;

  //motion.changePosition("LArm", space, positionChange, fractionMaxSpeed, axisMask);
  //motion.changePosition("RArm", space, positionChangeR, fractionMaxSpeed, axisMask);


    std::string brazo   = "LArm";
    AL::ALValue patron     = AL::ALValue::array(0.0f,  0.06f,  0.00f, 0.0f, 0.0f, 0.8f);
    AL::ALValue timeList = 2.0f; // seconds              

  motion.positionInterpolation(brazo, 0, patron,
                              63, timeList, false);

  sleep(5);


 // motion.walkTo(0.2f, 0.0f, 1.57079f); //caminar hacia adelante girando 90° grados
  
  motion.angleInterpolationWithSpeed("HeadPitch", -1.0f, 0.2f); // mover la cabeza en vertical 
  //motion.angleInterpolationWithSpeed("HeadYaw", -1.0f, 0.2f); // mover la cabeza en horizontal

  motion.angleInterpolationWithSpeed("HeadPitch", 0.0f, 0.2f);

  //cout << "Position : " << motion.getPosition("RArm", 2, true) << endl;
  
  //motion.getPosition("RArm", 2, true);

  //sleep(2);
  //motion.stopWalk();


  



  robotPosture.goToPosture("StandInit", 0.5f);

  // Example of a cartesian foot trajectory
  // Warning: Needs a PoseInit before executing
  int space0       =  1; // FRAME_ROBOT
  int axisMask0    = 63; // control all the effector's axes
  bool isAbsolute = false;

  // Lower the Torso and move to the side
  std::string torso = "Torso";
//  AL::ALValue path     = AL::ALValue::array(0.0f, -0.07f, -0.03f, 0.0f, 0.0f, 0.0f); //se inclina a la derecha
  AL::ALValue Tpath     = AL::ALValue::array(-0.07f, 0.0f, -0.03f, 0.0f, 0.0f, 0.0f); //se inclina hacia atras
  AL::ALValue time= 2.0f; // seconds
//  motion.positionInterpolation(torso, space0, Tpath, axisMask0, time, isAbsolute);

sleep(5);

  // LLeg motion
  std::string effector   = "LLeg";
  AL::ALValue path       = AL::ALValue::array(0.0f,  0.8f,  0.00f, 0.00f, 0.00f, 0.00f); //horizontal
  //path       = AL::ALValue::array(0.0f,  0.00f,  0.8f, 0.0f, 0.0f, 0.0f);  //levantar el pie
//  path       = AL::ALValue::array(0.8f,  0.00f,  0.00f, 0.0f, 0.0f, 0.0f); //vertical
//  timeList   = 2.0f; // seconds
  motion.positionInterpolation(effector, space0, path, axisMask0, time, isAbsolute);


 motion.walkTo(0.2f, 0.0f, 1.57079f);

  motion.rest();



  return 0;
}
