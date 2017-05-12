/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#include <iostream>
#include <string>
#include "Sound_resource.h"
#include "Setting.h"

Sound_resource::Sound_resource()
{
	chunk = NULL;
	path = "";
}

Sound_resource::~Sound_resource()
{
	if (chunk != NULL) {
		Mix_FreeChunk(chunk);
		chunk = NULL;
	}

	path = "";
}

bool Sound_resource::load_from_file(char* file)
{
	// Only WAVs are supported the ".wav" can be appended here
	path = Setting::sound_path + file + ".wav";

	// Load sound at specified path
	chunk = Mix_LoadWAV(path.c_str());
	if (chunk == NULL) {
		std::cout << "Mix_LoadWAV Error: Couldn't open " << path << ". SDL_mixer Error: " << Mix_GetError() << std::endl;
		return false;
	}

	return true;
}

void Sound_resource::play()
{
	if (chunk == NULL) {
		std::cout << "Mix_PlayChannel Error: Couldn't play chunk for " << path << ". SDL_mixer Error: " << Mix_GetError() << std::endl;
	}
	else {
		if (Setting::play_sounds) {
			// Play chunk on the first free channel and don't loop it
			Mix_PlayChannel(-1, chunk, 0);
		}
	}
}