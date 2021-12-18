#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"
#include "mat_io.h"

int main(int argc, char **argv) {
    if (argc < 2) {
		fprintf(stderr, "Nie podano zadnego pliku. Program zakonczy dzialanie.\n");
		exit(EXIT_FAILURE);
	}
	else if (argc < 3) {
		fprintf(stderr, "Nie podano macierzy wynikow rownan. Program zakonczy dzialanie.\n");
		exit(EXIT_FAILURE);
	}
    
    Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);

    
}