#include <stdio.h>
#include "game.h"

int main () 
{
    line(100, '-');
	printf("Guessing Game\n");
	line(100, '-');

	guessingGame(ORACLE_VALUE_MIN, ORACLE_VALUE_MAX);

	return 0;
}