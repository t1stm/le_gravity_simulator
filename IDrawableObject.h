//
// Created by kris on 4/13/23.
//

#include <SDL_render.h>

class IDrawableObject {
public:
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual ~IDrawableObject() = 0;
};