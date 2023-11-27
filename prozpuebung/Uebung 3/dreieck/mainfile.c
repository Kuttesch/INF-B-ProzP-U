//*******************************************************************
// Programm    : Dreieck                                          
// Verfasser   : Schmidt                                           
// Datum       : Urprogramm: 11.10.2012                                          
// Eingabe     : Seite + Winkel eines rechtwinkligen Dreiecks                            
// Verarbeitung: Berechnung aller Seiten und Winkel                   
// Ausgabe     : Ergebnis als Tabelle
// Änderungen  : 11.10.2012
//				 18.08.2022 (Jurgovsky)
//*******************************************************************

// Einbinden von nötigen Header-Dateien                              
#include <stdio.h>    // Standard Input/ Output  z.B. scanf, printf
#include <math.h>     // Standard-Bibliothek für math. Funktionen z.B. sqrt
#include "mainfile.h" // eigene Header-Datei mit Funktionsprototypen


int main() // Beginn Hauptprogramm          **************************
{
    // Aufgabe: Dreieck
    dreieck();

    return 0;
} //***************** Ende Hauptprogramm ***************************


// Definition der benötigten Funktionen      

void dreieck(void) {
    double a;            // Länge von Seite a
    double b;
    double c;
    double alpha_deg;   // Winkel in Grad
    double beta_deg;
    double gamma_deg = 90;
    double alpha_rad;   // Winkel in Rad
    double beta_rad;
    double gamma_rad = deg2rad(gamma_deg);

    // Dialogeröffnung
    strich(50, '-');
    printf("Rechtwinkliges Dreieck\n");
    strich(50, '-');

    // Seite/Winkel einlesen

        printf("Bitte Laenge Seite a eingeben: ");
        scanf("%lf", &a);
        while (a < 0) {
            printf("Bitte positive Seitenlaenge eingeben: ");
            scanf("%lf", &a);
        }

    printf("Bitte Winkel Alpha in Grad eingeben: ");
    scanf("%lf", &alpha_deg);
    while(alpha_deg < 0) {
        printf("Bitte positive Winkel eingeben: ");
        scanf("%lf", &alpha_deg);
    }
    // Berechnung aller Seiten und Winkel
    beta_deg = 180 - (gamma_deg + alpha_deg);
    alpha_rad = deg2rad(alpha_deg);
    beta_rad = deg2rad(beta_deg);
    gamma_rad = deg2rad(gamma_deg);
    c = a/(sin(alpha_rad));
    b = c*(cos(alpha_rad));

    // speichern aller Ergebnisse in einer neuen Variablen

    // abrunden aller Seiten auf die nächste ganze Zahl
    double a_floor = floor(a);
    double b_floor = floor(b);
    double c_floor = floor(c);
    // aufrunden aller Seiten auf die nächste ganze Zahl
    double a_ceil = ceil(a);
    double b_ceil = ceil(b);
    double c_ceil = ceil(c);
    // (korrektes) Runden aller Seiten auf die nächste ganze Zahl
    double a_round = round(a);
    double b_round = round(b);
    double c_round = round(c);
    // Ausgabe aller Seiten und Winkel
    printf("                                            2 NK-Stellen   abrundet   aufgerundet   gerundet\n");
    strich(75, '-');
    printf("a                                         %10.2f %10.0f   %10.0f    %10.0f\n", a, a_floor, a_ceil, a_round);
    printf("b                                         %10.2f %10.0f   %10.0f    %10.0f\n", b, b_floor, b_ceil, b_round);
    printf("c                                         %10.2f %10.0f   %10.0f    %10.0f\n", c, c_floor, c_ceil, c_round);
    printf("Alpha (Grad)                              %10.2f\n",alpha_deg);
    printf("Beta (Grad)                               %10.2f\n",beta_deg);
    printf("Gamma (Grad)                              %10.2f\n",gamma_deg);
    printf("Alpha (Rad)                               %10.3f\n",alpha_rad);
    printf("Beta (Rad)                                %10.3f\n",beta_rad);
    printf("Gamma (Rad)                               %10.3f\n",gamma_rad);



}

// Eingabe: w_deg, Winkel in Grad
// Ausgabe: w_rad, Winkel in rad
double deg2rad(double w_deg) {
    double w_rad = 0.0;
    // Grad in rad umrechnen, Ergebnis in w_rad
    w_rad = w_deg*(PI/180);

    return w_rad;
}

// gibt n mal das Zeichen c aus 
void strich(int n, char c) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("%c", c);
    }

    printf("\n");
}

