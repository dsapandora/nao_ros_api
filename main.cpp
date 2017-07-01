#include <iostream>
#include <alproxies/almotionproxy.h>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv)
{
  std::string robotIp = "192.168.0.100";


  AL::ALMotionProxy motion(robotIp);

  // Example showing how to open the right hand.
  std::string handName = "RHand", LhandName = "LHand";

  motion.setWalkArmsEnabled(true, true);


  motion.openHand(handName); 


  motion.openHand(LhandName);

  sleep(5);
  motion.closeHand(LhandName);   
  motion.closeHand(handName);

  motion.walkTo(0.2f, 0.0f, 1.57079f); //caminar hacia adelante girando 90° grados

  //sleep(2);
  //motion.stopWalk();


  return 0;
}
