# Genius
Genius game for a class using C and SDL

## To compile the sdltest.c do:

Inside the libs folder: gcc -c game.c -o game.o

Inside the Genius folder: 	gcc -c sdltest.c -o sdltest.o
				gcc sdltest.o libs/game.o -o sdltest.out -lSDL2 -Wall


## To compile the genius.c do:

Inside the libs folder: gcc -c game.c -o game.o

Inside the Genius folder: 	gcc -c genius.c -o genius.o
				gcc genius.o libs/game.o -o genius.out -Wall

