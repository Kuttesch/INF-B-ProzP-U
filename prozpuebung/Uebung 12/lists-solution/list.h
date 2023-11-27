//**************************************************************************
// Header Datei : list.h
// Abstract data type (ADT) für Verwaltung einer einfach verketteten Liste
// Verfasser   : R.Feindor / R.Hüttl
// Datum       : 18.02.2008
// Änderungen  : 21.12.2010 J. Schmidt
//               11.01.2023 Jurgovsky
//***************************************************************************

#ifndef LIST_H
#define LIST_H

#include "util.h"
#include <string.h>

#define LENGTH 80

/**
 * Ein einzelnes Element der Datenstruktur.
 * Die Attribute dieses Elements sind anwendungsspezifisch.
 */
typedef struct Element_s
{ 
   char content[LENGTH];       // Inhalt als String fester Länge 
   struct Element_s *next;    // Zeiger auf das nächste Element der Datenstruktur
} Element_t;


/**
 * Der Listenkopf bietet Zugriff auf das erste/letzte Element der Liste und verwaltet die Größe der Liste.
 * Die Attribute des Listenkopfes sind unabhängig von der Gestaltung der einzelnen Listenelemente.
 */
typedef struct  
{
   struct Element_s *firstElement;
   struct Element_s *lastElement;
   int n_elements;
} List_t;


/**
 * Besetzt 'list' vor (NULL-Pointer, n_elements = 0 )
 */
void initList(List_t *list);


/**
 * Erzeugt ein neues Element und fuegt dieses am Kopf (vorne) von 'list' ein
 */
void pushFront(List_t *list, const char *s);


/**
 * Gibt die Liste 'list' auf dem Bildschirm aus.
 */
void printList(const List_t *list);


/**
 * Erzeugt ein neues Element und fuegt dieses am Ende (hinten) von 'list' ein
 */
void pushBack(List_t *list, const char *s);


/**
 * Gibt das vorderste Element der Liste 'list' zurück und entfernt es aus der Liste.
 */
// gibt den Inhalt des ersten Elements zurück (kopiert den string in den
// übergebenen Buffer s) und entfernt das Element aus ‚list’
void popFront(List_t *list, char *s);


/**
 * Speichert den Inhalt der Liste in einer Datei mit dem Namen 'fileName'
 */
bool saveContent(List_t * list, char * fileName);

#endif // LIST_H

