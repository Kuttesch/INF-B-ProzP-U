/*******************************************************************
/ Programm    : Datentypen                                          
/ Verfasser   : Schmidt                                           
/ Datum       : Urprogramm: 17.10.2012                                          
/ Eingabe     : Vier Zeichen                            
/ Verarbeitung: diverse Berechnungen                   
/ Änderungen  : 17.10.2012
/				02.11.2023 (Jurgovsky)
*******************************************************************/

// Einbinden von nötigen Header-Dateien
#include <stdio.h>    // Standard Input/ Output  z.B. scanf, printf

char kleinstesZeichen(char c[], int size);

char groesstesZeichen(char c[], int size);
int sizeOfArray;

int main() {
    char min, max;
    int mittel, abstand, tmp = 0;
    float mittelf;

    printf("Bitte geben Sie die Laenge ihrer Zeichenfolge ein: ");
    scanf("%d", &sizeOfArray);

    char c[sizeOfArray];

    printf("Bitte geben Sie %d Zeichen ein: ", sizeOfArray);
    scanf("%s", &c);

    int size = sizeof(c)/sizeof(char);

    for (int i = 0; i < size; i++){
            tmp = tmp + c[i];
    }

    mittelf = (float) tmp/size;
    mittel = (int) mittelf;

    printf("Eingegeben wurde:          ");
    for (int i = 0; i < size; i++) {
        printf("%c ", c[i]);
    }
    printf("\nASCII Codes:                ");
    for (int i = 0; i < size; i++) {
        printf("%d ", c[i]);
    }


    min = kleinstesZeichen(c, size);
    max = groesstesZeichen(c, size);
    abstand = max - min;

    printf("\nASCII Code (Mittel,int):    %d\n", mittel);
    printf("ASCII Code (Mittel,int):    %X\n", mittel);
    printf("ASCII Code (Mittel,fl):     %f\n", mittelf);
    printf("Mittleres Zeichen:          %c\n", mittel);
    printf("Kleinstes Zeichen:          %c\n", min);
    printf("Groesstes Zeichen:          %c\n", max);
    printf("Abstand Max/Min:            %d Zeichen\n", abstand);

    return 0;
}

char kleinstesZeichen(char c[], int size) {
    char min;
    int tmp;
    for (int i = 1; i <= size; i++) {
        for (int j = 0; j < size -1; j++) {
            if (c[j] > c[j + 1]) {
                tmp = (int)c[j];
                c[j] = c[j + 1];
                c[j + 1] = (char)tmp;
            }
        }
    }
    min = c[0];
    return min;
}
char groesstesZeichen(char c[], int size) {
    char max;
    int tmp;
    for (int i = 1; i <= size; i++) {
        for (int j = 0; j < size -1; j++) {
            if (c[j] < c[j + 1]) {
                tmp = (int)c[j];
                c[j] = c[j + 1];
                c[j + 1] = (char)tmp;
            }
        }
    }
    max = c[0];
    return max;
}

