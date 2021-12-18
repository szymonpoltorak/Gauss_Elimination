#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char ** argv) {
	if (argc < 2) {
		fprintf(stderr, "Nie podano zadnego pliku. Program zakonczy dzialanie.\n");
		exit(EXIT_FAILURE);
	}
	else if (argc < 3) {
		fprintf(stderr, "Nie podano macierzy wynikow rownan. Program zakonczy dzialanie.\n");
		exit(EXIT_FAILURE);
	}
	if (argc < 4){
		printf("Aby użyć eliminacji Gaussa z wykorzystaniem elementu maksylnalnego dodaj na końcu flagę -USE_MAX\n");
	}
	int use_max = 0;
	if(argc > 3 && (strcmp(argv[3],"-USE_MAX") == 0)){
		use_max = 1;
		printf("Użyto najwiekszego elementu w eliminacji gaussa\n");
	}

	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if ((A -> r != A -> c) || (A -> r != b -> r)){
		fprintf(stderr, "Nie mozna wyznaczyc rozwiazan ukladu rownan. Program zakonczy dzialanie\n");
		freeMatrix(A);
		freeMatrix(b);
		exit(EXIT_FAILURE);
	}

	if (A == NULL)
		return -1;
	if (b == NULL)
		return -2;

	printf("Macierz wspolczynnikow:\n");
	printToScreen(A);
	printf("Macierz wynikow rownan:\n");
	printToScreen(b);

	eliminate(A,b, use_max);

	x = createMatrix(b->r, 1);

	if (x != NULL) {
		backsubst(x,A,b);
		printf("Macierz schodkowa:\n");
		printToScreen(A);
		printf("Macierz rozwiazan ukladu rownan:\n");
		printToScreen(x);
		freeMatrix(x);
		freeMatrix(A);
		freeMatrix(b);
	}
	else {
		fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
		freeMatrix(x);
		freeMatrix(A);
		freeMatrix(b);
		exit(EXIT_FAILURE);
	}

	exit (EXIT_SUCCESS);
}
