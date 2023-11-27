#ifndef _EURO_H_
#define _EURO_H_

#define SNLEN 12

typedef enum 
{
	ec_ok,				/* Seriennummer gültig */
	ec_pz_falsch,		/* Prüfziffer falsch 
						   (Rest bei Division durch 9 ungleich 0)
						*/
	ec_zukurz,			/* Seriennummer zu kurz */
	ec_zulang,			/* Seriennummer zu lang */
	ec_LCfalsch,		/* Ländercode ist kein Großbuchstabe */
	ec_SNkeineZiffer	/* 10-stellige Seriennummer oder 
						   Prüfziffer enthält Zeichen,
						   die keine Ziffern sind.
						   */
} t_errcode;


/* Prototypen der benötigten Funktionen */

/**
 * Berechnet die Quersumme der Seriennummer und gibt die Quersumme zurück.
 */
int checksum(const char * serial);

/**
 * Prüft eine Seriennummer auf das korrekte Format (syntaktisch).
 * Im Erfolgsfall wird die Funktion 'checksum(..)' zur semantischen Prüfung aufgerufen.
 * Gibt einen Fehlercode vom Typ 't_errcode' zurück
 */
int* eurotest(const char * string);

/**
 * Übersetzt einen Fehlercode in eine für den Nutzer verständliche Fehlermeldung und
 * gibt diese in der Konsole aus.
 */
// TODO   show(..)

void printSerial(const char * serial);

void printErrors(int * errors);

/* Gibt n mal das Zeichen c aus  */
void line(int n, char c); 


#endif
