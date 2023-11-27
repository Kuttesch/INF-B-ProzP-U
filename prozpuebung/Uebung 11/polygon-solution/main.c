/*******************************************************************
// Programm    : Polygon                                               
// Verfasser   : Schmidt / Jurgovsky                                             
// Datum       : Urprogramm: 5.12.2012                                           
// Aufgabe     : Berechnung Fläche regelmäßiger Polygone
// Änderungen  : 13.11.2012
// 				 21.12.2022
*******************************************************************/

#include <stdio.h>  	/* Standard Input/Output  z.B. scanf, printf 	*/
#include <stdlib.h>   	/* Standard-Bibliothek, z.B. für system       	*/
#include "funktionen.h"

#define EX 1

int main(int argc, char **argv)    
{
	line(50, '-');
	printf("Flaeche regelmaessiger Polygone\n");
	line(50,'-');

	inputParams_t inputParams;

#if (EX == 1  || EX == 2)
//	 Aufgabe 1+2
	 printf("Minimale Anzahl Ecken: ");
	 scanf("%d", &inputParams.min_vertices);

	 printf("Maximale Anzahl Ecken: ");
	 scanf("%d", &inputParams.max_vertices);

	 printf("Umkreisradius: ");
	 scanf("%lf", &inputParams.radius);

     int n_polygons = inputParams.max_vertices - inputParams.min_vertices + 1;
     if(n_polygons > MAX_POLYS) {
         exit(EXIT_FAILURE);
     }

#if EX == 1
     //	 Aufgabe 1
	 polygon_t polygons[MAX_POLYS];
#else

    polygon_t *polygons = (polygon_t*)calloc(n_polygons, sizeof(polygon_t));

    if(polygons == NULL) {
        printf("Error allocating memory for polygons. exiting...\n");
        exit(EXIT_FAILURE);
    }
#endif

    calculatePolygons(polygons, inputParams);
    showPolygons(polygons, inputParams.max_vertices - inputParams.min_vertices + 1);

#if EX == 2
    if(polygons != NULL) {
        free(polygons);
    }
#endif
#endif



#if EX == 3
	// Aufgabe 3

    cl_error_t error;

	error = scanCommandLine(argc, argv, &inputParams);
	printCLError(error);

	if(error == CL_NO_ERROR) {

		// Aufgabe 2
		int n_polygons = inputParams.max_vertices - inputParams.min_vertices + 1;
		polygon_t *polygons = (polygon_t*)calloc(n_polygons, sizeof(polygon_t));

		if(polygons == NULL) {
			printf("Error allocating memory for polygons. exiting...\n");
			exit(EXIT_FAILURE);
		}
		// END: Aufgabe 2

		calculatePolygons(polygons, inputParams);
		showPolygons(polygons, inputParams.max_vertices - inputParams.min_vertices + 1);

		// Aufgabe 2
		if(polygons != NULL) {
			free(polygons);
		}
		// END: Aufgabe 2
	}
#endif

	return EXIT_SUCCESS;
}
