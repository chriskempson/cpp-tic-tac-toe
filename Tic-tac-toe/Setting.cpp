/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#include "Setting.h"

char* Setting::game_name = "Tic-tac-toe";

// Set to NULL to use the default icon. Be careful as images that are too big
// don't always load.
char* Setting::icon_path = "images/icon16.bmp";

const std::string Setting::image_path = "images/";

const std::string Setting::sound_path = "sounds/";

// Set first element to -1 to disable colour keying
const int Setting::color_key[] = { 0x00, 0xFF, 0xFF };

// Default background colour for renderer
const int Setting::background_color[] = { 0xFF, 0xFF, 0xFF, 0xFF };