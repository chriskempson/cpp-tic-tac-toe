/*
 * Tic Tac Toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#include <iostream>
#include <string>
#include <SDL_mixer.h>
#include "Game.h"
#include "Setting.h"
#include "State_manager.h"
#include "Resource_manager.h"
#include "Title_state.h"

// Flag used by run() and stop() to check if the game should stop running
bool running = true;

// Points to an instance of SDL_Event returned by get_window()
SDL_Event* event = new SDL_Event();

// Points to an instance of SDL_CreateWindow returned by get_window()
SDL_Window* window = NULL;

// Points to an instance of SDL_CreateRenderer returned by get_renderer()
SDL_Renderer* renderer = NULL;

Game::~Game()
{
	// Delete member variables
	delete event;
	event = NULL;

	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	// Quit SDL subsystems
	Mix_Quit();
	SDL_Quit();
}

SDL_Window* Game::get_window()
{
	return window;
}

SDL_Renderer* Game::get_renderer()
{
	return renderer;
}

bool Game::init(char* title, int window_width, int window_height)
{
	// Initialise SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	// Create window
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width * Setting::scale_factor, window_height * Setting::scale_factor, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return false;
	}

	// Set titlebar icon
	if (Setting::icon_path) {
		SDL_Surface* icon = SDL_LoadBMP(Setting::icon_path);
		if (icon == NULL) {
			std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
			return false;
		}
		SDL_SetWindowIcon(window, icon);
	}

	// Create renderer for window
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return false;
	}

	// Initialise SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		std::cout << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
		return false;
	}

	return true;
}

void Game::run()
{
	while (running)
	{
		// Loop until all pending events have left the queue 
		while (SDL_PollEvent(event)) {

			// Let the state handle events
			State_manager::get_state()->handle_events(event);

			// Handle window quit event
			if (event->type == SDL_QUIT) {
				Game::stop();
			}
		}

		// Update data of the state
		State_manager::get_state()->update();

		// Clear screen
		SDL_RenderClear(renderer);

		// Render the state
		State_manager::get_state()->render();

		// Update screen taking into account SDL v-sync. This is what stops the 
		// game loop from running too fast
		SDL_RenderPresent(renderer);

	}
}

void Game::stop()
{
	running = false;
}