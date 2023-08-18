#include "algo.h"
#include "drawboard.h"
#include <thread>

void loop (void* arg);

int main(int argc, const char *argv[]) {

  vector<vii> board;

  ALGO.find();
  DRAWBOARD.clear(board);
  DRAWBOARD.restart(board);
  
  thread th(loop, (void*)&board);

  th.join();

  return 0;
}

void loop(void* arg){

  vector<vii>* board = (vector<vii>*)arg;
  DRAWBOARD.draw(*board);

}