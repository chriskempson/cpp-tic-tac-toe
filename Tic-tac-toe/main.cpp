/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#include <iostream>
#include <string>
#include "Game.h"
#include "Setting.h"
#include "State_manager.h"
#include "Title_state.h"

// App entry point
int main(int argc, char* args[])
{
	Game game;

	if (!game.init(Setting::game_name, Setting::window_width, Setting::window_height)) {
		std::cout << "Application initialisation error. Exiting. " << std::endl;
	}

	State_manager::set_state(new Title_state());

	game.run();
	return 0;
}