//Kuttesch
//*******************************************************************
// Programm    : Zahltab
// Verfasser   : Feindor/Schmidt
// Datum       : Urprogramm: 1.10.1996
// Eingabe     : obere und untere Grenzen
// Verarbeitung: Berechnung von Standardfunktionen
// Ausgabe     : Zahlentabellen
// Änderungen  : 03.10.2012
// 				 19.10.2023 (Jurgovsky)
//*******************************************************************

// Einbinden von nötigen Header-Dateien
#include <stdio.h>  // Standard Input/ Output  z.B. scanf, printf
#include <math.h>   // Standard-Bibliothek für math. Funktionen z.B. sqrt

// Prototypen der benötigten Funktionen
void strich(int n, char c);  // gibt n mal das Zeichen c aus
void tabelleAusgeben(int von, int bis, int schritt);
int untereGrenzeEinlesen(void);
int obereGrenzeEinlesen(int ug);


int main() // Beginn Hauptprogramm          **************************
{
    //************************ Vereinbarungsteil **************************
    int von, bis, schritt;

    //************************ Anweisungsteil  ****************************
    // Dialogeröffnung
    strich(50, '-');
    printf("Zahltab: Berechnung von Zahlentafeln\n");
    strich(50, '-');

    //grenzenEinlesen(&von, &bis);
    von = untereGrenzeEinlesen();
    bis = obereGrenzeEinlesen(von);

    // Einlesen Schrittweite
    printf("Bitte Schrittweite eingeben: ");
    scanf("%d", &schritt);
    while (bis-von < schritt){
        printf("Bitte einen kleineren Schritt eingeben!!\n\n");
        printf("Bitte Schrittweite eingeben: ");
        scanf("%d", &schritt);
    }

    tabelleAusgeben(von, bis, schritt);

    return 0;
} //***************** Ende Hauptprogramm ***************************


// Definition der benötigten Funktionen

/**
 * Gib n mal das Zeichen c aus und beende die Zeile mit einem 'newline' Zeichen.
 */void strich(int n, char c) {
    int i;

    for (i = 1; i <= n; i = i + 1) {
        printf("%c", c);
    }

    printf("\n");
}

// Einlesen und prüfen der Tabellengrenzen

// Untergrenze
int untereGrenzeEinlesen(void) {
    int ug;

    do // Einlesen und Prüfen der unteren Grenze
    {
        printf("Bitte positive untere Grenze eingeben:  ");
        scanf("%d", &ug);
        if (ug <= 0) {
            printf("Bitte nur positive ganze Zahlen.\n");
        }
    } while (ug <= 0);

    return ug;
}

// Obergrenze
// Übergabeparameter ug: vorher eingelesene Untergrenze
int obereGrenzeEinlesen(int ug) {
    int og = 0;

    // Einlesen und Prüfen der oberen Grenze
    printf("Bitte obere Grenze eingeben: ");
    scanf("%d", &og);
    while (og <= ug){
        printf("Obere Grenze >> Untere Grenze!!\n");
        printf("Bitte obere Grenze eingeben: ");
        scanf("%d", &og);
    }


    return og;
}


// Ausgeben Tabelle
void tabelleAusgeben(const int von, const int bis, const int schritt) {
    int i;

    printf("  i    i^2      i^3    Wurzel(i)    log(i)       e^i\n");
    strich(70, '-');

    for (i = von; i <= bis; i += schritt) {
        double ido = (double)i;
        double ifl_squared = ido * ido;
        double ifl_cubed = pow(ido, 3);
        double ifl_sqrt = sqrt(ido);
        double ifl_log = log(ido);
        double ifl_exp = exp(ido);

        printf("%3d %7.0f %8.0f %12.6f %11.6f %12.6f\n", i, ifl_squared, ifl_cubed, ifl_sqrt, ifl_log, ifl_exp);
    }
}

