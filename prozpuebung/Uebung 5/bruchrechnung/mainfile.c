/*******************************************************************/
// Programm    : Bruchrechnung                                         
// Verfasser   : Schmidt                                           
// Datum       : Urprogramm: 24.10.2012                                          
// Eingabe     : 2 rationale Zahlen                    
// Verarbeitung: Produkt, Quotient, Summe und Differenz der 
// 				 rationalen Zahlen   
// Ausgabe	   : Ergebnisse der Operationen                 
// Änderungen  : 24.10.2012
//				 18.08.2022 (Jurgovsky)
// *******************************************************************/

/* Einbinden von nötigen Header-Dateien                             */
#include <stdio.h>    /* Standard Input/ Output  z.B. scanf, printf */
#include "rational.h"



int main(void)
{

    //variables
    struct bruch_s fraction1 = {0,0};
    struct bruch_s fraction2 = {0,0};
    struct bruch_s result = {0,0};

    printf("Bitte Zaehler und Nenner Bruch 1 eingeben: \n");
    scanf("%d %d",&fraction1.zaehler, &fraction1.nenner);
    printf("Bitte Zaehler und Nenner Bruch 2 eingeben: \n");
    scanf("%d %d",&fraction2.zaehler, &fraction2.nenner);

    result =  rational_product(fraction1, fraction2);
    printf("%d/%d * %d/%d = %d/%d\n",fraction1.zaehler, fraction1.nenner, fraction2.zaehler,fraction2.nenner, result.zaehler, result.nenner);
    result = rational_quotient(fraction1, fraction2);
    printf("%d/%d / %d/%d = %d/%d\n",fraction1.zaehler, fraction1.nenner, fraction2.zaehler,fraction2.nenner, result.zaehler, result.nenner);
    result = rational_sum(fraction1, fraction2);
    printf("%d/%d + %d/%d = %d/%d\n", fraction1.zaehler, fraction1.nenner, fraction2.zaehler,fraction2.nenner, result.zaehler, result.nenner);
    result = rational_diff(fraction1, fraction2);
    printf("%d/%d - %d/%d = %d/%d\n", fraction1.zaehler, fraction1.nenner, fraction2.zaehler,fraction2.nenner, result.zaehler, result.nenner);

    return 0;
}
