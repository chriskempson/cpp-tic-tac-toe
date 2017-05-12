/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#include <iostream>
#include <string>
#include "Image_resource.h"
#include "Game.h"
#include "Setting.h"

Image_resource::Image_resource()
{
	texture = NULL;
	width = 0;
	height = 0;
	position_x = 0;
	position_y = 0;
}

Image_resource::~Image_resource()
{
	if (texture != NULL) {
		SDL_DestroyTexture(texture);
		texture = NULL;
	}
}

bool Image_resource::load_from_file(char* file)
{
	// Only BMPs are supported the ".bmp" can be appended here
	std::string path = Setting::image_path + file + ".bmp";

	// Load image at specified path
	SDL_Surface* surface = SDL_LoadBMP(path.c_str());
	if (surface == NULL) {
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		return false;
	}

	// Colour key image if enabled in Settings.h
	if (Setting::color_key[0] != -1) {
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, Setting::color_key[0], Setting::color_key[1], Setting::color_key[2]));
	}

	// Create texture from surface pixels
	texture = SDL_CreateTextureFromSurface(Game::get_renderer(), surface);
	if (texture == NULL) {
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return false;
	}

	// Grab the actual (not-scaled) width and height 
	width = surface->w;
	height = surface->h;

	// Delete the surface
	SDL_FreeSurface(surface);

	return true;
}

void Image_resource::set_position(int x, int y) {

	// Update the X and Y positions ready for render()
	position_x = x;
	position_y = y;
}

void Image_resource::render(SDL_Rect* clip_rect)
{
	// Create a rectangle that defines where the texture should be draw and 
	// at what size
	SDL_Rect dest_rect = {
		position_x * Setting::scale_factor,
		position_y * Setting::scale_factor,
		width * Setting::scale_factor, 
		height * Setting::scale_factor 
	};

	// If using a sprite dest_rect needs to use the width and height of a single sprite not the entire sprite sheet
	if (clip_rect != NULL) {
		dest_rect.w = clip_rect->w * Setting::scale_factor;
		dest_rect.h = clip_rect->h * Setting::scale_factor;
	}

	// Copy the texture to the renderer with a clipping source rectangle if 
	// supplied but with no rotating or flipping
	SDL_RenderCopyEx(Game::get_renderer(), texture, clip_rect, &dest_rect, 0.0, NULL, SDL_FLIP_NONE);
}