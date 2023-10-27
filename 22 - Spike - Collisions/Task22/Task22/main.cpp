#include "shapes.h"
#include <stdio.h>

// Screen dimensions
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

//sdl window and renderer setup
bool init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    window = SDL_CreateWindow("Box Collision Detection", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

//closing
void closeSDL() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//draw circle, SDL2 can't intuitively draw circles
void drawFilledCircle(SDL_Renderer* renderer, int x, int y, int radius) {
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, x + dx - radius, y + dy - radius);
            }
        }
    }
}


Rectangle staticBox({ SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, 50, 50 }); //static rect
Rectangle movingBox({ 0, staticBox.rect.y + (staticBox.rect.h / 2) - 25, 50, 50 }); //moving rect

Circle staticCircle({ 3 * SCREEN_WIDTH / 4, 3 * SCREEN_HEIGHT / 4 }, 25); //static circle
Circle movingCircle({ 0 * SCREEN_WIDTH / 4, 3 * SCREEN_HEIGHT / 4 }, 25); //moving circle


int main(int argc, char* args[]) {
    if (!init()) {
        printf("Failed to initialize SDL!\n");
        return 1;
    }

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Move the shapes
        movingBox.rect.x += 1;
        movingCircle.center.x += 2;

        // Collision detection
        bool boxCollision = staticBox.checkCollision(movingBox);
        bool circleCollision = staticCircle.checkCollision(movingCircle);

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);  // White background
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);  // Red for the static shapes
        SDL_RenderFillRect(renderer, &staticBox.rect);
        drawFilledCircle(renderer, staticCircle.center.x, staticCircle.center.y, staticCircle.radius);

        
        if (boxCollision) { //changes colour based on bool
            SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);  // Green for colliding shapes
        }
        else {
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);  // Blue for non-colliding shapes
        }
        SDL_RenderFillRect(renderer, &movingBox.rect);

        if (circleCollision) { //changes colour based on bool
            SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);  // Green for colliding circles
        }
        else {
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);  // Blue for non-colliding circles
        }
        drawFilledCircle(renderer, movingCircle.center.x, movingCircle.center.y, movingCircle.radius);

        SDL_RenderPresent(renderer);
        SDL_Delay(16); //delay to make objects move slower
    }

    closeSDL();
    return 0;
}
