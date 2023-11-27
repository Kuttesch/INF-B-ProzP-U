#ifndef _POLY_H_
#define _POLY_H_

#define MAX_POLYS 100

typedef enum
{
	CL_NO_ERROR,			/* Parameter sind gültig */
	CL_EMIN_OUT_OF_RANGE,	/* emin ist kleiner/gleich 2 */
	CL_EMAX_OUT_OF_RANGE,	/* emax ist kleiner als emin */
	CL_RADIUS_INVALID,	    /* Radius ist kleiner/gleich 0.0 */
    CL_TOO_MANY_POLYS,      /* Anzahl nachgefragter Polygone übersteigt Limit: (emax - emin + 1) > MAX_POLYS */
	CL_PARAM_MISSING,	    /* einer der Parameter emin/emax/r fehlt */
	CL_UNKOWN_PARAM		    /* ein unbekannter Kommandozeilenparameter wurde verwendet */
} cl_error_t;


typedef struct {
	int min_vertices;
	int max_vertices;
    double radius;
} inputParams_t;


typedef struct {
	int n_vertices;
	double area;
    double l;
    double diff_circle;
} polygon_t;


/* Prototypen der benötigten Funktionen */
// Aufgabe 1
void calculatePolygons(polygon_t polygons[], inputParams_t inputParams);
void showPolygons(polygon_t polygons[], int n_polygons);

// Aufgabe 3
cl_error_t scanCommandLine(int argc, char **argv, inputParams_t *params);
void printCLError(cl_error_t error);

/* Gibt n mal das Zeichen c aus  */
void line(int n, char c); 

#endif
