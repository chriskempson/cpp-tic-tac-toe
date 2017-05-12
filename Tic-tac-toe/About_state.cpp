/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#include "About_state.h"
#include "Game.h"
#include "State_manager.h"
#include "Resource_manager.h"
#include "Title_state.h"

void About_state::init()
{
	Resource_manager::load_image("about");
	Resource_manager::load_sound("about")->play();
}

void About_state::handle_events(SDL_Event* event)
{
	if (event->type == SDL_MOUSEBUTTONDOWN) {
		State_manager::set_state(new Title_state());
	}
}

void About_state::update()
{
	// Not much to do in this kind of game
}

void About_state::render()
{
	Resource_manager::get_image("about")->render();
}

void About_state::clean_up()
{
	Resource_manager::unload_image("about");
	Resource_manager::unload_sound("about");
}