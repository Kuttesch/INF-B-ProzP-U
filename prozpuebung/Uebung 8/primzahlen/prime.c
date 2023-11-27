/*******************************************************************
// Programm    : Primzahlen                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 13.11.2012                                           
// Aufgabe     : Primzahlberechnung nach Sieb des Eratosthenes
// Änderungen  : 13.11.2012
// 				 30.11.2022 (Jurgovsky)
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <math.h>
#include "prime.h"


void sieve(int markers[], int N) {
    for(int i = 2; i <= N; i++) {
        markers[i] = PRIME;
    }
    for(int i = 2; i <= sqrt(N) ; i++) {
        for(int j = 2*i; j <= N; j++) {
            if((j%i) == 0) {
                if(markers[j] == PRIME) {
                    markers[j] = NOT_PRIME;
                }
            }
        }
    }
}


void show(const int markers[], int N) {

	printf("Prmizahlen zwischen 1 und %d\n", (N-1));
    int j = 0;
    for(int i = 1; i <= N-1; i++) {
        if(markers[i] == PRIME) {
            printf("%d\t", i);
            j++;
            if(!(j%10)) {
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
