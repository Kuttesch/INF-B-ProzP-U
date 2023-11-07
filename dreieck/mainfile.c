//*******************************************************************
// Programm    : Dreieck                                          
// Verfasser   : Schmidt                                           
// Datum       : Urprogramm: 11.10.2012                                          
// Eingabe     : Seite + Winkel eines rechtwinkligen Dreiecks                            
// Verarbeitung: Berechnung aller Seiten und Winkel                   
// Ausgabe     : Ergebnis als Tabelle
// Änderungen  : 11.10.2012
//				 27.10.2023 (Jurgovsky)
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
    double a,b,c;           // Länge von Seite a, b und c
    double a_up,b_up,c_up;
    double a_down,b_down,c_down;
    double a_real,b_real,c_real;
    double alpha_deg,beta_deg,gamma_deg;
    double alpha_rad, beta_rad, gamma_rad;

    // Dialogeröffnung
    strich(50, '-');
    printf("Rechtwinkliges Dreieck\n");
    strich(50, '-');

    // Seite/Winkel einlesen
    printf("Bitte Laenge Seite a eingeben: ");
    scanf("%lf", &a);
    while(a<=0){
        printf("Laenge darf nicht negativ sein!!\n");
        printf("Bitte Laenge Seite a eingeben: ");
        scanf("%lf", &a);
    }

    printf("Bitte Winkel Alpha in Grad eingeben: ");
    scanf("%lf", &alpha_deg);
    while(alpha_deg<=0 || alpha_deg >= 90){
        printf("Winkel muss zwischen 1 und 89 liegen!!\n");
        printf("Bitte Winkel Alpha in Grad eingeben: ");
        scanf("%lf", &alpha_deg);
    }
    alpha_rad = deg2rad(alpha_deg);
    beta_rad = deg2rad(beta_deg);
    gamma_rad = deg2rad(gamma_deg);

    a_up = ceil(a);
    a_down = floor(a);
    a_real = round(a);

    c = a / sin(alpha_rad);
    c_up = ceil(c);
    c_down = floor(c);
    c_real = round(c);

    b = c * cos(alpha_rad);
    b_up = ceil(b);
    b_down = floor(b);
    b_real = round(b);

    gamma_deg = 90.000;
    beta_deg = 90 - alpha_deg;

    // Ausgabe aller Seiten und Winkel
    printf("                2 NK-Stellen   gerundet   abgerundet   aufgerundet\n");
    strich(57, '-');
    printf("a               %10.2f %10.0f   %10.0f    %10.0f\n", a, a_real, a_down, a_up);
    printf("b               %10.2f %10.0f   %10.0f    %10.0f\n", b, b_real, b_down, b_up);
    printf("c               %10.2f %10.0f   %10.0f    %10.0f\n", c, c_real, c_down, c_up);
    printf("Alpha (Grad)    %10.3f\n", alpha_deg);
    printf("Beta (Grad)     %10.3f\n", beta_deg);
    printf("Gamma (Grad)    %10.3f\n", gamma_deg);
    printf("Alpha (rad)     %10.3f\n", alpha_rad);
    printf("Beta (rad)      %10.3f\n", beta_rad);
    printf("Gamma (rad)     %10.3f\n", gamma_rad);
}

// Eingabe: w_deg, Winkel in Grad
// Ausgabe: w_rad, Winkel in rad
double deg2rad(double w_deg) {
    double w_rad = 0.0;
    w_rad = (w_deg/180)*PI;

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

