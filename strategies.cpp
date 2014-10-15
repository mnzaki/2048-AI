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
  class GR1 : GeneralSeach { };
  class GR2 : GeneralSeach { };
  class AS1 : GeneralSeach { };
  class AS2 : GeneralSeach { };
};
