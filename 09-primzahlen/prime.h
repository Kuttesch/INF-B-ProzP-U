#ifndef _PRIM_H_
#define _PRIM_H_

/* Definition globaler Konstanten */
#define NOT_PRIME 0
#define PRIME  1

/* Prototypen der benötigten Funktionen */

/**
 * Bestimmt die Primzahlen von 2 bis N-1 mittels des Sieb des Eratosthenes
 * und markiert die Primzahlen in 'markers'.
 */
void sieve(int markers[], int N);

/**
 * Gibt die in 'markers' als Primzahlen markierten Primzahlen zwischen 1 und N-1 aus.
 */
void show(const int markers[], int N);


/**
 * Gibt n mal das Zeichen c aus
 */
void line(int n, char c); 


#endif
