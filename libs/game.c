#include "game.h"
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

int aleatorio(void){
	int randNum = 0;

	// Provide seed for the random number
	// generator.
	srand(time(NULL));
	// First, pick a number between 0 and
	// 4.
	randNum = 4 * (rand() / (RAND_MAX + 1.0));
	//printf ("Random int: %d\n", randNum);
	
	return randNum;
}

bool criaJogo(tJogo *jogo, int tam){
	tJogo *novo = (tJogo *) malloc(sizeof(tJogo));
		
	if(tam == 0){
		jogo->cor = aleatorio();
		return true;
	}else{
		novo->prox = NULL;
		novo->cor = aleatorio();
		while(jogo->prox != NULL){
			jogo = jogo->prox;
		}
		jogo->prox = novo;
		criaJogo(jogo, --tam);
	}

}

void exibe(tJogo *LISTA){
	tJogo *tmp;

	tmp = LISTA->prox;
	
	while( tmp != NULL){
		printf("%d ", tmp->cor);
		tmp = tmp->prox;
	}
	printf("\n\n");
}

SDL_Rect branco(SDL_Renderer *renderer){
	SDL_Rect rec_branco;

	rec_branco.w = WIDTH_REC;
	rec_branco.h = HEIGHT_REC;
	rec_branco.x = ((WIDTH_REC)*2);
	rec_branco.y = ((HEIGHT_REC)*2);

    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    SDL_RenderFillRect( renderer, &rec_branco);
//    SDL_RenderPresent(renderer);

	return rec_branco;
}

SDL_Rect vermelho(SDL_Renderer *renderer){
	SDL_Rect rec_vermelho;

	rec_vermelho.w = WIDTH_REC;
	rec_vermelho.h = HEIGHT_REC;
	rec_vermelho.x = ((WIDTH_REC)*2);
	rec_vermelho.y = ((HEIGHT_REC));

    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
    SDL_RenderFillRect( renderer, &rec_vermelho);
//    SDL_RenderPresent(renderer);

	return rec_vermelho;
}

SDL_Rect azul(SDL_Renderer *renderer){
	SDL_Rect rec_azul;

	rec_azul.w = WIDTH_REC;
	rec_azul.h = HEIGHT_REC;
	rec_azul.x = ((WIDTH_REC)*3);
	rec_azul.y = ((HEIGHT_REC)*2);

    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
    SDL_RenderFillRect( renderer, &rec_azul);
//    SDL_RenderPresent(renderer);

	return rec_azul;
}

SDL_Rect amarelo(SDL_Renderer *renderer){
	SDL_Rect rec_amarelo;

	rec_amarelo.w = WIDTH_REC;
	rec_amarelo.h = HEIGHT_REC;
	rec_amarelo.x = ((WIDTH_REC)*2);
	rec_amarelo.y = ((HEIGHT_REC)*3);

    SDL_SetRenderDrawColor( renderer, 255, 255, 0, 255 );
    SDL_RenderFillRect( renderer, &rec_amarelo);
//    SDL_RenderPresent(renderer);

	return rec_amarelo;
}

SDL_Rect verde(SDL_Renderer *renderer){
	SDL_Rect rec_verde;

	rec_verde.w = WIDTH_REC;
	rec_verde.h = HEIGHT_REC;
	rec_verde.x = ((WIDTH_REC));
	rec_verde.y = ((HEIGHT_REC)*2);

    SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
    SDL_RenderFillRect( renderer, &rec_verde);
//    SDL_RenderPresent(renderer);

	return rec_verde;
}
