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


static polygon_t calculatePolygon(int n_vertices, double radius) {
	polygon_t poly;

	poly.n_vertices = n_vertices;
	poly.l = 2.0 * radius * sin(M_PI / n_vertices);
	poly.area = n_vertices * poly.l * poly.l / (4.0 * tan(M_PI / n_vertices));
	poly.diff_circle = radius * radius * M_PI - poly.area;

	return poly;
}


void calculatePolygons(polygon_t polygons[], inputParams_t inputParams) {
	int polyCount = 0;
	for(int n = inputParams.min_vertices; n <= inputParams.max_vertices; n++) {
		polygons[polyCount++] = calculatePolygon(n, inputParams.radius);
	}
}


void showPolygons(polygon_t polygons[], int n_polygons) {

	printf("Anzahl Ecken (n)    Seitenlänge    Fläche    Abweichung zur Kreisfläche\n");

	for(int i = 0; i < n_polygons; i++) {
		printf(
			"%10d %16.2f %12.2f %15.2f\n",
			polygons[i].n_vertices,
			polygons[i].l,
			polygons[i].area,
			polygons[i].diff_circle
		);
	}
}


cl_error_t scanCommandLine(int argc, char **argv, inputParams_t *params) {

	cl_error_t err = CL_NO_ERROR;
	int initializedParams = 0;

	for(int paramPos = 1; paramPos < argc; paramPos += 2) {

		if(strcmp(argv[paramPos], "-emin") == 0) {
			params->min_vertices = atoi(argv[paramPos + 1]);
			initializedParams++;
		} else if(strcmp(argv[paramPos], "-emax") == 0) {
			params->max_vertices = atoi(argv[paramPos + 1]);
			initializedParams++;
		} else if(strcmp(argv[paramPos], "-r") == 0) {
			params->radius = atof(argv[paramPos + 1]);
			initializedParams++;
		} else {
			return CL_UNKOWN_PARAM;
		}
	}

    if(initializedParams != 3)
        return CL_PARAM_MISSING;

    if(params->min_vertices <= 2) {
        err = CL_EMIN_OUT_OF_RANGE;
    } else if(params->max_vertices < params->min_vertices) {
        err = CL_EMAX_OUT_OF_RANGE;
    } else if(params->radius <= 0.0) {
        err = CL_RADIUS_INVALID;
    } else if(params->max_vertices - params->min_vertices + 1 > MAX_POLYS) {
        err = CL_TOO_MANY_POLYS;
    } else {
        err = CL_NO_ERROR;
    }
	return err;
}


void printCLError(cl_error_t error) {
	switch (error)
	{
	case CL_PARAM_MISSING:
		printf("Alle Parameter -emin, -emax und -r müssen beim Programmaufruf angegeben werden.\n");
		break;
	case CL_UNKOWN_PARAM:
		printf("Unbekannter Parameter wurde übergeben. Erwartete Parameter -emin, -emax und -r.\n");
		break;
	case CL_EMIN_OUT_OF_RANGE:
		printf("Wert von -emin muss im Intervall [3, inf) liegen.\n");
		break;
	case CL_EMAX_OUT_OF_RANGE:
		printf("Wert von -emax muss größer gleich -emin sein.\n");
		break;
	case CL_RADIUS_INVALID:
		printf("Wert von -r muss im Intervall (0.0, inf) liegen.\n");
		break;
    case CL_TOO_MANY_POLYS:
        printf("Es können maximal %d Polygone gespeichert werden.\n", MAX_POLYS);
        break;
	default:
		break;
	}
}


/* Gibt n mal das Zeichen c aus */
void line(int n, char c) 
{
	for (int i = 0; i < n; i++) {
		printf("%c", c);
	}
	printf("\n");
}

