#include <vector>
#include <deque>

namespace Search {
  class State {
  };

  class Operator {
  public:
    State apply(State&);
  };

  class SearchNode {
  public:
    State &state;
    SearchNode &parent;
    Operator &operator;
    unsigned long depth;
    long pathCost;

    SearchNode();
    SearchNode(State&, SearchNode&, Operator&, unsigned long, long);
  };

  class Problem {
  public:
    std::vector<Operator&> operators;
    State initialState;
    // state space???
    bool isGoal(State&);
    long pathCost(Node&);
  };

  class GeneralSearch {
  private:
    deque<SearchNode&> Q;
    void enqueue(SearchNode);
  public:
    vector<SearchNode&> search(Problem&);
  };
};
