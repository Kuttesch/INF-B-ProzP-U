#include <stdio.h>
#include "loops.h"
#include <math.h>

/* Array für die Werte der Tabellenzeilen */
struct Row_s rows[MAX_LIMIT];


int main(void) {

    int limit;

    line(77, '-');
    printf("Exp: Berechnung von einfachen Funktionen\n");
    line(77, '-');

    limit = readLimit(MAX_LIMIT);
    calculateTable(limit);
    printTable(limit);

    return 0;
}


/* Gibt n mal das Zeichen c aus */
void line(int n, char c) {
    int i;

    for (i = 1; i <= n; i++) {
        printf("%c", c);
    }

    printf("\n");
}

int readLimit(int cMax) {

    int limit = -1;

    do {
        printf("Bitte positive obere Grenze eingeben (ganzzahlig <= %d):", cMax);
        scanf("%d", &limit);

        if(! ((1 <= limit) && (limit <= cMax)) ) {
            printf("Bitte limit in [1, %d] eingeben\n", cMax);
        }
    } while(! ((1 <= limit) && (limit <= cMax)) );

    return limit;
}


void calculateTable(int limit) {

    for (int i = 1; i <= limit; i++) {
        calculateRow(i);
    }
}


int faculty(int i) {
    int result = 1;
    for(int j = 1; j <= i; j++ ) {
        result *= j;
    }
    rows[i-1].length_fak_i = (int) log10(result) + 1;
    return result;
}


void calculateRow(int i) {

    int rowIdx = i-1;

    struct Row_s row = rows[rowIdx];
    row.i = i;

    row.frac_i = (double) 1/i;

    for (int j = 1; j <= i; j++) {
        row.sum_i += (double) 1/j;
    }

    row.fak_i = faculty(i);

    row.frac_fak_i = (double) 1/row.fak_i;

    for (int j = 0; j <= i; j++) {
        row.e_i += (double) 1/faculty(j);
    }

    rows[i-1] = row;
}

void printTable(int limit){

    line(110, '-');
    printf("i           1/i              sum(1/j)                  i!         1/i!             e                Lenght i!\n");
    line(110, '-');

    for(int i = 0; i < limit; i++){
        printf("%2d          %lf         %lf         %10d          %lf         %lf         %d\n",
        rows[i].i, rows[i].frac_i, rows[i].sum_i, rows[i].fak_i, rows[i].frac_fak_i, rows[i].e_i,rows[i].length_fak_i);
    }
}

