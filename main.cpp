#include "Renderer.h"

int main() {
    Renderer renderer = Renderer("SDL Test Program", 1280, 720);

    renderer.start_renderer();
    return 0;
}
