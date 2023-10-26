#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Image Display",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800,  // width
        600,  // height
        SDL_WINDOW_SHOWN);

    // window check
    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    // Make renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    // Load image
    SDL_Surface* bgSurface = IMG_Load("background.bmp");
    if (!bgSurface) {
        std::cerr << "Failed to load background image: " << IMG_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_Texture* bgTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
    SDL_FreeSurface(bgSurface);

    SDL_Surface* tilesSurface = IMG_Load("tiles.bmp");
    if (!tilesSurface) {
        std::cerr << "Failed to load tiles image: " << IMG_GetError() << std::endl;
        SDL_DestroyTexture(bgTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_Texture* tilesTexture = SDL_CreateTextureFromSurface(renderer, tilesSurface);
    SDL_FreeSurface(tilesSurface);

    SDL_Rect tileRects[3];
    tileRects[0] = { 0, 0, 64, 64 }; 
    tileRects[1] = { 64, 0, 64, 64 };
    tileRects[2] = { 128, 0, 64, 64 };

    bool displayBackground = false;
    bool displayTiles[3] = { false, false, false };
    SDL_Rect tileDestRects[3];

    // Keep showing image until close
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_0:
                    displayBackground = !displayBackground;
                    break;
                case SDLK_1:
                case SDLK_2:
                case SDLK_3:
                    int index = event.key.keysym.sym - SDLK_1;
                    displayTiles[index] = !displayTiles[index];
                    if (displayTiles[index]) {
                        tileDestRects[index].x = std::rand() % (800 - 64);
                        tileDestRects[index].y = std::rand() % (600 - 64);
                        tileDestRects[index].w = 64;
                        tileDestRects[index].h = 64;
                    }
                    break;
                }
            }
        }

        SDL_RenderClear(renderer);
        if (displayBackground) {
            SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
        }
        for (int i = 0; i < 3; ++i) {
            if (displayTiles[i]) {
                SDL_RenderCopy(renderer, tilesTexture, &tileRects[i], &tileDestRects[i]);
            }
        }
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyTexture(tilesTexture);
    SDL_DestroyTexture(bgTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
