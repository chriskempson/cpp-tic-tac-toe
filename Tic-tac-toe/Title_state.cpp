/*
 * Tic Tac Toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#include "Title_state.h"
#include "Game.h"
#include "Setting.h"
#include "State_manager.h"
#include "Resource_manager.h"
#include "Play_state.h"
#include "About_state.h"

bool title_sound_has_played;

int tic_text_x;
int tac_text_x;
int toe_text_x;

void Title_state::init()
{
	Resource_manager::load_image("title_background");

	// Load the text images with an offset so the don't appear on the 
	// screen when first rendered
	Resource_manager::load_image("tic_text")->set_position(-100, 0);
	Resource_manager::load_image("tac_text")->set_position(-100, 0);
	Resource_manager::load_image("toe_text")->set_position(-100, 0);

	Resource_manager::load_sound("title");

	title_sound_has_played = false;

	// Image width is 20px hence the value used for the offset
	tic_text_x = -20;
	tac_text_x = Setting::window_width;
	toe_text_x = -20;
}

void Title_state::handle_events(SDL_Event* event)
{
	if (event->type == SDL_MOUSEBUTTONDOWN) {

		// Get mouse coords
		int x, y;
		SDL_GetMouseState(&x, &y);

		// Work out scaled distance from top right in pixels
		int from_right = (Setting::actual_window_width - x) / Setting::scale_factor;
		int from_top = y / Setting::scale_factor;

		// If click falls within 8px from right and 9px from top user has 
		// pressed the about button
		if (from_right < 8 && from_top < 9) {
			State_manager::set_state(new About_state());
		}
		else {
			State_manager::set_state(new Play_state());
		}
	}
}

void Title_state::update()
{
	// Animate title screen text
	if (tic_text_x < 13) {
		tic_text_x = tic_text_x + 3;
		Resource_manager::get_image("tic_text")->set_position(tic_text_x, 2);
	}
	else if (tac_text_x > 13) {

		if (!title_sound_has_played) {
			Resource_manager::get_sound("title")->play();
			title_sound_has_played = true;
		}

		tac_text_x = tac_text_x - 3;
		Resource_manager::get_image("tac_text")->set_position(tac_text_x + 2, 12);
	}
	else if (toe_text_x < 13) {
		toe_text_x = toe_text_x + 3;
		Resource_manager::get_image("toe_text")->set_position(toe_text_x, 22);
		if (toe_text_x > 47) toe_text_x = -9;
	}
}


void Title_state::render()
{
	Resource_manager::get_image("title_background")->render();
	Resource_manager::get_image("tic_text")->render();
	Resource_manager::get_image("tac_text")->render();
	Resource_manager::get_image("toe_text")->render();
}

void Title_state::clean_up()
{
	Resource_manager::unload_image("title_background");
	Resource_manager::unload_image("tic_text");
	Resource_manager::unload_image("tac_text");
	Resource_manager::unload_image("toe_text");

	Resource_manager::unload_sound("title");
}