#include <cstring>
#include <ctime>
#include <iostream>
#include <memory>
#include "search.hpp"

using namespace Search;

unsigned SearchNode::obj_count = 0;

std::shared_ptr<SearchNode> GeneralSearch::search(Problem* P) {
  unsigned max_depth = 0;
  std::time_t begin_ts = std::time(0);

  std::shared_ptr<SearchNode> node =
    std::make_shared<SearchNode>(P->initialState, nullptr, (Operator*)0, 0, 0);
  enqueue(node);

  for (;;) {
    if (Q.empty()) return nullptr;
    node = Q.front(); Q.pop_front();

    if (P->isGoal(node->state))
      return node;

    for (unsigned i = 0, n = P->operators.size(); i < n; i++) {
      State *newState = P->operators[i]->apply(node->state);

      if (newState != NULL) {
        std::shared_ptr<SearchNode> newNode =
          std::make_shared<SearchNode>(newState, node, P->operators[i],
                                       node->depth+1, 0);
        newNode->pathCost = P->pathCost(&(*newNode));

        if (newNode->depth > max_depth) {
          std::time_t ts = std::time(0) - begin_ts;
          max_depth = newNode->depth;
          std::cout << ts << "s: depth = " << max_depth-1 << ", obj_count = " << SearchNode::obj_count-1 << std::endl;
        }
        enqueue(newNode);
      }
    }
  }
  return nullptr;
}
