#include "vectors.h"
#include <math.h>
#include <stdio.h>

// get Vectornorm
double normL2(struct Vector2_s * vec) {
    double norm = sqrt(pow(vec->x, 2.0) + pow(vec->y, 2.0));
    return norm;
}
// search shortest vector
int argMin(struct Vector2_s * data, int start, int end) {
    int min = -1;
    for(int i = start+1; i < end; i++) {
        if(normL2(&data[start]) > normL2(&data[i])) {
            if(min < 0) {
                min = i;
            }
            else {
                if(normL2(&data[i]) < normL2(&data[min])) {
                    min = i;
                }
            }
        }
    }
    return min;
}

//swap two elements
void swap(struct Vector2_s * a, struct Vector2_s * b) {
    struct Vector2_s tmp = *a;
    *a = *b;
    *b = tmp;
}


void selectionSort(struct Vector2_s data[], int n) {
    for(int i = 0; i < n; i++) {
        int positionmin = argMin(data, i, n);
        if(positionmin >= 0) {
            swap(&data[i], &data[positionmin]);
        }
    }
}


void printVectorArray(struct Vector2_s data[], int n) {
    printf("\nVectorArray:\n");
    for(int i = 0; i < n; i++) {
        printf("Index: %d\t [Vector2f x = %4.1f\t y = %4.1f\t normL2 = %4.1f]\n", i, data[i].x, data[i].y, normL2(&data[i]));
    }
}