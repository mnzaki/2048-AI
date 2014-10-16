#include <iostream>
#include <cmath>
#include <stack>

using namespace Search;
using namespace std;

Problem2048::State GenGrid(){
  return Problem2048::State(false);
}

void Search(Problem2048::State *grid, int M, Search::GeneralSearch *strategy, bool visualize){
  Problem2048::Problem2048 problem(grid, (int)round(log(M)/log(2)));
  SearchNode *node = strategy.search(problem);
  int totalCost = node->pathCost;
  stack<Search::SearchNode*> stk;
  while(node->parent != NULL) {
    stk.push(node);
    node = node->parent;
  }
  

}

int main(){
  int m, visualize;
  Search::GeneralSearch strategy;
  string sstrategy;

  cout << "Enter m(the required power of 2 goal):";
  cin >> m;
  cout << "Enter the strategy(BF, DF, ID , GRi, ASi)";
  cin >> sstrategy;
  cout << "Enter 1 if you need to visualize the result, 0 insted:"
  cin >> visualize;

  if(sstrategy.substr(0,2) == "BF") strategy = Search::BF();
  else if(sstrategy.substr(0,2) == "DF") strategy = Search::DF();
  else if(sstrategy.substr(0,2) == "ID") strategy = Search::ID();
  else if(sstrategy.substr(0,3) == "GR1") strategy = Search::GR1();
  else if(sstrategy.substr(0,3) == "GR2") strategy = Search::GR2();
  else if(sstrategy.substr(0,3) == "AS1") strategy = Search::AS1();
  else if(sstrategy.substr(0,3) == "AS2") strategy = Search::AS2();

  Search(&GenGrid(), pow(2,m), &strategy, visualize==1);

  return 0;
}
