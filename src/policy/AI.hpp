#pragma once
#include "../state/state.hpp"

typedef std::pair<int, Move> pim;

/**
 * @brief Policy class for MinMax policy, 
 * your policy class should have get_move method
 */

class AI{
public:
  static pim get_move_minimax(State *state, int depth, int current_player);//best score & best move
};