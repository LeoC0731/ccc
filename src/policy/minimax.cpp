//[TODO] Design your own policy
#include <cstdlib>
#include <iostream>
#include <climits>

#include "../state/state.hpp"
#include "./minimax.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Minimax::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  int best_score = INT_MIN;
  int score = 0;
  int cnt = 0;
  int ans = 0;
  for(auto &x : state->legal_actions){
    score = minimax(state->next_state(x), depth - 1, state->player);
    if(score > best_score){
      ans = cnt;
    }
    cnt++;
  }
  
  auto actions = state->legal_actions;
  return actions[ans];
}

int Minimax::minimax(State *state, int depth, int cur_player){
  int best_score = 0;
/*
  if(!state->legal_actions.size())
    state->get_legal_actions();

  if(depth == 0 || state->game_state == WIN || state->game_state == DRAW){
    best_score = state->evaluate(cur_player);
    return best_score;
  }

  if(state->player == cur_player){
    best_score = INT_MIN;
  }
  else{
    best_score = INT_MAX;
  }

  
  for(auto &x : state->legal_actions){
    if(state->player == cur_player){
      int score = minimax(state->next_state(x), depth - 1, cur_player);
      if(score > best_score){
        best_score = score;
      }
    }
    else{
      int score = minimax(state->next_state(x), depth - 1, cur_player);
      if(score < best_score){
        best_score = score;
      }
    }
  }

*/
  return best_score;
} 