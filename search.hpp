#ifndef __SEARCH_HPP__
#define __SEARCH_HPP__

#include <vector>
#include <deque>
#include <string>

namespace Search {
  class State {
  public:
    virtual std::string visualize(void) =0;
  };

  class Operator {
  public:
    virtual State* apply(State*) =0;
  };

  class SearchNode {
  public:
    State *state;
    SearchNode *parent;
    Operator *op;
    unsigned long depth;
    long pathCost;

    SearchNode(State *_state, SearchNode *_parent, Operator *_op,
              unsigned long _depth, long _pathCost) :
      state(_state), parent(_parent), op(_op),
      depth(_depth), pathCost(_pathCost) { };
  };

  class Problem {
  public:
    std::vector<Operator*> operators;
    State *initialState;
    // state space???
    virtual bool isGoal(State*) =0;
    virtual long pathCost(SearchNode*) =0;
  };

  class GeneralSearch {
  protected:
    std::deque<SearchNode*> Q;
    virtual void enqueue(SearchNode*) =0;
  public:
    SearchNode* search(Problem*);
  };
};

#endif /* end of include guard: __SEARCH_HPP__ */
