/*
 * Tic-tac-toe
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#pragma once
#include <SDL.h>

/**
* Provides the core of the game application: window management,
* event capture, render area, main game loop and any helper
* functions related to the game
*/
class Game
{
public:
    ~Game();

    /**
     * Gets an instance of an SDL_Window
     *
     * @return Pointer to instance
     */
    static SDL_Window* get_window();

    /**
     * Gets an instance of an SDL_Renderer
     *
     * @return Pointer to instance
     */
    static SDL_Renderer* get_renderer();

    /**
     * SDL setup an initialisation
     *
     * @param title Application window title
     * @param window_width Application window width
     * @param window_height Application window height
     *
     * @return True if initialisation was successful
     */
    bool init(char* title, int window_width, int window_height);

    /**
     * Runs the game loop until stop() is called
     */
    void run();

    /**
     * Stops the game loop started by run() and cleans up SDL variables
     */
    void stop();

    /**
     * Returns by reference the X and Y axis positions of the mouse cursor
     * divided by the scale factor
     */
    static void get_mouse_position(int* mouse_x, int* mouse_y);

private:
    // Flag used by run() and stop() to check if the game should stop running
    bool running = true;

    // An instance of SDL_Event to be passed to a states handle_events() method
    SDL_Event event;

    // Points to an instance of SDL_CreateWindow returned by get_window()
    static SDL_Window* window;

    // Points to an instance of SDL_CreateRenderer returned by get_renderer()
    static SDL_Renderer* renderer;
};
