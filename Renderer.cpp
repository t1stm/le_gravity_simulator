//
// Created by kris on 4/13/23.
//

#include "Renderer.h"

void Renderer::handle_inputs() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        for (auto action : button_handlers) {
            action->handle_event(&event);
        }
    }
}

void Renderer::start_renderer() {
    while (!force_close) {
        handle_inputs();

    }
}

void Renderer::close() {
    force_close = true;
}

