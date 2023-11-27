#include "util.h"
#include <stdio.h>  	/* Standard Input/Output  z.B. scanf, printf	*/
#include <string.h>  	/* Standardfunktionen für String-Operationen	*/
#include <ctype.h>      /* Standardfunktionen für Zeichentypen          */
#include <stdlib.h>     /* Standardfunktionen für Speicherverwaltung    */
#define BINS 256
void statistics(char * argv[], int argc) {
    int histogram[BINS];
    for(int i = 0; i < BINS; i++) {
        histogram[i] = 0;
    }
    for(int i = 1; i < argc; i++) {
        for(int j = 1; j < strlen(argv[i]); j++) {
            if(isalnum(argv[i][j])) {
                histogram[argv[i][j]] += 1;
            }
        }
    }
    for(int i = 0; i < BINS; i++ ) {
        if(histogram[i] > 0) {
            printf("%c:%d ", i, histogram[i]);
        }
    }
}


void reverse(char *argv[], int argc) {
    int words = argc - 1;
    char **tmp = (char**) malloc(words * sizeof(char*));
    tmp = argv;
    for(int i = 1 ; i < argc; i++) {
        tmp[i-1] = (char*) malloc(strlen(argv[i]) + 1);
        strcpy(tmp[i-1], argv[i]);
    }
    printText(tmp, words);
}

void printText(char* strings[], int size) {
    for(int i = size-1; i >= 0; i--) {
        printf("%s ", strings[i]);
    }
}
