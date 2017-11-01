/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#include <iostream>
#include <string>
#include <SDL_mixer.h>
#include "Game.h"
#include "Setting.h"
#include "State_manager.h"
#include "Resource_manager.h"
#include "Title_state.h"

// Initialise static data-members 
SDL_Window* Game::window = NULL;
SDL_Renderer* Game::renderer = NULL;

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    // Quit SDL subsystems
    Mix_Quit();
    SDL_Quit();
}

SDL_Window* Game::get_window()
{
    return window;
}

SDL_Renderer* Game::get_renderer()
{
    return renderer;
}

bool Game::init(char* title, int window_width, int window_height)
{
    // Initialise SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create window
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width * Setting::scale_factor, window_height * Setting::scale_factor, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Set titlebar icon
    if (Setting::icon_path) {
        SDL_Surface* icon = SDL_LoadBMP(Setting::icon_path);
        if (icon == NULL) {
            std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
            return false;
        }

        SDL_SetWindowIcon(window, icon);
        SDL_FreeSurface(icon);
    }

    // Create renderer for window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Set background colour
    SDL_SetRenderDrawColor(renderer, Setting::background_color[0], Setting::background_color[1], Setting::background_color[2], Setting::background_color[3]);

    // Initialise SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
        return false;
    }

    return true;
}

void Game::run()
{
    while (running)
    {
        // Loop until all pending events have left the queue 
        while (SDL_PollEvent(&event)) {

            // Let the state handle events
            State_manager::get_state()->handle_events(event);

            // Handle window quit event
            if (event.type == SDL_QUIT) {
                Game::stop();
            }
        }

        // Update data of the state
        State_manager::get_state()->update();

        // Clear screen
        SDL_RenderClear(renderer);

        // Render the state
        State_manager::get_state()->render();

        // Update screen taking into account SDL v-sync. This is what stops the 
        // game loop from running too fast
        SDL_RenderPresent(renderer);

    }
}

void Game::stop()
{
    running = false;
}

void Game::get_mouse_position(int* mouse_x, int* mouse_y)
{
    SDL_GetMouseState(mouse_x, mouse_y);
    *mouse_x = *mouse_x / Setting::scale_factor;
    *mouse_y = *mouse_y / Setting::scale_factor;
}
