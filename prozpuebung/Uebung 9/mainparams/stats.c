//*******************************************************************
// Programm    : stats
// Verfasser   : Hüttl/ Feindor / Schmidt / Jurgovsky
// Übungsbeispiel für:
//               Kommandozeilen Argumente und
//               dynamische Speicherverwaltung
// Verarbeitung: Kommandozeilen-Argumente werden ausgewertet
//               umkopiert und in der Reihenfolge vertauscht.
// Datum       : 1.11.2002
// Änderungen  : 4.12.2012
//				07.12.2022
//*******************************************************************


#include <stdlib.h>		/* Standardfunktionen für Speicherverwaltung	*/
#include "util.h"


int main(int argc, char *argv[]) 
{

	// Aufgabe 1
	statistics(argv, argc);

	// Aufgabe 2
	reverse(argv, argc);

	return EXIT_SUCCESS;
}