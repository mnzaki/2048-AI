#include "problem_2048.hpp"
#include "strategies.hpp"
#include <iostream>
#include <cmath>
#include <stack>
#include <memory>

using namespace Search;
using namespace std;

Problem2048::State* GenGrid(){
  return new Problem2048::State(false);
}

void SearchP(Problem2048::State *grid, int M, Search::GeneralSearch *strategy, bool visualize){
  Problem2048 problem(grid, (int)round(log(M)/log(2.0)));
  std::shared_ptr<SearchNode> node = strategy->search(&problem);

  if (!node) {
    std::cout << "No solution found for:\n" << problem.initialState->visualize();
  } else {
    stack<std::shared_ptr<Search::SearchNode> > stk;
    int totalCost = node->pathCost;
    int depth = node->depth;
    if (visualize) {
      while (node->parent) {
        stk.push(node);
        node.swap(node->parent);
      }
    }
    // always push at least 1 node (solution), or last node after visualize loop
    stk.push(node);
    while (!stk.empty()){
      node = stk.top(); stk.pop();
      if (visualize && node->op) {
        cout << "Move " << node->op->print() << std::endl;
      }
      std::cout << ((Problem2048::State*)node->state)->visualize();
    }
    cout << "Depth = " << depth << ", " << "Total Path Cost = " << totalCost << std::endl;
  }
}

int main(int argc, char *argv[]){
  int m, visualize;
  Search::GeneralSearch *strategy;
  string sstrategy;

  if (argc < 3) {
    cout << "Enter m(the required power of 2 goal): ";
    cin >> m;
    cout << "Enter the strategy(BF, DF, ID , GRi, ASi): ";
    cin >> sstrategy;
    cout << "Enter 1 if you need to visualize the result, 0 insted: ";
    cin >> visualize;
  } else {
    sscanf(argv[1], "%d", &m);
    sstrategy = argv[2];
    sscanf(argv[3], "%d", &visualize);
  }

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
