//
// Created by kris on 4/13/23.
//

#include "Renderer.h"
void Renderer::handle_inputs() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        for (auto action : button_handlers) {
            action->handle_event(event);
        }
    }
}

void Renderer::start_renderer() {
    while (!force_close) {
        handle_inputs();
        SDL_RenderClear(renderer);
        for (auto drawable : render_objects) {
            drawable->render(renderer);
        }
        SDL_RenderPresent(renderer);
    }
}

void Renderer::close() {
    force_close = true;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

