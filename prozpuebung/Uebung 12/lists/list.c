//**************************************************************************
// Header Datei : list.c
// Abstract data type (ADT) für Verwaltung einer einfach verketteten Liste
// Verfasser   : R.Feindor / R.Hüttl
// Datum       : 18.02.2008
// Änderungen  : 21.12.2010 J. Schmidt
//               10.01.2023 Jurgovsky
//***************************************************************************

#include "list.h"
#include "tester.h"

/**
 * Besetzt 'list' vor (NULL-Pointer, n_elements = 0 )
 */
void initList(List_t *list) {
   list->firstElement = NULL;
   list->lastElement = NULL;
   list->n_elements = 0;
}


/**
 * Erzeugt ein neues Element und fuegt dieses am Kopf (vorne) von 'list' ein
 */
void pushFront(List_t *list, const char *s) {
    Element_t *element = (Element_t*)malloc(sizeof(Element_t));
   
   assert(element != NULL, "Allokation für Element_s fehlgeschlagen!");

   strcpy(element->content, s);

   element->next = list->firstElement;
   list->firstElement = element;

   if(list->lastElement == NULL) {
      list->lastElement = element;
   }

   list->n_elements++;
}


/**
 * Gibt die Liste 'list' auf dem Bildschirm aus.
 */
void printList(const List_t *list) {
    Element_t * current = list->firstElement;
    int count = 1;
    if(current == NULL) {
        printf("Die Liste ist Leer!\n");
    }
    else {
        do {
            printf("Position: %d Content: %s\n", count, current->content);
            count++;
            current = current->next;
        } while (current != NULL);
    }
}


/**
 * Erzeugt ein neues Element und fuegt dieses am Ende (hinten) von 'list' ein
 */
void pushBack(List_t *list, const char *s) {
    Element_t *element = (Element_t*)malloc(sizeof(Element_t));

    assert(element != NULL, "Allokation für Element_s fehlgeschlagen!\n");

    element->next = NULL;
    strcpy(element->content, s);

    if(list->lastElement != NULL) {
        list->lastElement->next = element;
    }
    list->lastElement = element;

    if(list->firstElement == NULL) {
        list->firstElement = element;
    }

    list->n_elements++;
}


/**
 * Gibt das vorderste Element der Liste 'list' zurück und entfernt es aus der Liste.
 */
// gibt den Inhalt des ersten Elements zurück (kopiert den string in den
// übergebenen Buffer s) und entfernt das Element aus ‚list’
void popFront(List_t *list, char *s) {
    Element_t * element = list->firstElement;
    if(element != NULL)
    strcpy(s, element->content);
    if(list->firstElement == list->lastElement) {
        list->firstElement = NULL;
        list->lastElement = NULL;
    }
    else
    list->firstElement = element->next;

    list->n_elements--;
    free(element);
}


int main (void)
{
    printf("Manual test:\n");
    List_t list;

    initList(&list);

    pushBack(&list, "e1");
    pushFront(&list, "e2");

    char buffer[LENGTH];
    popFront(&list, buffer);
    printf("Element: %s\n", buffer);
    popFront(&list, buffer);
    printf("Element: %s\n", buffer);

    pushFront(&list, "andagain");

    popFront(&list, buffer);
    printf("Element: %s\n", buffer);


    printf("\n\n\n");
    runTests();

    return EXIT_SUCCESS;
}
