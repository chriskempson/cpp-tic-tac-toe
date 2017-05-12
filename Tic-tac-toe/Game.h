/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#pragma once
#include <SDL.h>

/**
 * Provides the core of the game application: window management,
 * event capture, render area, main game loop and any helper
 * functions related to the game
 */
class Game
{
public:
	~Game();

	/**
	 * Gets an instance of an SDL_Window
	 *
	 * @return Pointer to instance
	 */
	static SDL_Window* get_window();

	/**
	 * Gets an instance of an SDL_Renderer
	 *
	 * @return Pointer to instance
	 */
	static SDL_Renderer* get_renderer();

	/**
	 * SDL setup an initialisation
	 *
	 * @param title Application window title
	 * @param window_width Application window width
	 * @param window_height Application window height
	 *
	 * @return True if initialisation was successful
	 */
	bool init(char* title, int window_width, int window_height);

	/**
	* Runs the game loop until stop() is called
	*/
	void run();

	/**
	 * Stops the game loop started by run() and cleans up SDL variables
	 */
	void stop();
};