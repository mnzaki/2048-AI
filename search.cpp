#include "search.hpp"

using namespace Search;

SearchNode& GeneralSearch::search(Problem& P) {
  SearchNode &node = new SearchNode(P.initialState, NULL, NULL, 0, 0);
  enqueue(node);

  for (;;) {
    if (Q.empty()) return NULL;
    node = Q.pop_front();
    if (P.isGoal(node.state)) return node;
    for (unsigned i = 0, n = P.operators.size(); i < n; i++) {
      State &newState = P.operators[i].apply(N.state);
      if (newState != NULL) {
        Node &newNode = new SearchNode(newState, node, P.operators[i],
        node.depth+1, 0);
        newNode.pathCost = P.pathCost(newNode);
        enqueue(newNode);
      }
    }
  }
}