/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#include "Resource_manager.h"

// Define vectors to store pointers to instances of resource classes
std::vector<std::pair<std::string, Image_resource*>> Resource_manager::images;
std::vector<std::pair<std::string, Sound_resource*>> Resource_manager::sounds;

Image_resource* Resource_manager::get_image(char* file) {

	// Check each entry until we find one that matches file as file is being 
	// used an ID
	for (unsigned int i = 0; i < images.size(); i++) {
		if (images[i].first == file) {

			return images[i].second;
		}
	}

	return NULL;
}

Sound_resource* Resource_manager::get_sound(char* file) {

	// Check each entry until we find one that matches file as file is being 
	// used an ID
	for (unsigned int i = 0; i < sounds.size(); i++) {
		if (sounds[i].first == file) {

			return sounds[i].second;
		}
	}

	return NULL;
}

Image_resource* Resource_manager::load_image(char* file) {

	// Load a resource file, store the instance and then return it
	Image_resource* image = new Image_resource();
	image->load_from_file(file);
	images.insert(images.end(), std::make_pair(file, image));
	return get_image(file);
}

Sound_resource* Resource_manager::load_sound(char* file) {

	// Load a resource file, store the instance and then return it
	Sound_resource* sound = new Sound_resource();
	sound->load_from_file(file);
	sounds.insert(sounds.end(), std::make_pair(file, sound));
	return get_sound(file);
}

void Resource_manager::unload_image(char* file) {

	// Check each entry until we find one that matches file as file is being 
	// used an ID
	for (unsigned int i = 0; i < images.size(); i++) {
		if (images[i].first == file) {

			// Delete instance since it was created with new
			delete images[i].second;
			images[i].second = NULL;
			
			// Remove unneeded entry from vector
			images.erase(images.begin() + i);
		}
	}
}

void Resource_manager::unload_sound(char* file) {

	// Check each entry until we find one that matches file as file is being 
	// used an ID
	for (unsigned int i = 0; i < sounds.size(); i++) {
		if (sounds[i].first == file) {

			// Delete instance since it was created with new
			delete sounds[i].second;
			sounds[i].second = NULL;

			// Remove unneeded entry from vector
			sounds.erase(sounds.begin() + i);
		}
	}
}
