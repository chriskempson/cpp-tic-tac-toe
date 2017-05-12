/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#pragma once
#include <SDL_mixer.h>
#include "Resource.h"

/**
 * Resource interface implementation for handling sound files
 */
class Sound_resource : public Resource
{
public:
	Sound_resource();
	~Sound_resource();

	/**
	 * See Resource Class for documentation
	 */
	bool load_from_file(char* file);

	/**
	 * Plays the loaded sound file
	 */
	void play();

private:
	/// Pointer to the sound file stored as a Mix_Chunk
	Mix_Chunk* chunk;

	/// Path to the loaded sound file
	std::string path;
};