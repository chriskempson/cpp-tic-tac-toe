/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#pragma once
#include <SDL.h>
#include "State.h"

/**
 * State implementation for handling the title screen state
 *
 * See State class for documentation on init(), handle_events(), update(),
 * render() and clean_up().
 */
class Title_state : public State
{
public:
	void init();
	void handle_events(SDL_Event& event);
	void update();
	void render();
	void clean_up();
};
