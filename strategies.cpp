#include "strategies.hpp"

namespace Search {
  class BF : GeneraSearch { 
		void enqueue(SearchNode &node){
			Q.push_back(node);
		}
  };
  class DF : GeneralSeach {
		void enqueue(SearchNode &node){
			Q.push_front(node);
		}
  };
  class ID : GeneralSeach {
  	void enqueue(SearchNode &node){
			Q.push_front(node);
		}
  };
  class BFS : GeneralSeach { 
  	virtual int f(State&) =0;
  	
		void enqueue(SearchNode &node){
			int fnode = f(node);
			for(deque<SearchNode&>::iterator it = Q.begin(); it != Q.end(); it++){
				if(f(it->state) > fnode){
					Q.insert(it, node);
					break;
				}
			}
		}
  };
};
