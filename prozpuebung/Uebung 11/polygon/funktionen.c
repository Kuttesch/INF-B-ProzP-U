/*******************************************************************
// Programm    : Polygon                                               
// Verfasser   : Schmidt / Jurgovsky                                             
// Datum       : Urprogramm: 5.12.2012                                           
// Aufgabe     : Berechnung Fläche regelmäßiger Polygone
// Änderungen  : 13.11.2012
// 				 21.12.2022
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf 	*/
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "funktionen.h"






/* Gibt n mal das Zeichen c aus */
void line(int n, char c) 
{
	for (int i = 0; i < n; i++) {
		printf("%c", c);
	}
	printf("\n");
}

static polygon_t calculatePolygon(int n_vertices, double radius) {
    polygon_t poly;

    poly.n_vertices = n_vertices;
    poly.side_length = 2.0 * radius * sin(M_PI / n_vertices);
    poly.area = (n_vertices * pow(poly.side_length, 2) / (4.0 * tan(M_PI / n_vertices)));
    poly.diff_polygon_cyrcle = (pow(radius, 2) * M_PI) - poly.area;

    return poly;
}

void calculatePolygons(polygon_t polygons[], inputParams_t params) {

    int poly_index = 0;
    for(int n = params.min_vertices; n <= params.max_vertices ; n++) {
       polygons[poly_index++] = calculatePolygon(n, params.radius);
    }
}

void showPolygons(polygon_t polygons[], int n_polygons) {
    printf("Anzahl Ecken (n)        Seitenlänge         Fläche          Abweichung zur Kreisfläche\n");
    for(int n = 0; n < n_polygons; n++) {
        printf(
                "%10d %16.2f %12.2f %16.2f\n",
                polygons[n].n_vertices,
                polygons[n].side_length,
                polygons[n].area,
                polygons[n].diff_polygon_cyrcle
        );
    }
}

cl_error_t scanCommandLine(int argc, char **argv, inputParams_t *params) {
    cl_error_t err = CL_NO_ERROR;
    int initializedParams = 0;

    for(int paramPos = 0; paramPos < argc; paramPos += 2) {

        if(strcmp(argv[paramPos], "-emin") == 0) {
            params->min_vertices = atoi(argv[paramPos+1]);
            initializedParams++;
        }
        else if(strcmp(argv[paramPos], "-emax") == 0) {
            params->max_vertices = atoi(argv[paramPos+1]);
            initializedParams++;
        }
        else if(strcmp(argv[paramPos], "-r") == 0) {
            params->radius = atoi(argv[paramPos+1]);
            initializedParams++;
        }
        else {
            return CL_UNKOWN_PARAM;
        }
    }

    if(initializedParams != 3) {
        return CL_PARAM_MISSING;
    }

    if(params->min_vertices < 2) {
        return CL_EMIN_OUT_OF_RANGE;
    }
    else if (params->max_vertices < params->min_vertices) {
        return CL_EMAX_OUT_OF_RANGE;
    }
    else if(params->radius <= 0) {
        return CL_RADIUS_INVALID;
    }
    else if((params->max_vertices - params->min_vertices + 1) > MAX_POLYS) {
        return CL_TOO_MANY_POLYS;
    }
    return err;
}

void printCLError(cl_error_t error) {
    switch(error) {
        case CL_TOO_MANY_POLYS:
            printf("Es können maximaml %d Polygone gespeichert werden.\n", MAX_POLYS);
            break;
        case CL_RADIUS_INVALID:
            printf("Der Radius muss größer Null sein.\n");
            break;
        case CL_EMAX_OUT_OF_RANGE:
            printf("Der Wert von -emax muss größer oder gleich -emin sein.\n");
            break;
        case CL_EMIN_OUT_OF_RANGE:
            printf("Der Wert für -emin muss größer 2 sein.\n");
            break;
        case CL_PARAM_MISSING:
            printf("Alle Parameter -emin -emax -r müssen beim Programmaufruf angegeben werden.\n");
            break;
        case CL_UNKOWN_PARAM:
            printf("Ein unbekannter Parameter wurde übergeben. Erwartete Parameter -emin -emax -r.\n");
            break;
    }
}
