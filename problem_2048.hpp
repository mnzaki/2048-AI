#ifndef __PROBLEM_2048_HPP__
#define __PROBLEM_2048_HPP__

#include "search.hpp"

class Problem2048 : Search::Problem {
  unsigned M;
  unsigned *score_lut;
  class State : Search::State {
    unsigned board[4][4];
  };

  class Operator : Search::Operator {
    typedef enum MoveType {
      UP, DOWN, LEFT, RIGHT
    };
    Operator(MoveType _move) : move(_move) { };
  }
};

#endif /* end of include guard: __PROBLEM_2048_HPP__ */
