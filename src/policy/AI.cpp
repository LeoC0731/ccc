//[TODO] Design your own policy
#include <cstdlib>
#include <iostream>
#include <climits>

#include "../state/state.hpp"
#include "./AI.hpp"


/**
 * @brief Use MinMax to get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move
 */


pim AI::get_move_minimax(State *state, int depth, int current_player){
  	// Initialize best move
	Move best_move = std::make_pair(std::make_pair(0, 0), std::make_pair(0, 0));
  int best_score;
  if(state->player != current_player){
    best_score = INT_MIN;
  }
  else{
    best_score = INT_MAX;
  }

  if(!state->legal_actions.size())
    state->get_legal_actions();

	// If we hit a terminal state (leaf node), return the best score and move
  if(depth == 0 || state->game_state == WIN || state->game_state == DRAW){
    best_score = state->evaluate(current_player);
    return std::make_pair(best_score, best_move);
  }

  for(auto x : state->legal_actions){
    if(state->player != current_player){//max player
      int score = get_move_minimax(state->next_state(x), depth - 1, current_player).first;
      if(score > best_score){
        best_move = x;
        best_score = score;
      }
    }
    else{//min opponent
      int score = get_move_minimax(state->next_state(x), depth - 1, current_player).first;
      if(score < best_score){
        best_move = x;
        best_score = score;
      }
    }
  }

	return std::make_pair(best_score, best_move);
}

/*
int AI::minimax(State *state, int depth){
  int best_score;
  Move best_move;
  if(!state->legal_actions.size())
    state->get_legal_actions();
  for(auto x : state->legal_actions){
    State* n_state = state->next_state(x);
    if(best_score < n_state->evaluate()){
      best_score = n_state->evaluate();
    }
  }
  return best_score;
}
*/