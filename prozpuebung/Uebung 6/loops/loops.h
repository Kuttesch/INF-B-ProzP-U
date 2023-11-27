#ifndef LOOPS_LOOPS_H
#define LOOPS_LOOPS_H

#define MAX_LIMIT 20

/* Datentypdefinitionen */
struct Row_s {
    int i;
    double fraction_i;
    double sum_fraction_i;
    int faculty_i;
    double fraction_faculty_i;
    double approximation_i;
};



/* Prototypen der benötigten Funktionen */

/* Gibt n mal das Zeichen c aus  */
void line(int n, char c);

/**
 * Liest den oberen Grenzwert ein und prüft ob sich der eingegebene Wert in [1; cMax] befindet.
 * Bei Fehleingabe wird der Lesevorgang wiederholt.
 * Im Erfolgsfall wird der eingelesene obere Grenzwert zurückgegeben.
 */
int readLimit(int cMax);

/**
 * Erstellt die Tabelle mit kumulierten Werten für 1 <= i <= limit.
 * Speichert die Werte jeder Tabellenzeile in der globalen Variable 'rows'.
 */
void calculateTable(int limit);

/**
 * Berechnet die Werte der i-ten Tabellenzeile und speichert die Werte
 * in der globalen Variable 'rows'
 */
void calculateRow(int i);

/**
 * Gibt die in der globalen Variable 'rows' gespeicherten Werte
 * als Tabelle aus.
 */
void printTable(int limit);

#endif