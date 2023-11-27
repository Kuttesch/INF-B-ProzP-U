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

int main(int argc, char **argv)    
{
	line(50, '-');
	printf("Flaeche regelmaessiger Polygone\n");
	line(50,'-');

    inputParams_t inputParams;
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


     // TODO
    polygon_t * polygons = (polygon_t*) malloc(n_polygons * sizeof(polygon_t));
    // polygons with calloc
    // polygon_t * polygons2 = (polygon_t*)calloc(n_polygons, sizeof(polygon_t));

    if(polygons == NULL) {
        exit(EXIT_FAILURE);
    }
    calculatePolygons(polygons,inputParams) ;
    showPolygons(polygons,n_polygons);

    free(polygons);
	return EXIT_SUCCESS;
}
