/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#pragma once
#include <SDL.h>
#include "Setting.h"

/**
 * Rendering and logic for the game's grid and cells.
 *
 * The grid refers to the board upon which the game is played. The cells are
 * the areas within the board upon which a play can be made.
 */
class Grid
{
public:
	/// Player names stored as an enum for easy reference
	enum players { player_red = 1, player_yellow = 2 };

	/// Names of sprites stored as an enum for easy reference
	enum sprite_sheet { sprite_blank, sprite_red, sprite_yellow };

	/// Holds data about a cell for a Grid
	struct Cell {

		/// Location of a sprite
		SDL_Point position;

		/// Current part of a sprite sheet to display
		sprite_sheet current_sprite = sprite_blank;
	};

	/// An array of cells that describes the grid
	Cell cell[Setting::grid_columns][Setting::grid_rows];

	/**
	 * Initialises the grid state
	 */
	void init();

	/**
	 * Draws a grid
	 */
	void render();

	/**
	 * Clears the grid of any current plays
	 */
	void clear();

	/**
	 * Check to see if a player has won the game
	 *
	 * A win can come from a row, column or diagonal count of consecutive 
	 * player moves.
	 *
	 * @param col Grid column number to run check from
	 * @param row Grid row number to run check from
	 * @param sprite Grid sprite image to check cell for
	 * @return True if a win was found
	 */
	bool check_for_win(int col, int row, sprite_sheet sprite);

	/**
	 * Check to see neither player has won the game but the game has ended.
	 *
	 * A draw will happen with neither player has won but no more moves can be played.
	 *
	 * @return True if a win was found
	 */
	bool check_for_draw();

private:
	/// Contains coords of clipping rectangles for the cell sprite sheet
	SDL_Rect sprite_clips[3];

	/**
	 * Used by check_for_X_win functions when printing debug messages
	 *
	 * @param sprite Value from enum sprite_sheet
	 * @return Name of a player
	 */
	const char* get_player_name(int sprite);

	/**
	 * @see check_for_win() for documentation of these member functions
	 */
	bool check_for_row_win(int col, int row, sprite_sheet sprite);
	bool check_for_column_win(int col, int row, sprite_sheet sprite);
	bool check_for_forwards_diagonal_win(int col, int row, sprite_sheet sprite);
	bool check_for_backwards_diagonal_win(int col, int row, sprite_sheet sprite);
};