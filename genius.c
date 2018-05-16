#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aleatorio(){
	char randChar = ' ';
	int counter = 0;
	int randNum = 0;

	// Provide seed for the random number
	// generator.
	srand(time(NULL));
	for (counter = 0; counter < 10; counter++)
	{
		// First, pick a number between 0 and
		// 25.
		randNum = 26 * (rand() / (RAND_MAX + 1.0));

		// The ASCII code for ‘a’ is 97, so
		// add 97 to the random number to get
		// a lower case letter.
		randNum = randNum + 97;

		// Type cast to character to convert
		// it to a char type.
		randChar = (char) randNum;

		printf ("Random char: %c\n", randChar);
	}
}

int main(void){

	aleatorio();

	return 0;
}
