#include <stdio.h>    /* Standard Input/Output  z.B. scanf, printf */
#include <stdbool.h>    /* 'bool' als Datentyp und Macros für 'true' und 'false' */
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "game.h"

/*
 * Konstanten
 */
const char DISP_UNKNOWN = '?';
const char DISP_KNOWN_IMPOSSIBLE = '.';
const char DISP_KNOWN_ORACLE = 'X';
const char DISP_KNOWN_GUESSED = '!';
const char DISP_KNOWN_GUESSED_ORACLE = '$';


void guessingGame(const int oracleValueMin, const int oracleValueMax) {

    const int oracleValueRange = oracleValueMax - oracleValueMin;
    const int displaySize = oracleValueRange + 1;
    srand(time(NULL));
    int random;

    char display[displaySize + 1]; // reserve space for Null-terminator symbol
    initializeDisplay(display, displaySize);

    unsigned char retry = 'j';


    do {
        random = ORACLE_VALUE_MIN + rand() % (ORACLE_VALUE_MAX + 1 - ORACLE_VALUE_MIN);
        printf("%d\n", random);
        int oracleValue = random;

        printf("Ich habe mir eine Zahl zwischen %d und %d ausgedacht. Welche ist es?\n",
               oracleValueMin,
               oracleValueMax
        );

        initializeDisplay(display, displaySize);
        showDisplay(display);
        guess(random, display, oracleValueMin, oracleValueMax);


        printf("Another time? (j/n)\n");
        while (getchar() != '\n');
        scanf("%c", &retry);
        retry = tolower(retry);

    } while (retry == 'j');
}


void guess(int random, char *display, int oracleValueMin, int oracleValueMax) {

    int remaining_guesses = N_GUESSES;
    int guessedValue = 0;
    bool fWon = false;

    while (remaining_guesses > 0 && !fWon) {
        scanf("%d", &guessedValue); // Moved inside the loop
        remaining_guesses--;
        updateDisplay(display, guessedValue, random, remaining_guesses, oracleValueMin, oracleValueMax);
        showDisplay(display);
        printf("Remaining guesses: %d\n", remaining_guesses);

        if (random == guessedValue) {
            fWon = true;
            break;
        } else if (random < guessedValue) {
            printf("The number is smaller than %d\n", guessedValue);
        } else if (random > guessedValue) {
            printf("The number is bigger than %d\n", guessedValue);
        }
    }

    if (fWon == true) {
        printf("You won!\n");
    } else if (remaining_guesses == 0) {
        printf("You lost!\nThe number was %d\n", random);
    }
}

void initializeDisplay(char *display, const int sizeOfDisplay) {
    for (int i = 0; i < sizeOfDisplay; i++) {
        display[i] = DISP_UNKNOWN;
    }
    display[sizeOfDisplay] = '\0';
}

void updateDisplay(char *display, int guess, int oracle, int remainingGuesses, int oracleValueMin, int oracleValueMax) {
    if (guess > oracle) {
        for (int i = oracleValueMin; i <= oracleValueMax; i++) {
            if (display[i - oracleValueMin] != DISP_KNOWN_GUESSED) {
                if (i < guess) {
                    display[i - oracleValueMin] = DISP_KNOWN_IMPOSSIBLE;
                } else if (i == guess) {
                    display[i - oracleValueMin] = DISP_KNOWN_GUESSED;
                } else {
                    display[i - oracleValueMin] = DISP_UNKNOWN;
                }
                oracleValueMin = guess;
            }
        }
    } else if (guess < oracle) {
        for (int i = oracleValueMax; i >= oracleValueMin; i--) {
            if (display[i - oracleValueMin] != DISP_KNOWN_GUESSED) {
                if (i > guess) {
                    display[i - oracleValueMin] = DISP_KNOWN_IMPOSSIBLE;
                } else if (i == guess) {
                    display[i - oracleValueMin] = DISP_KNOWN_GUESSED;
                } else {
                    display[i - oracleValueMin] = DISP_UNKNOWN;
                }
                oracleValueMin = guess;
            }
        }
    } else if (guess == oracle) {
        for (int i = oracleValueMin; i <= oracleValueMax; i++) {
            if (i == guess) {
                display[i - oracleValueMin] = DISP_KNOWN_GUESSED;
            }
        }
        display[oracleValueMax - oracleValueMin + 1] = '\0'; // Null-terminate the display string
    }
}

void showDisplay(char *display) {
    printf("| %s |\n", display);
}


void line(int n, char c) {
    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }
    printf("\n");
}

