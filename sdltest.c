#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#define WIDTH 800
#define HEIGHT 600
#define WIDTH_REC (WIDTH / 5)
#define HEIGHT_REC (HEIGHT / 5)


void branco(SDL_Renderer *renderer){
	SDL_Rect rec_branco;

	rec_branco.w = WIDTH_REC;
	rec_branco.h = HEIGHT_REC;
	rec_branco.x = ((WIDTH_REC)*2);
	rec_branco.y = ((HEIGHT_REC)*2);

    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    SDL_RenderFillRect( renderer, &rec_branco);
    SDL_RenderPresent(renderer);
}

void vermelho(SDL_Renderer *renderer){
	SDL_Rect rec_vermelho;

	rec_vermelho.w = WIDTH_REC;
	rec_vermelho.h = HEIGHT_REC;
	rec_vermelho.x = ((WIDTH_REC)*2);
	rec_vermelho.y = ((HEIGHT_REC));

    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
    SDL_RenderFillRect( renderer, &rec_vermelho);
    SDL_RenderPresent(renderer);
}

void azul(SDL_Renderer *renderer){
	SDL_Rect rec_azul;

	rec_azul.w = WIDTH_REC;
	rec_azul.h = HEIGHT_REC;
	rec_azul.x = ((WIDTH_REC)*3);
	rec_azul.y = ((HEIGHT_REC)*2);

    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
    SDL_RenderFillRect( renderer, &rec_azul);
    SDL_RenderPresent(renderer);
}

void amarelo(SDL_Renderer *renderer){
	SDL_Rect rec_amarelo;

	rec_amarelo.w = WIDTH_REC;
	rec_amarelo.h = HEIGHT_REC;
	rec_amarelo.x = ((WIDTH_REC)*2);
	rec_amarelo.y = ((HEIGHT_REC)*3);

    SDL_SetRenderDrawColor( renderer, 255, 255, 0, 255 );
    SDL_RenderFillRect( renderer, &rec_amarelo);
    SDL_RenderPresent(renderer);
}

void verde(SDL_Renderer *renderer){
	SDL_Rect rec_verde;

	rec_verde.w = WIDTH_REC;
	rec_verde.h = HEIGHT_REC;
	rec_verde.x = ((WIDTH_REC));
	rec_verde.y = ((HEIGHT_REC)*2);

    SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
    SDL_RenderFillRect( renderer, &rec_verde);
    SDL_RenderPresent(renderer);
}


int main(int argc, char **argv)
{
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
			
        }

    	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // Clear screen
        SDL_RenderClear(renderer);

        // Draw
		branco(renderer);
		vermelho(renderer);
		azul(renderer);
		amarelo(renderer);
		verde(renderer);

        // Show what was drawn
        SDL_RenderPresent(renderer);
    }

    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

