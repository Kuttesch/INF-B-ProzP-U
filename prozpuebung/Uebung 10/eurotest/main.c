/*******************************************************************/
// Programm    : Eurotest                                               
// Verfasser   : Schmidt / Jurgovsky
// Datum       : Urprogramm: 21.11.2012                                           
// Aufgabe     : Prüfung der Seriennummer von Euro-Banknoten
// Änderungen  : 21.11.2012
// 				 14.12.2022
/*******************************************************************/

#include <stdio.h>  		/* Standard Input/Output  z.B. scanf, printf 	*/
#include <stdlib.h>   		/* Standard-Bibliothek, z.B. für system       */
#include "serial.h"


int main () 
{
    char serialNumbers[8][50] = {
    "P02571225193", "P12571215193", "P0257122519", "P0257122519", "P025712251934", "P0257122519a", "P0257122!193", "p02571225193"
    };
    int n = 8;

	line(50, '-');
	printf("Eurotest\n");
	line(50, '-');

    // TODO
    for(int i = 0; i<=n; i++) {
        int * errors = eurotest(serialNumbers[i]);
        if(errors[0] == ec_ok) {
            printSerial(serialNumbers[i]);
        }
        else {
            printErrors(errors);
            line;
        }
    }

	return EXIT_SUCCESS;
}