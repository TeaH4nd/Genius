#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "libs/game.h"

bool XYInRect(const SDL_Rect rect, int x, int y){
	return ( ( (x >= rect.x) && (x <= (rect.x + rect.w)) ) && ( (y >= rect.y) && (y <= (rect.y + rect.h)) ) );
}


int main(int argc, char **argv){
	SDL_Rect rec_branco, rec_vermelho, rec_azul, rec_amarelo, rec_verde;
	int tamanho, tentativas;
	tJogo *jogo = (tJogo *) malloc(sizeof(tJogo));
	int i;

	printf("Tamanho: ");
	scanf("%d", &tamanho);
	printf("Tentativas: ");
	scanf("%d", &tentativas);

	 // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a SDL window
    SDL_Window *window = SDL_CreateWindow("Genius", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    bool running = true;
	bool iniciado = false;	

    SDL_Event event;
	criaJogo(jogo, tamanho);
	printf("exibe:\n");
	exibe(jogo);

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


			/*
			if(event.type == SDL_MOUSEBUTTONDOWN){
				printf("%d %d\n", event.motion.x, event.motion.y);
                if (XYInRect(rec_branco, event.motion.x, event.motion.y)){
            		running = false;
				}
			}
			*/

        } //while eventos
			

        // Show what was drawn
        SDL_RenderPresent(renderer);
    } //while running

    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

