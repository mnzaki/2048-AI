#include <iostream>
#include <cstring>
#include "problem_2048.hpp"

int main(int argc, char *argv[]) {
  //Problem2048 *p = new Problem2048(4);
  Problem2048::Operator *op = new Problem2048::Operator(Problem2048::Operator::RIGHT);
  Problem2048::State *s = new Problem2048::State(true);
  unsigned board[4][4] = {{1,1,3,2}, {0,0,0,2}, {0,0,0,0}, {0,0,0,1}};
  memcpy(s->board, board, sizeof board);
  op->apply(s);
  //std::cout << ((Problem2048::State*)p->initialState)->visualize();
  return 0;
}
