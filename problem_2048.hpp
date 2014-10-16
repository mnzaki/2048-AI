#ifndef __PROBLEM_2048_HPP__
#define __PROBLEM_2048_HPP__

#include <string>
#include "search.hpp"
#include "strategies.hpp"
#include <string>

class Problem2048 : public Search::Problem {
public:
  unsigned k;
  unsigned *score_lut;

  class State : public Search::State {
  public:
    unsigned board[4][4];
    State(bool empty);
    State() : State(true) { };
    std::string visualize(void);
  };

  class Operator : public Search::Operator {
  public:
    enum MoveType {
      UP, DOWN, LEFT, RIGHT
    } move;
    Operator(MoveType _move) : move(_move) { };
    Search::State* apply(Search::State*);
    std::string print();
  };

  Problem2048(State* init, unsigned k);
  Problem2048(unsigned k) : Problem2048(NULL, k) { };
  bool isGoal(Search::State *s);
  long pathCost(Search::SearchNode*);

  class GR1 : public Search::BFS {
    int f(Search::SearchNode*);
  };
  class GR2 : public Search::BFS {
    int f(Search::SearchNode*);
  };
  class AS1 : public Search::BFS {
    int f(Search::SearchNode*);
  };
  class AS2 : public Search::BFS {
    int f(Search::SearchNode*);
  };
};

#endif /* end of include guard: __PROBLEM_2048_HPP__ */
