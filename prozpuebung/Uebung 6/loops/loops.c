#include <stdio.h>
#include "loops.h"


/* Array für die Werte der Tabellenzeilen */
struct Row_s rows[MAX_LIMIT];


int main(void) {
    int grenze;

    line(77, '-');
    printf("Exp: Berechnung von einfachen Funktionen\n");
    line(77, '-');

    grenze = readLimit(MAX_LIMIT);
    calculateTable(grenze);
    printTable(grenze);

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
        printf("Bitte geben Sie eine ganzzahlige positive Obergrenze <= %d ein: ", MAX_LIMIT);
        scanf("%d", &limit);
        if(! ((1 <= limit) && (limit <= cMax))) {
            printf("Eingegebene Grenze muss in [1;%d] liegen.", cMax);
        }
    } while(! ((1 <= limit) && (limit <= cMax)));
    // die eingelesene Grenze zurückgeben.
    return limit;
}


void calculateTable(int limit) {

    // TODO
    for(int i = 1; i <= limit; i++) {
        calculateRow(i);
    }
}

int faculty(int i) {
    int result = 1;
    for(int j = 1; j <= i; j++ ) {
        result *= j;
    }
    return result;
}

void calculateRow(int i) {
    struct Row_s row = {0,0,0,0,0,0};
    row.i = i;
    row.fraction_i = (double) 1/i;
    for(int j = 1; j <= i; j++ ) {
        row.sum_fraction_i += (double) 1/j;
    }
    row.faculty_i = faculty(i);
    row.fraction_faculty_i = (double) 1/row.faculty_i;
    for(int j = 0; j <= i; j++ ) {
        row.approximation_i += (double) 1/faculty(j);
    }
    rows[i-1] = row;
}


void printTable(int limit) {

    line(77, '-');
    printf("  i     1/i  Summe(1/i)                  i!              1/i!      Näherung e\n");
    line(77, '-');

    // TODO
    for(int i = 0; i < limit; i++) {
        printf("%d %6.5lf %8.7lf %d %16.14lf %14.12lf \n",
        rows[i].i, rows[i].fraction_i, rows[i].sum_fraction_i,
        rows[i].faculty_i, rows[i].fraction_faculty_i, rows[i].approximation_i);
    }


}