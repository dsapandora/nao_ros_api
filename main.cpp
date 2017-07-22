#include <iostream>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <unistd.h>


using namespace std;

int main(int argc, char **argv)
{
  //std::string robotIp = "192.168.0.101";
  std::string robotIp = "127.0.0.1:51673";


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
  positionChange[2] = 1.5f;	
  
  std::vector<float> positionChangeR(6, 0.0f);
  positionChangeR[0] = 1.5f;	
  
  float fractionMaxSpeed    = 1.0f;
  int axisMask              = 7;

  motion.changePosition("LArm", space, positionChange, fractionMaxSpeed, axisMask);
  motion.changePosition("RArm", space, positionChangeR, fractionMaxSpeed, axisMask);

  sleep(5);

 // motion.walkTo(0.2f, 0.0f, 1.57079f); //caminar hacia adelante girando 90° grados
  
  motion.angleInterpolationWithSpeed("HeadPitch", -1.0f, 0.2f); // mover la cabeza en vertical 
  //motion.angleInterpolationWithSpeed("HeadYaw", -1.0f, 0.2f); // mover la cabeza en horizontal

  motion.angleInterpolationWithSpeed("HeadPitch", 0.0f, 0.2f);

  //cout << "Position : " << motion.getPosition("RArm", 2, true) << endl;
  
  //motion.getPosition("RArm", 2, true);

  //sleep(2);
  //motion.stopWalk();

 // robotPosture.goToPosture("StandInit", 0.5f);  





  

  motion.rest();



  return 0;
}
