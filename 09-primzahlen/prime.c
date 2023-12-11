/*******************************************************************
// Programm    : Primzahlen                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 13.11.2012                                           
// Aufgabe     : Primzahlberechnung nach Sieb des Eratosthenes
// Änderungen  : 13.11.2012
// 				 06.12.2023 (Jurgovsky)
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <math.h>
#include "prime.h"


void sieve(int markers[], int N) {
    for(int i = 2; i <= N; i++) {
        markers[i] = PRIME;
    }
    for(int i = 2; i <= sqrt(N); i++) {
        if(markers[i] == PRIME) {
            for(int j = i*i; j <= N; j += i) {
                markers[j] = NOT_PRIME;
            }
        }
    }

}


void show(const int markers[], int N) {

    printf("Primzahlen bis %d:\n", (N-1));
    int j = 0;
    for(int i = 2; i <= N; i++) {
        if(markers[i] == PRIME) {
            printf("%5d", i);
            j++;
            if(j % 10 == 0) {
                printf("\n");
            }
        }
    }
}


void line(int n, char c) 
{
	for (int i = 1; i <= n; i++) {
        printf("%c", c);
    }
	printf("\n");
}
