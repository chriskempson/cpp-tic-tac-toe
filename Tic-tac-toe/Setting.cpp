/*
 * Tic Tac Toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#include "Setting.h"

char* Setting::game_name = "Tic-tac-toe";
char* Setting::icon_path = "images/icon.bmp"; // Set to NULL to use the default icon
const std::string Setting::image_path = "images/";
const std::string Setting::sound_path = "sounds/";
const int Setting::color_key[] = { 0, 0xFF, 0xFF }; // Set first element to -1 to disable colour keying