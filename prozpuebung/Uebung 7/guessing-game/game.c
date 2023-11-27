#include <stdio.h>  	/* Standard Input/Output  z.B. scanf, printf */
#include <stdbool.h> 	/* 'bool' als Datentyp und Macros für 'true' und 'false' */
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "game.h"

/*
 * Konstanten
 */
const char DISP_UNKNOWN              = '?';
const char DISP_KNOWN_IMPOSSIBLE     = '.';
const char DISP_KNOWN_ORACLE         = 'X';
const char DISP_KNOWN_GUESSED        = '!';
const char DISP_KNOWN_GUESSED_ORACLE = '$';


void guessingGame(const int oracleValueMin, const int oracleValueMax) {

    const int oracleValueRange = oracleValueMax - oracleValueMin;
    const int displaySize = oracleValueRange + 1;

    char display[displaySize + 1]; // reserve space for Null-terminator symbol
    initializeDisplay(display, displaySize);

	unsigned char retry = 'j';
    srand((unsigned int)time(0));

	do {

        // TODO: Erzeuge eine Zufallszahl anstatt der 42.
        int oracleValue = rand() % 100;

		printf("Ich habe mir eine Zahl zwischen %d und %d ausgedacht. Welche ist es?\n", 
			oracleValueMin,
			oracleValueMax
		);
		guess(oracleValue, display, oracleValueMin, oracleValueMax);
        initializeDisplay(display, displaySize);
        printf("Möchtest du erneut spielen? (j/n)\n");
		while(getchar() != '\n');
		scanf("%c", &retry);
		retry = tolower(retry);

	} while(retry == 'j');	
}


void guess(int oracleValue, char * display, int oracleValueMin, int oracleValueMax) {

	int remaining_guesses = N_GUESSES;
	int guessedValue = 0;
    // TODO: Diese Funktion soll den Nutzer wiederholt nach einer Zahl fragen und das Spiel,
    //  wie im Übungsblatt gezeigt, durchführen. Die Funktion kehrt zurück, sobald der Nutzer die Zahl erraten oder
    //  seine Versuche aufgebraucht hat.
    do {
        scanf("%d", &guessedValue);
        if (guessedValue == oracleValue) {
            updateDisplay(display, guessedValue, oracleValue, remaining_guesses, oracleValueMin, oracleValueMax);
            showDisplay(display);
            printf("Glückwunsch. Du hast die richtige Zahl erraten!\n");
            break;
        }
        if(guessedValue < oracleValue) {
            remaining_guesses -= 1;
            printf("Die ist zu klein.\n");
            updateDisplay(display, guessedValue, oracleValue, remaining_guesses, oracleValueMin, oracleValueMax);
            showDisplay(display);
        }
        if(guessedValue > oracleValue){
            remaining_guesses -= 1;
            printf("Die ist zu groß.\n");
            updateDisplay(display, guessedValue, oracleValue, remaining_guesses, oracleValueMin, oracleValueMax);
            showDisplay(display);
        }
    } while(remaining_guesses > 0);

    if(remaining_guesses > 0) {
        printf("Du hättest noch %d Versuche frei gehabt.\n", remaining_guesses);
    }
    else {
        printf("Du hats deine 5 Versuche aufgebraucht. Die korrekte Zahl war: %d.\n", oracleValue);
    }
}


void initializeDisplay(char * display, const int sizeOfDisplay) {
    for(int i = 0; i < sizeOfDisplay; i++) {
        display[i] = DISP_UNKNOWN;
    }
    display[sizeOfDisplay] = '\0';
}

void updateDisplay(char * display, int guess, int oracle, int remainingGuesses, int oracleValueMin, int oracleValueMax) {
    unsigned long n = strlen(display);

    // TODO: Setze die Zeichen im Display entsprechend der aktuellen Spielsituation.
    //  'updateDisplay' soll nach jedem Rateversuch aus der Funktion guess heraus aufgerufen werden.
    if(guess < oracle) {
        for(int i = oracleValueMin - 1; i <= guess; i++) {
            if(i == guess) {
                display[i] =  DISP_KNOWN_GUESSED;
            }
            else {
                if(display[i] != DISP_KNOWN_GUESSED) {
                    display[i] = DISP_KNOWN_IMPOSSIBLE;
                }
            }
        }
    }
    if(guess > oracle) {
        for(int i = guess; i <= oracleValueMax - 1; i++) {
            if(i == guess) {
                display[i] =  DISP_KNOWN_GUESSED;
            }
            else {
                if(display[i] != DISP_KNOWN_GUESSED) {
                    display[i] = DISP_KNOWN_IMPOSSIBLE;
                }
            }
        }
    }
    if(guess == oracle) {
        display[guess] = DISP_KNOWN_GUESSED_ORACLE;
    }
    if(remainingGuesses == 0) {
        display[oracle] = DISP_KNOWN_ORACLE;
    }

}

void showDisplay(char * display) {
    printf("| %s |\n", display);
}


void line(int n, char c)
{
	for (int i = 0; i < n; i++) {
		printf("%c", c);
	}
	printf("\n");
}

