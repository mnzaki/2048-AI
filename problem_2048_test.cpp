#include <iostream>
#include "problem_2048.hpp"

int main(int argc, char *argv[]) {
  Problem2048 *p = new Problem2048(4);
  std::cout << ((Problem2048::State*)p->initialState)->visualize();
  return 0;
}
