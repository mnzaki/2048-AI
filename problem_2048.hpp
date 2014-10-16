#ifndef __PROBLEM_2048_HPP__
#define __PROBLEM_2048_HPP__

#include "search.hpp"

class Problem2048 : public Search::Problem {
public:
  unsigned M;
  unsigned *score_lut;

  class State : public Search::State {
  public:
    unsigned board[4][4];
    State();
  };

  class Operator : public Search::Operator {
  public:
    enum MoveType {
      UP, DOWN, LEFT, RIGHT
    } move;
    Operator(MoveType _move) : move(_move) { };
    Search::State* apply(Search::State*);
  };

  Problem2048(unsigned k);
  bool isGoal(Search::State *s);
  long pathCost(Search::SearchNode*);

};

#endif /* end of include guard: __PROBLEM_2048_HPP__ */
