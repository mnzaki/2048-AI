#include <cstring>
#include <deque>
#include <iostream>
#include "strategies.hpp"

namespace Search {
  void BF::enqueue(SearchNode *node){
    Q.push_back(node);
  }
  void DF::enqueue(SearchNode *node){
    Q.push_front(node);
  }
  void ID::enqueue(SearchNode *node){
    if (node->depth <= limit) {
      Q.push_front(node);
    } else if (Q.empty() && limit < maxLimit) {
      limit++;
      while (node->parent != NULL) node = node->parent;
      Q.push_front(node);
    }
  }

  void BFS::enqueue(SearchNode *node){
    while(fvalues.size()>Q.size()) fvalues.pop_front();
    int fnode = f(node);
    std::deque<int>::iterator it = lower_bound(fvalues.begin(), fvalues.begin(), fnode);
    std::deque<SearchNode*>::iterator it2 = Q.begin();
    std::advance(it2, (int)(it-fvalues.begin()));
    fvalues.insert(it, fnode);
    Q.insert(it2, node);
  }

};
