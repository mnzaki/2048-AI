#include "problem_2048.hpp"
#include "strategies.hpp"
#include <iostream>
#include <cmath>
#include <stack>

using namespace Search;
using namespace std;

Problem2048::State* GenGrid(){
  return new Problem2048::State(false);
}

void SearchP(Problem2048::State *grid, int M, Search::GeneralSearch *strategy, bool visualize){
  Problem2048 problem(grid, (int)round(log(M)/log(2.0)));

  SearchNode *node = strategy->search(&problem);

  int totalCost = node->pathCost;
  stack<Search::SearchNode*> stk;

  int x=0;
  while(node->parent != NULL) {
    stk.push(node);

    node = node->parent;
    if(x==10) break;
    x++;
  }


  if(visualize) node->state->visualize();
  while(!stk.empty()){
    node = stk.top(); stk.pop();
    cout << "Move " << node->op->print();
    if(visualize) node->state->visualize();
  }

  cout << "Total Path Cost = " << totalCost;
}

int main(){
  int m, visualize;
  Search::GeneralSearch *strategy;
  string sstrategy;

  cout << "Enter m(the required power of 2 goal): ";
  cin >> m;
  cout << "Enter the strategy(BF, DF, ID , GRi, ASi): ";
  cin >> sstrategy;
  cout << "Enter 1 if you need to visualize the result, 0 insted: ";
  cin >> visualize;

  if(sstrategy.substr(0,2) == "BF") strategy = new Search::BF();
  else if(sstrategy.substr(0,2) == "DF") strategy = new  Search::DF();
  else if(sstrategy.substr(0,2) == "ID") strategy = new Search::ID();
  else if(sstrategy.substr(0,3) == "GR1") strategy = new Problem2048::GR1();
  else if(sstrategy.substr(0,3) == "GR2") strategy = new Problem2048::GR2();
  else if(sstrategy.substr(0,3) == "AS1") strategy = new Problem2048::AS1();
  else if(sstrategy.substr(0,3) == "AS2") strategy = new Problem2048::AS2();

  SearchP(NULL, pow(2,m), strategy, visualize==1);

  return 0;
}
