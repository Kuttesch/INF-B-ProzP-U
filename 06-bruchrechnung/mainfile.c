/*******************************************************************/
// Programm    : Bruchrechnung                                         
// Verfasser   : Schmidt                                           
// Datum       : Urprogramm: 24.10.2012                                          
// Eingabe     : 2 rationale Zahlen                    
// Verarbeitung: Produkt, Quotient, Summe und Differenz der 
// 				 rationalen Zahlen   
// Ausgabe	   : Ergebnisse der Operationen                 
// Änderungen  : 24.10.2012
//				 19.11.2023 (Jurgovsky)
// *******************************************************************/

/* Einbinden von nötigen Header-Dateien                             */
#include <stdio.h>    /* Standard Input/ Output  z.B. scanf, printf */
#include "rational.h" /* Funktionsprototypen und Datentypen */


int main(void){
    struct bruch_s b1,b2,sum,dif,pro,quo;

	printf("Bitte Zaehler und Nenner Bruch 1 eingeben: \n");
    scanf("%d %d", &b1.zaehler, &b1.nenner);
	printf("Bitte Zaehler und Nenner Bruch 2 eingeben: \n");
    scanf("%d %d", &b2.zaehler, &b2.nenner);

   // struct bruch_s result_add = add(b1, b2);
    sum = add(b1,b2);
    dif = sub(b1,b2);
    pro = mul(b1,b2);
    quo = div(b1,b2);



    printf("%d / %d + %d / %d = %d / %d\n", b1.zaehler, b1.nenner, b2.zaehler, b2.nenner, sum.zaehler, sum.nenner);
    printf("%d / %d - %d / %d = %d / %d\n", b1.zaehler, b1.nenner, b2.zaehler, b2.nenner, dif.zaehler, dif.nenner);
    printf("%d / %d / %d / %d = %d / %d\n", b1.zaehler, b1.nenner, b2.zaehler, b2.nenner, pro.zaehler, pro.nenner);
    printf("%d / %d * %d / %d = %d / %d\n", b1.zaehler, b1.nenner, b2.zaehler, b2.nenner, quo.zaehler, quo.nenner);


	return 0;
}



