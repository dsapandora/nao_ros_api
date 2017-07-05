#include <iostream>
#include <alproxies/almotionproxy.h>
#include <unistd.h>


using namespace std;

int main(int argc, char **argv)
{
  std::string robotIp = "192.168.0.100";
 // std::string robotIp = "127.0.0.1";


  AL::ALMotionProxy motion(robotIp);
  

  motion.wakeUp();

  // Example showing how to open the right hand.
  std::string handName = "RHand", LhandName = "LHand";

  motion.setWalkArmsEnabled(true, true);


  motion.openHand(handName); 


  motion.openHand(LhandName);

  sleep(2);
  motion.closeHand(LhandName);   
  motion.closeHand(handName);

  motion.walkTo(0.2f, 0.0f, 1.57079f); //caminar hacia adelante girando 90° grados
  
  motion.angleInterpolationWithSpeed("HeadPitch", -1.0f, 0.2f); // mover la cabeza en vertical 
  motion.angleInterpolationWithSpeed("HeadYaw", -1.0f, 0.2f); // mover la cabeza en horizontal

  //sleep(2);
  //motion.stopWalk();

  motion.rest();

  return 0;
}
