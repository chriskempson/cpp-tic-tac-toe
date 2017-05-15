/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#pragma once
#include <string>

/**
 * Contains common setting variables for the game
 *
 * See settings.cpp for defined values that do not appear here.
 */
struct Setting
{
	/// Name that appears in the application titlebar
	static char* game_name; 

	/// Path to the icon that appears in the application titlebar
	static char* icon_path;

	/// Path to images relative to the source files, must end with a trailing
	/// slash
	static const std::string image_path;

	/// Path to sounds relative to the source files, must end with a trailing
	/// slash
	static const std::string sound_path;

	/// Set first element to -1 to disable colour keying, otherwise set to a 
	/// colour such as { 0, 0xFF, 0xFF }
	static const int color_key[];

    /// Set a background colour for the renderer
    static const int background_color[];

	/// Set to false for peaceful development
	static const bool play_sounds = true;

	/// Changing the scale factor adjusts the size of the images and the 
	/// playing window
	static const int scale_factor = 8;

	/// Width of the clipped sprite sheet image used for the grid
	static const int grid_sprite_width = 16;

	/// Height of the clipped sprite sheet image used for the grid
	static const int grid_sprite_height = 16;

	/// Amount of columns to draw for the grid, changing this will affect
	/// window_width and actual_window_width
	static const int grid_columns = 3;

	/// Amount of rows to draw for the grid, changing this will affect
	/// window_height and actual_window_height
	static const int grid_rows = 3;

	/// The amount of consecutive player pieces in a row, column or diagonal 
	/// required for a win
	static const int win_count = 3;

	// Subtracting 1 from the window_width and window_height will hide part of 
	// the repeating grid image that we don't want to see

	/// Width of the application window
	static const int window_width = grid_columns * grid_sprite_width - 1;

	/// Height of the application window
	static const int window_height = grid_rows * grid_sprite_height - 1;

	/// Width of the playing area without the scaling factor applied
	static const int actual_window_width = window_width * scale_factor;

	/// Height of the playing area without the scaling factor applied
	static const int actual_window_height = window_height * scale_factor;
};