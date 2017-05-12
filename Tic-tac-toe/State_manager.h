/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#pragma once
#include <vector>
#include "State.h"

/**
 * Manages the current game state
 */
class State_manager
{
public:
	/**
	 * Set the current state to run
	 *
	 * The current state will be called from the Game::run() loop
	 *
	 * @param state Instance of a state to run
	 */
	static void set_state(State* state);

	/**
	 * Gets the current running state
	 *
	 * @return Instance of the current state
	 */
	static State* get_state();

private:
	/// Stores pointers to instances of a State
	static std::vector<State*> states;
};