#include <SDL.h>
#include <SDL_mixer.h>

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        SDL_Log("Cannot initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        SDL_Log("Cannot initialize SDL_mixer, SDL_mixer Error: %s", Mix_GetError());
        return 1;
    }

    // Create SDL window and renderer
    SDL_Window* window = SDL_CreateWindow("SDL2 Sound Demo",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Log("cannot create window : % s", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Cannot create renderer: %s", SDL_GetError());
        return 1;
    }

    // Load sounds
    Mix_Chunk* sound1 = Mix_LoadWAV("1_start.wav");
    Mix_Chunk* sound2 = Mix_LoadWAV("2_relax.wav");
    Mix_Chunk* sound3 = Mix_LoadWAV("3_shutdown.wav");

    if (!sound1 || !sound2 || !sound3) {
        SDL_Log("Failed to load sound effect! SDL_mixer Error: %s", Mix_GetError());
        return 1;
    }

    bool isRunning = true;
    SDL_Event event;

    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_1:
                    Mix_PlayChannel(-1, sound1, 0);
                    break;
                case SDLK_2:
                    Mix_PlayChannel(-1, sound2, 0);
                    break;
                case SDLK_3:
                    Mix_PlayChannel(-1, sound3, 0);
                    break;
                }
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    // Clean up
    Mix_FreeChunk(sound1);
    Mix_FreeChunk(sound2);
    Mix_FreeChunk(sound3);
    Mix_CloseAudio();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
