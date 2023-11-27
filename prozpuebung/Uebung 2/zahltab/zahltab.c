//*******************************************************************
// Programm    : Zahltab                                             
// Verfasser   : Feindor/Schmidt                                           
// Datum       : Urprogramm: 1.10.1996                                          
// Eingabe     : obere und untere Grenzen                            
// Verarbeitung: Berechnung von Standardfunktionen                   
// Ausgabe     : Zahlentabellen                                      
// Änderungen  : 03.10.2012
// 				 18.08.2022 (Jurgovsky)
//*******************************************************************

// Einbinden von nötigen Header-Dateien                              
#include <stdio.h>  // Standard Input/ Output  z.B. scanf, printf
#include <math.h>   // Standard-Bibliothek für math. Funktionen z.B. sqrt
#include <ctype.h>

// Prototypen der benötigten Funktionen 
void strich(int n, char c);  // gibt n mal das Zeichen c aus 
void tabelleAusgeben(const int von, const int bis, const int schritt);

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

    tabelleAusgeben(von, bis, schritt);

    return 0;
} //***************** Ende Hauptprogramm ***************************


// Definition der benötigten Funktionen      

/**
 * Gib n mal das Zeichen c aus und beende die Zeile mit einem 'newline' Zeichen.
 */
void strich(int n, char c) {
    int i;

    for (i = 1; i <= n; i++) {
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
    int og;

    do // Einlesen und Prüfen der oberen Grenze
    {
        printf("Bitte obere Grenze eingeben: ");
        scanf("%d", &og);
        if (og <= 0) {
            printf("Bitte nur positive ganze Zahlen.\n");
        }
        if (ug >= og) {
            printf("Bitte >= Untergrenze !!\n");
        }
    } while ((og <= 0) || (ug >= og));

    return og;
}


// Ausgeben Tabelle
void tabelleAusgeben(const int von, const int bis, const int schritt) {
    int i;

    printf("     i    i^2      i^3      sqrt(i)     ln(i)         exp(i)\n");
    strich(60, '-');
    for (i = von; i <= bis; i = i + schritt) {
        float ifl = (float) i;  // Wert der variable 'i' als float-Typ in Variable 'ifl' speichern.
        float ifl_squared = ifl * ifl;
        float ifl_cubed = pow(ifl, 3);
        float ifl_sqrt = sqrt(i);
        float ifl_ln = log(i);
        float ifl_exp_i = exp(i);

        printf("%6.f %6.f %8.f %11.6f %11.6f    %11.6f\n", ifl, ifl_squared, ifl_cubed, ifl_sqrt, ifl_ln, ifl_exp_i);
    }
}
