/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#pragma once
#include <SDL.h>
#include "Resource.h"

/**
 * Resource interface implementation for handling image files
 */
class Image_resource : public Resource
{
public:
	Image_resource();
	~Image_resource();

	/**
	 * See Resource Class for documentation
	 */
	bool load_from_file(char* file);

	/**
	 * Sets the position of an image to be read by render()
	 *
	 * Scale factor is taken into consideration. For example your window 
	 * width is 100 before a scale factor of x2, 100 will remain the max width 
	 * before the element appears to move off the screen.
	 *
	 * @param x Number of pixels from the left of the screen 
	 * @param y Number of pixels from the top of the screen
	 */
	void set_position(int x = 0, int y = 0);

	/**
	 * Renders the image to renderer
	 *
	 * @param clip_rect optional rectangle for sprite sheet clipping
	 */
	void render(SDL_Rect* clip_rect = NULL);

private:
	/// Pointer to the image file stored as an SDL_Texture
	SDL_Texture* texture;

	/// Width of the image not including scale factor
	int width;
	
	/// Height of the image not including scale factor
	int height;

	/// Current X axis position of the image
	int position_x;

	/// Current Y axis position of the image
	int position_y;
};
