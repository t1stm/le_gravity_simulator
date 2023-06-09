//
// Created by kris on 4/13/23.
//

#include <SDL2/SDL.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "IButtonHandler.h"
#include "IDrawableObject.h"

const uint32_t render_flags = SDL_RENDERER_ACCELERATED;

class Renderer {
    class SDLButtonsHandler : public IButtonHandler {
    public:
        void handle_event(const SDL_Event& event) override {
            switch (event.type) {
                case SDL_QUIT:
                    renderer->close();
                    break;
            }
        }

        explicit SDLButtonsHandler(Renderer* source_renderer) {
            renderer = source_renderer;
        }

    private:
        Renderer* renderer;
    };

public:
    void start_renderer();
    void close();

    void add_drawable(IDrawableObject* drawable_object) {
        render_objects.push_back(drawable_object);
    }

    void add_input_handler(IButtonHandler* button_handler) {
        button_handlers.push_back(button_handler);
    }

    void remove_drawable(IDrawableObject* drawable_object) {
        auto start = render_objects.begin();
        auto end = render_objects.end();
        auto position = std::find(start, end, drawable_object);
        if (position == end) return;
        render_objects.erase(position);
    }

    void remove_input_handler(IButtonHandler* button_handler) {
        auto start = button_handlers.begin();
        auto end = button_handlers.end();
        auto position = std::find(start, end, button_handler);
        if (position == end) return;
        button_handlers.erase(position);
    }

    Renderer(const char* title, int32_t width, int32_t height) {
        button_handlers = std::vector<IButtonHandler*>();
        window = SDL_CreateWindow(title, 0, 0, width, height, 0);
        renderer = SDL_CreateRenderer(window, -1, render_flags);
        force_close = false;

        auto handler = new SDLButtonsHandler(this);
        sdl_default_handler = handler;
        button_handlers.push_back(sdl_default_handler);
        std::cout << "Created renderer.\n";
    }

    ~Renderer() {
        close();
        delete sdl_default_handler;
    }

private:
    IButtonHandler* sdl_default_handler;
    std::vector<IButtonHandler*> button_handlers;
    std::vector<IDrawableObject*> render_objects;
    bool force_close;
    void handle_inputs();
    SDL_Window* window;
    SDL_Renderer* renderer;
};