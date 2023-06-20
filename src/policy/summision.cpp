//[TODO] Design your own policy
#include <cstdlib>
#include <iostream>
#include <climits>

#include "../state/state.hpp"
#include "./summision.hpp"


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
  
  int best_score = 1000000;
  int score = 0;
  int cnt = 0;
  int ans = 0;
  
  for(auto &x : state->legal_actions){
    score = minimax(state->next_state(x), depth - 1, state->player);
    if(score > best_score){
      ans = cnt;
      best_score = score;
    }
    cnt += 1;
  }
  auto actions = state->legal_actions;
  return actions[ans];
}

int Minimax::minimax(State *state, int depth, int cur_player){
  int best_score = 0;
  int value;

  if(!state->legal_actions.size())
    state->get_legal_actions();

  if(depth == 0){
    best_score = state->evaluate(cur_player);
    if(cur_player == state->player) return best_score;
    else return -best_score;
  }


  if(state->game_state == WIN){
    if(state->player == cur_player) return 100000;
    else return -100000;
  }

  if(state->player == cur_player){
    best_score = -1000000;
    for(auto &x : state->legal_actions){
      value = minimax(state->next_state(x), depth - 1, cur_player);
      if(value > best_score){
        best_score = value;
      }
    }
  }
  else{
    best_score = 1000000;
    for(auto &x : state->legal_actions){
      value = minimax(state->next_state(x), depth -1, cur_player);
      if(value < best_score){
        best_score = value;
      }
    }
  }
  return best_score;
} 