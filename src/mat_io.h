#ifndef _MAT_IO_H
#define _MAT_IO_H

typedef struct _Matrix {
	int r,c; // wiersze i kolumny
	double **data;
} Matrix;

/**
 * Zwraca 0 - udalo sie wczytac
 * Zwraca 1 - podczas wczytywania wystapil blad
 */

Matrix * readFromFile(char * fname); //przeczytaj dane z pliku
void printToScreen(Matrix *mat); //wyswietl macierz

Matrix * createMatrix(int r, int c); //stworz macierz
void freeMatrix(Matrix *mat); //zwolnij pamięć zajmowaną przez macierz

#endif
