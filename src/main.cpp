#include "algo.h"
#include <thread>

void loop (void* arg);

int main(int argc, const char *argv[]) {

  // allocate memeory for the board object
  algoMove_t* boardObj = new algoMove_t;

  // init board
  DRAWBOARD.clear(boardObj->board);
  DRAWBOARD.restart(boardObj->board);

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
  algoMove_t *copyBoard = new algoMove_t;
  // while (true) {};
  // ALGO.find(boardObj);
  // DRAWBOARD.draw(boardObj->board);
  copyBoard = ALGO.getBoardWithValidMoves(boardObj);
  DRAWBOARD.draw(copyBoard->board);
  delete copyBoard;

}