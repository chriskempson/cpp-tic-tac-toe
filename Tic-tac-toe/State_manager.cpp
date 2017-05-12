/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#include "State_manager.h"

std::vector<State*> State_manager::states;

void State_manager::set_state(State* state)
{
	// Call clean_up() on the old state free it from memory and remove it 
	// from the vector
	if (!states.empty()) {

		// Call clean up function on state to free a state's memory
		states.back()->clean_up();

		// Delete instance since it was created with new
		delete states.back();
		states.back() = NULL;

		// Remove unneeded entry from vector
		states.pop_back();
	}

	// Store the new state and call its init()
	states.push_back(state);
	states.back()->init();
}

State* State_manager::get_state() {
	return states.back();
}