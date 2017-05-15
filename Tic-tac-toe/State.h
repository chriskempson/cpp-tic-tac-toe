/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#pragma once
#include <SDL.h>

/**
 * Abstract class for state interface
 *
 * Games typically have many states that often need to perform the same
 * functions. For example a menu state for when the game is display the menu,
 * a playing state for when the actual gameplay is happening and so on.
 */
class State
{
public:
	/**
	 * Called when a state is loaded to initialise memory for a state
	 */
	virtual void init() = 0;

	/**
	 * Called first in the game loop to handle game events such as button
	 * presses, mouse clicks, window resizing and so on.
	 */
	virtual void handle_events(SDL_Event& event) = 0;

	/**
	 * Called second in the game loop to update game items such as character 
	 * positions, scores and so on. All game logic will be handled here.
	 */
	virtual void update() = 0;

	/**
	 * Called third in the game loop to render items to the game window. This
	 * should be the only area that items are rendered within.
	 */
	virtual void render() = 0;

	/**
	 * Called when a state is unloaded to free memory for a state
	 */
	virtual void clean_up() = 0;
};