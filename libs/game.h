#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL2/SDL.h>
#include <stdbool.h>

#define WIDTH 800
#define HEIGHT 600
#define WIDTH_REC (WIDTH / 5)
#define HEIGHT_REC (HEIGHT / 5)

typedef struct jogo{
		int cor;
		struct jogo *prox;
		} tJogo;

int aleatorio(void);
bool criaJogo(tJogo *jogo, int tam);
void exibe(tJogo *LISTA);

SDL_Rect branco(SDL_Renderer *renderer);
SDL_Rect vermelho(SDL_Renderer *renderer);
SDL_Rect azul(SDL_Renderer *renderer);
SDL_Rect amarelo(SDL_Renderer *renderer);
SDL_Rect verde(SDL_Renderer *renderer);

#endif
