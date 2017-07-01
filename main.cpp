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


  motion.openHand(handName); 


  motion.openHand(LhandName);

  sleep(5);
  motion.closeHand(LhandName);   
  motion.closeHand(handName);

  motion.moveTo(0.2f, 0.2f, 1.5709f);

  sleep(5);
  motion.moveTo(-0.2f, 0.2f, -1.5709f);


  return 0;
}
