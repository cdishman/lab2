#include <stdio.h>
#include <stdlib.h>
#include "dot.h"

/*  Compile by
gcc main.c dot.c -o main
*/


void scanV(double v[], int num) {
	int i;
	for (i=0; i<num; i++) {
		scanf(" %lf", &(v[i]));
		}
	}

int main(int argc, char* argv[]) {
	int vLen = 0;
	double *v1;
	double *v2;
	double dot1, dot2;
	if ((argc <= 1)) { 
		printf("Specify how many numbers in each vector as first command line argument\n");
		return -1;
	}
	if (!(vLen = atoi(argv[1]))) {
		printf("Computes the dot product of two arbitrary length vectors of real numbers\n");
		printf("First command line argument must be an integer indicating vector lengths\n");
		return -1;
	}
	v1 = (double*) malloc(vLen*sizeof(double));
	v2 = (double*) malloc(vLen*sizeof(double));

	printf("Enter a vector of %d numbers on one line separated by spaces\n", vLen);
	scanV(v1, vLen);

        printf("Enter a vector of %d numbers on one line separated by spaces\n", vLen);
	scanV(v2, vLen);

	dot1 = dot(v1, v2, vLen);
	dot2 = dot(v2, v1, vLen);

	printf("The first dot product: %d should be the same as the second: %d, right?\n", dot1, dot2);

	return 0;
	}
