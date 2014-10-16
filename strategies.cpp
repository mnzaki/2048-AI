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
    Q.push_front(node);
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
