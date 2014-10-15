#include <vector>
#include <deque>

namespace Search {
  class State { };

  class Operator {
  public:
    virtual State& apply(State&) =0;
  };

  class SearchNode {
  public:
    State &state;
    SearchNode &parent;
    Operator &op;
    unsigned long depth;
    long pathCost;

    SearchNode(State& _state, SearchNode& _parent, Operator& _op,
              unsigned long _depth, long _pathCost) :
      state(_state), parent(_parent), op(_op),
      depth(_depth), pathCost(pathCost_) { };
  };

  class Problem {
  public:
    std::vector<Operator&> operators;
    State &initialState;
    // state space???
    virtual bool isGoal(State&) =0;
    virtual long pathCost(Node&) =0;
  };

  class GeneralSearch {
  private:
    std::deque<SearchNode&> Q;
    virtual void enqueue(SearchNode&) =0;
  public:
    SearchNode& search(Problem&);
  };
};
