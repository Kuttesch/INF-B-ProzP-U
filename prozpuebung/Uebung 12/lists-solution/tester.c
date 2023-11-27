//*********************************************************************
// Source File : tt_liste.c
// Testtreiber für ADT liste (einfach verkettete Liste)
// Verfasser   : R.Feindor / R.Hüttl
// Datum       : 18.02.2008
// Änderungen  : 21.12.2010 J. Schmidt
// 				 11.01.2023 Jurgovsky
//*********************************************************************

#include "list.h"
#include <time.h>

#define N 10  	// Anzahl der Elemente
//#define VERBOSE

char testListe[N][LENGTH];   // globale Testdaten N Elemente der Standard-LAENGE

// Generieren von zufälligen globalen Testdaten
void GenTestdaten(void) 
{	
	int i, z;
	srand((int) time(0)); // Start des Zufallsgenerators
	for (i=0; i < N; i++)
	{
		z = rand() % (10*N);    // Zufallszahl 0..10N
		sprintf (testListe[i], "Testelement %5i", z); // füllen Elemente in testListe
	}
}

void pushFrontTest(List_t *list)
{
    char s[LENGTH];

	// Testfall 1:
	printf(":: pushFrontTest: push und print\n");
	for (int i = 0; i < N; i++) {
		pushFront(list, testListe[i]);
	}
#ifdef VERBOSE
	printList(list);
#endif

	assert(list->n_elements == N, "falsche Elementezahl");
    assert(strcmp(list->firstElement->content, testListe[N-1]) == 0, "firstElement zeigt auf falsches Element");
    assert(strcmp(list->lastElement->content, testListe[0]) == 0, "lastElement zeigt auf falsches Element");

    // Testfall 2:
    printf(":: popFrontTest\n");

    for (int i = 0; i < N; i++)
    {
        popFront(list, s);
#ifdef VERBOSE
        printf("pop: %s Rest: \n",s);
#endif

        assert(strcmp(s, testListe[N-i-1])==0, "falsche Reihenfolge");	// Reihenfolge prüfen
        assert(list->n_elements == (N-i-1), "falsche Elementezahl");	// Anzahl prüfen
#ifdef VERBOSE
        printList(list);
#endif
    }

    assert (list->n_elements == 0, "falsche Elementezahl");
}

void pushBackTest(List_t *list)
{
	int i;
	char s[LENGTH];

	// Testfall 3:
	printf(":: pushBackTest: Einfügen und Liste ausgeben\n");

	for (i = 0; i < N; i++) {
		pushBack(list, testListe[i]);
	}
#ifdef VERBOSE
	printList(list);
#endif
	assert (list->n_elements == N, "falsche Elementezahl");

	// Testfall 4
	printf(":: popFrontTest: pop einzeln\n");

	for (i = 0; i < N; i++)
	{
		popFront(list, s);
#ifdef VERBOSE
		printf("pop: %s  Rest: \n",s);
#endif
		assert (strcmp(s, testListe[i])==0, "falsche Reihenfolge");		// Reihenfolge prüfen
		assert (list->n_elements == (N-i-1), "falsche Elementezahl");	// Anzahl prüfen
#ifdef VERBOSE
		printList(list);
#endif
	}
	assert (list->n_elements == 0, "falsche Elementezahl");
}


void runTests() {
    List_t list;

    GenTestdaten();

    initList(&list);

    printf("Testtreiber beginnt mit leerer Liste:\n");
    printList(&list);
    pushFrontTest(&list);
    pushBackTest(&list);
    printf("Testtreiber erfolgreich beendet.\n");
}
