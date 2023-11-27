/*******************************************************************
// Programm    : Primzahlen                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 13.11.2012                                           
// Aufgabe     : Primzahlberechnung nach Sieb des Eratosthenes
// Änderungen  : 13.11.2012
//				 30.11.2022 (Jurgovsky)
*******************************************************************/

#include <stdio.h>  	/* Standard Input/Output  z.B. scanf, printf 	*/
#include <stdlib.h>     /* malloc, calloc, etc. */
#include "prime.h"
#include "vectors.h"


/* Obergrenze für Primzahlberechnung */
const int OG = 1000;


int main () 
{
    /*
     * Aufgabe 1
     */
	line(50, '-');
	printf("Sieb des Eratosthenes\n");
	line(50, '-');

    int N = OG + 1;
    int markers[N];
    /*
     * Beispiel für OG = 10, N = 11
     *
     * markers:
     * P P P P P P P P P P P
     * 0 1 2 3 4 5 6 7 8 9 10
     *                     ^
     *                     OG
     * P = PRIME
     * N = NOT_PRIME
     */

	sieve(markers, N);
	show(markers, N);




    /*
     * Aufgabe 2
     */
    struct Vector2_s data[] = {
            {5.0, -3.0}, // 0
            {-2.0, 8.0}, // 4
            {9.0, 2.0},  // 5
            {4.0, 5.0},  // 1
            {-1.0, 7.0}, // 3
            {3.0, -6.0}  // 2
        };

    int n = sizeof(data) / sizeof(struct Vector2_s);
    printVectorArray(data, n);


    selectionSort(data, n);
    printVectorArray(data, n);

	return EXIT_SUCCESS;
}