//
// Created by kris on 4/13/23.
//

#ifndef LE_GRAVITY_SIMULATOR_IPRESSHANDLER_H
#define LE_GRAVITY_SIMULATOR_IPRESSHANDLER_H

#endif //LE_GRAVITY_SIMULATOR_IPRESSHANDLER_H

#include <SDL2/SDL.h>

class IButtonHandler {
public:
    virtual void handle_event(const SDL_Event& event) = 0;
};