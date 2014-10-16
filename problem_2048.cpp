#include "problem_2048.hpp"
#include <cstdlib>
#include <cstring>
#include <cmath>

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

Problem2048::Problem2048(Problem2048::State *state, unsigned k) {
  unsigned pos;

  M = pow(2, k);
  initialState = state;
  if(initialState == NULL){
    initialState = new Problem2048::State(false);
  }

  score_lut = new unsigned[k+1];
  score_lut[0] = 0;
  while (k > 0) {
    score_lut[k] = pow(2, k) * (k-1);
    k--;
  }
}

bool Problem2048::isGoal(Search::State *s) {
  Problem2048::State *state = (Problem2048::State*) s;
  for (int i = 0; i < 16; i++) {
    if (state->board[i/4][i%4] == M) return true;
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

  unsigned x, y, x2, y2, vx, vy;

  switch (move) {
  case UP:
    x = 0; y = 0;
    vx = 0; vy = 1;
    break;
  case DOWN:
    x = 3; y = 3;
    vx = 0; y = -1;
  case LEFT:
    x = 0; y = 0;
    vx = 1; vy = 0;
  case RIGHT:
    x = 3; y = 3;
    vx = -1; vy = 0;
  };

  while (x >= 0 && x < 4 && y >= 0 && y < 4) {
    x2 = x; y2 = y;
    newState->board[x][y] = state->board[x2][y2];
    x2 += vx; y2 += vy;
    while (x2 >= 0 && x2 < 4 && y2 >= 0 && y2 < 4 && !state->board[x2][y2]) {
      if (state->board[x2][y2]) {
        if (state->board[x2][y2] == newState->board[x][y]) {
          // it's the same tile, merge it
          newState->board[x][y] += 1;
          x += vx; y += vy;
        } else {
          // just move it
          if (newState->board[x][y]) x += vx; y += vy;
          newState->board[x][y] = state->board[x2][y2];
        }
      }
      x2 += vx; y2 += vy;
    }
    x += vy; y = vx;
  }

  return newState;
}
