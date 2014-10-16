#include "problem_2048.hpp"
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>

// State stores n, not 2^n
Problem2048::State::State(bool empty) {
  memset(board, 0, sizeof(board));
  if(!empty){
    unsigned pos;
    pos = std::rand() % 16;
    board[pos/4][pos%4] = 1;
    pos = std::rand() % 16;
    board[pos/4][pos%4] = 1;
  }
}

std::string Problem2048::State::visualize(void) {
  std::stringstream ss;
  //ss << std::setw(5) << std::setfill('0');
  for (int y = 0; y < 4; y++) {
    ss << "| ";
    for (int x = 0; x < 4; x++) {
      ss << board[y][x] << " | ";
    }
    ss << std::endl;
  }
  return ss.str();
}

Problem2048::Problem2048(Problem2048::State *state, unsigned _k) : k(_k) {
  initialState = state;
  if(initialState == NULL){
    initialState = new Problem2048::State(false);
  }

  score_lut = new unsigned[k+1];
  for (int i = 0; i < k; i++) {
    score_lut[i] = pow(2, i) * (i-1);
  }

  Problem2048::Operator *op;
  op = new Problem2048::Operator(Problem2048::Operator::UP);
  operators.push_back(op);
  op = new Problem2048::Operator(Problem2048::Operator::DOWN);
  operators.push_back(op);
  op = new Problem2048::Operator(Problem2048::Operator::LEFT);
  operators.push_back(op);
  op = new Problem2048::Operator(Problem2048::Operator::RIGHT);
  operators.push_back(op);
}

bool Problem2048::isGoal(Search::State *s) {
  Problem2048::State *state = (Problem2048::State*) s;
  for (int i = 0; i < 16; i++) {
    if (state->board[i/4][i%4] == k) return true;
  }
  return false;
}

long Problem2048::pathCost(Search::SearchNode *node) {
  unsigned score = 0;
  Problem2048::State *state = (Problem2048::State*) node->state;
  for (int i = 0; i < 16; i++) {
    score += score_lut[state->board[i/4][i%4]];
  }
  return score;
}

Search::State* Problem2048::Operator::apply(Search::State *s) {
  Problem2048::State *state = (Problem2048::State*) s;
  Problem2048::State *newState = new Problem2048::State();

  int x, y, x2, y2, vx, vy;

  switch (move) {
  case UP:
    x = 0; y = 0;
    vx = 0; vy = 1;
    break;
  case DOWN:
    x = 3; y = 3;
    vx = 0; vy = -1;
    break;
  case LEFT:
    x = 0; y = 0;
    vx = 1; vy = 0;
    break;
  case RIGHT:
    x = 3; y = 3;
    vx = -1; vy = 0;
    break;
  };

#if DEBUG
  std::cout << "APPLY" << std::endl;
  std::cout << x << " " << y << " " << vx << " " << vy << std::endl;
#endif

  while (x >= 0 && x < 4 && y >= 0 && y < 4) {
    x2 = x; y2 = y;
    newState->board[y][x] = state->board[y2][x2];
    x2 += vx; y2 += vy;
    while (x2 >= 0 && x2 < 4 && y2 >= 0 && y2 < 4) {
      if (state->board[y2][x2]) {
        if (state->board[y2][x2] == newState->board[y][x]) {
          // it's the same tile, merge it
          newState->board[y][x] += 1;
          x += vx; y += vy;
        } else {
          // just move it
          if (newState->board[y][x]) { x += vx; y += vy; }
          newState->board[y][x] = state->board[y2][x2];
        }
      }
      x2 += vx; y2 += vy;
    }
    x += vy; y += vx;
  }
#if DEBUG
  std::cout << "FROM: \n" << state->visualize() << "TO: \n" << newState->visualize() << "\n\n";
#endif
  return newState;
}

std::string Problem2048::Operator::print() {
  switch(move){
    case Problem2048::Operator::UP:
      return "Up";
    case Problem2048::Operator::DOWN:
      return "Down";
    case Problem2048::Operator::LEFT:
      return "Left";
    case Problem2048::Operator::RIGHT:
      return "Right";
  }
  return "NONE";
}

int Problem2048::GR1::f(Search::State *s){
  return 0;
}
int Problem2048::GR2::f(Search::State *s){
  return 0;
}
int Problem2048::AS1::f(Search::State *s){
  return 0;
}
int Problem2048::AS2::f(Search::State *s){
  return 0;
}
