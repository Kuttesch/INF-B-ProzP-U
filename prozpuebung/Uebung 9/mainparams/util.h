#ifndef MAINPARAMS_SOLUTION_STRINGS_H
#define MAINPARAMS_SOLUTION_STRINGS_H

#define BINS 256              // Größe Feld für Statistik
#define MAX_PRINT_COLUMNS 13  // Anzahl Zeichen je Zeile in der Ausgabe



/**
 * Aufgabe 1:
 * Berechnet die absoluten Häufigkeiten der ASCII-Zeichen in argv und gibt sie als Histogramm aus
 */
void statistics(char *argv[], int argc);


/**
 * Aufgabe 2:
 * Invertiert die Reihenfolge der Wörter eines Textes 'argv'.
 * WICHTIG: Nicht inplace - der Inhalt von argv soll nicht verändert werden.
 *
 * 1. Erzeugen Sie zunächst eine Kopie der Wörter in argv
 * 2. Geben Sie den gesamten Text aus
 * 3. Invertieren Sie die Reihenfolge der Wörter
 * 4. Geben Sie den gesamten Text erneut aus
 */
void reverse(char *argv[], int argc);


/**
 * Gibt einen Text ((Feld von Zeichenketten) mit 'nrWords' Worten aus
 *
 */
void printText(char *text[], int nrWords);


/**
 * Invertiert in einem Text (Feld von Zeichenketten) die Reihenfolge
 * der Wörter; die Invertierung erfolgt ausschliesslich durch Vertauschung
 * von Zeigern, nicht durch umkopieren der Wörter !!
 * WICHTIG: inplace
 */
void reverseText(char *text[], int nrWords);


/**
 * Speicher freigeben:
 * Gibt sowohl den für einzelne Wörter allozierten Speicher als auch den Speicher
 * zur Verwaltung der Pointer (char*) auf die Wörter frei.
 */
void deleteText(char *text[], int nrWords);




#endif //MAINPARAMS_SOLUTION_STRINGS_H
