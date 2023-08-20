#include "algo.h"
#include "movestep.h"
#include <thread>

void loop (void* arg);

int main(int argc, const char *argv[]) {

  // allocate memeory for the board object
  algoMove_t* boardObj = new algoMove_t;

  // init board
  DRAWBOARD.clear(*boardObj);
  DRAWBOARD.restart(*boardObj);

  // create thread
  thread th(loop, (void*)boardObj);

  // wait for the thread to end
  th.join(); // no return

  // if something wrong
  return -1;
}

/**
 * @brief no return loop
 * 
 * @param arg 
 */
void loop(void* arg){

  algoMove_t* boardObj = (algoMove_t*)arg;

  while (true)
  {
    MOVESTEP.loop(boardObj);
  }

}