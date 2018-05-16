#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "libs/game.h"

#define WIDTH 800
#define HEIGHT 600
#define WIDTH_REC (WIDTH / 5)
#define HEIGHT_REC (HEIGHT / 5)

bool XYInRect(const SDL_Rect rect, int x, int y){
//	printf("x: %d\ny: %d\nrect.x: %d\nrect.y: %d\n", x, y, rect.x, rect.y);
	return ( ( (x >= rect.x) && (x <= (rect.x + rect.w)) ) && ( (y >= rect.y) && (y <= (rect.y + rect.h)) ) );
}


int main(int argc, char **argv){
	SDL_Rect rec_branco, rec_vermelho, rec_azul, rec_amarelo, rec_verde;
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a SDL window
    SDL_Window *window = SDL_CreateWindow("Genius", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    bool running = true;
    SDL_Event event;
    while(running)
    {
        // Process events
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running = false;
            }
			
	    	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    	    // Clear screen
        	SDL_RenderClear(renderer);

	        // Draw
			rec_branco = branco(renderer);
			rec_vermelho = vermelho(renderer);
			rec_azul = azul(renderer);
			rec_amarelo = amarelo(renderer);
			rec_verde = verde(renderer);

			if(event.type == SDL_MOUSEBUTTONDOWN){
				printf("%d %d\n", event.motion.x, event.motion.y);
                if (XYInRect(rec_branco, event.motion.x, event.motion.y)){
            		running = false;
				}
			}
        }


        // Show what was drawn
        SDL_RenderPresent(renderer);
    }

    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

