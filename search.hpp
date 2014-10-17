#ifndef __SEARCH_HPP__
#define __SEARCH_HPP__

#include <vector>
#include <string>
#include <deque>
#include <string>
#include <memory>

namespace Search {
  class State {
  public:
    virtual std::string visualize(void) =0;
  };

  class Operator {
  public:
    virtual State* apply(State*) =0;
    virtual std::string print() =0;
  };

  class SearchNode {
  public:
    static unsigned obj_count;
    State *state;
    std::shared_ptr<SearchNode> parent;
    Operator *op;
    unsigned long depth;
    long pathCost;

    /*SearchNode(State *_state, SearchNode *_parent, Operator *_op,
              unsigned long _depth, long _pathCost) :
      state(_state), parent(_parent), op(_op),
      depth(_depth), pathCost(_pathCost) { };*/
    SearchNode(State *_state, std::shared_ptr<SearchNode> _parent, Operator *_op,
              unsigned long _depth, long _pathCost) :
      state(_state), parent(_parent), op(_op),
      depth(_depth), pathCost(_pathCost) { obj_count++; };
    ~SearchNode() { delete state; obj_count--; }
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
    std::deque<std::shared_ptr<SearchNode> > Q;
    virtual void enqueue(std::shared_ptr<SearchNode>) =0;
  public:
    std::shared_ptr<SearchNode> search(Problem*);
  };
};

#endif /* end of include guard: __SEARCH_HPP__ */
