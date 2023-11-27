//*******************************************************************
// Modul     : util.c                                              
// Verfasser : Feindor / Schmidt                                         
// Datum     : Urprogramm 1.10.1996                                           
// Inhalt    : Allgemeine Hilfsfunktionen für Übungsaufgaben                       
// Änderungen: 5.11.2010
// 			  11.01.2023 (Jurgovsky)
//*******************************************************************

// Einbinden von nötigen Header-Dateien                      
#include "util.h"

/**
 * Gibt n mal das Zeichen c aus
 */
void line(int n, char c)  
{
	for (int i = 0; i < n; i++) {
		printf("%c",c);
	}
	printf("\n");
}

/**
 * Gibt 'headline' mit ASCII-Rahmen aus.
 */
void dialog(char *headline) 
{
	line(50, '-');
	printf("%s \n", headline);
	line(50, '-');
}

/**
 * Beendet das Programm mit einer 'message' falls 'assertion' false ist.
 * Andernfalls kehrt die Funktion ohne Operation zurück.
 */
void assert (bool assertion, char *message)
{
	if (assertion) return;

	fprintf(stdout, "\n*** Fehler *** %s *** \n", message);
	
	// Hier können beliebige weitere Aktionen erfolgen:
	// Speicherfreigabe, Log-Datei beschreiben, Verbindungen schließen, etc.

	exit(EXIT_FAILURE);
}


