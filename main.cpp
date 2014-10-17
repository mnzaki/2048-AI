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

  if (node == NULL) {
    std::cout << "No solution found for:\n" << problem.initialState->visualize();
  } else {
    stack<Search::SearchNode*> stk;
    stk.push(node); node = node->parent;
    int totalCost = node->pathCost;

    if (visualize) {
      do {
        stk.push(node);
        node = node->parent;
      } while(node != NULL);
    }
    while (!stk.empty()){
      node = stk.top(); stk.pop();
      if (visualize && node->op) {
        cout << "Move " << node->op->print() << std::endl;
      }
      std::cout << ((Problem2048::State*)node->state)->visualize();
    }
    cout << "Total Path Cost = " << totalCost << std::endl;
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
  // else if(sstrategy.substr(0,3) == "GR1") strategy = new Search::GR1();
  // else if(sstrategy.substr(0,3) == "GR2") strategy = new Search::GR2();
  // else if(sstrategy.substr(0,3) == "AS1") strategy = new Search::AS1();
  // else if(sstrategy.substr(0,3) == "AS2") strategy = new Search::AS2();

  SearchP(NULL, pow(2,m), strategy, visualize==1);

  return 0;
}
