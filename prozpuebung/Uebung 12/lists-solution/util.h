//*******************************************************************
// Modul     : util.h                                              
// Verfasser : Feindor / Schmidt                                         
// Datum     : Urprogramm 1.10.1996                                           
// Inhalt    : Allgemeine Hilfsfunktionen für Übungsaufgaben                       
// Änderungen: 5.11.2010
// 			  11.01.2023 (Jurgovsky)
//*******************************************************************

#ifndef INF1_H
#define INF1_H

// Einbinden von nötigen Header-Dateien                              
#include <stdio.h>      // Standard Input/ Output  z.B. scanf, printf 
#include <stdlib.h>     // für Standard-Utility-Funktionen wie exit() oder rand() 
#include <stdbool.h>


// Deklaration von Prototypen, die in gesonderten Modulen (z.B. util.c)
// bereitgestellt werden. Diese Module müssen daher dazugelinkt werden 
void line(int n, char c);                   // gibt n mal das Zeichen c aus
void assert (bool assertion, char *message);// gibt Fehlermeldung, wenn nicht ok 

#endif

