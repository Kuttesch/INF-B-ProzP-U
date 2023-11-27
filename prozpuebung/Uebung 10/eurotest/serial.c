/*******************************************************************/
// Programm    : Eurotest                                               
// Verfasser   : Schmidt / Jurgovsky
// Datum       : Urprogramm: 21.11.2012                                           
// Aufgabe     : Prüfung der Seriennummer von Euro-Banknoten
// Änderungen  : 21.11.2012
// 				 14.12.2022
/*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <string.h>
#include "serial.h"





/**
 * Gibt n mal das Zeichen c aus
 */
void line(int n, char c) 
{
	for (int i = 0; i < n; i++) {
		printf("%c", c);
	}
	printf("\n");
}


void printSerial(const char * serial) {
    int n = strlen(serial);
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            printf("\033[0;35m%c\033[0m", serial[i]);
        } else if(i == SNLEN-1) {
            printf("\033[1;30m%c\033[0m", serial[i]);
        } else {
            printf("\033[0;34m%c\033[0m", serial[i]);
        }
    }
}

int checksum(const char * serial) {
    int sum = (int)serial[0];
    for(int i = 1; i <= 11; i++) {
        sum += ((int) serial[i]) - 48;
    }
    return sum;
}

int* eurotest(const char * string) {
    int errors[6] = {NULL, NULL, NULL, NULL, NULL, NULL,};
    int errorslength = 6;
    if(strlen(string) > 12) {
        for(int i = 0; i < errorslength; i++) {
            if(errors[i] == NULL){
                errors[i] = ec_zulang;
                break;
            }
        }
    }
    if(strlen(string) < 12) {
        for(int i = 0; i < errorslength; i++) {
            if(errors[i] == NULL){
                errors[i] = ec_zukurz;
                break;
            }
        }
    }
    if(((int)string[0] < 65) || (int)string[0] > 90) {
        for(int i = 0; i < errorslength; i++) {
            if(errors[i] == NULL){
                errors[i] = ec_LCfalsch;
                break;
            }
        }
    }
    else {
        for(int i = 1 ; i <= 11; i++) {
            if(((int)string[i] < 48) || (int)string[i] > 57) {
                for(int i = 0; i < errorslength; i++) {
                    if(errors[i] == NULL){
                        errors[i] = ec_SNkeineZiffer;
                        break;
                    }
                }
            }
        }
    }
    if(checksum(string) % 9 != 0) {
        for(int i = 0; i < errorslength; i++) {
            if(errors[i] == NULL){
                errors[i] = ec_pz_falsch;
                break;
            }
        }
    }
    if(errors[0] == NULL) {
        errors[0] = ec_ok;
    }
    return errors;
}

void printErrors(int * errors) {
    int i = 0;
    printf("Errors:");
    while(errors[i] != NULL) {
        printf("%d\n", errors[i]);
    }
}