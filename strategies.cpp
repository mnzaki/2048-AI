#include <cstring>
#include <deque>
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
    std::deque<int>::iterator it_beg = fvalues.begin(),
                              it_end = fvalues.end(),
                              it     = lower_bound(it_beg, it_end, fnode);
    std::deque<SearchNode*>::iterator it2 = Q.begin();
    std::advance(it2, (it-it_beg));
    Q.insert(it2, node);
    fvalues.insert(it, fnode);
  }

};
