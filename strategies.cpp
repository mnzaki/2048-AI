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
    int fnode = f(node->state);
    for(std::deque<SearchNode*>::iterator it = Q.begin(); it != Q.end(); it++){
      if(f((*it)->state) > fnode){
        Q.insert(it, node);
        break;
      }
    }
  }
};
