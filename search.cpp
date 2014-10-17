#include <cstring>
#include <ctime>
#include <iostream>
#include "search.hpp"

using namespace Search;

unsigned SearchNode::obj_count = 0;

SearchNode* GeneralSearch::search(Problem* P) {
  SearchNode *node = new SearchNode(P->initialState, NULL, NULL, 0, 0);
  unsigned max_depth = 0;
  std::time_t begin_ts = std::time(0);

  enqueue(node);

  for (;;) {
    bool hasChildren = false;

    if (Q.empty()) return NULL;
    node = Q.front();
    Q.pop_front();
    if (P->isGoal(node->state)) return node;
    for (unsigned i = 0, n = P->operators.size(); i < n; i++) {
      State *newState = P->operators[i]->apply(node->state);

      if (newState != NULL) {
        SearchNode *newNode = new SearchNode(newState, node, P->operators[i],
                                       node->depth+1, 0);
        newNode->pathCost = P->pathCost(newNode);

        if (newNode->depth > max_depth) {
          std::time_t ts = std::time(0) - begin_ts;
          max_depth = newNode->depth;
          std::cout << ts << "s: depth = " << max_depth-1 << ", obj_count = " << SearchNode::obj_count-1 << std::endl;
        }
        enqueue(newNode);
        hasChildren = true;
      }
    }
    if (!hasChildren) delete node;
  }
}
