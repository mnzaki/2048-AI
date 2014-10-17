#include <cstring>
#include <deque>
#include "strategies.hpp"
#include <iostream>
#include <memory>

namespace Search {
  void BF::enqueue(std::shared_ptr<SearchNode> node){
    Q.push_back(node);
  }
  void DF::enqueue(std::shared_ptr<SearchNode> node){
    Q.push_front(node);
  }
  void ID::enqueue(std::shared_ptr<SearchNode> node){
    if (node->depth <= limit) {
      Q.push_front(node);
    } else if (Q.empty() && limit < maxLimit) {
      limit++;
      while (node->parent != NULL) node = node->parent;
      Q.push_front(node);
    }
  }

  void BFS::enqueue(std::shared_ptr<SearchNode> node){
    while(fvalues.size()>Q.size()) fvalues.pop_front();
    int fnode = f(node.get());
    std::deque<int>::iterator it = lower_bound(fvalues.begin(), fvalues.begin(), fnode);
    fvalues.insert(it, fnode);
    std::deque<std::shared_ptr<SearchNode> >::iterator it2 = Q.begin();
    std::advance(it2, it-fvalues.begin());
    Q.insert(it2, node);
  }

};
