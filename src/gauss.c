#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

double count_k(Matrix *mat, int i, int j) {
	return (mat -> data[j][i]/mat->data[i][i]);
}

double count_data_mat(Matrix *mat, int i, int j, int um, double k){
	return (mat -> data[j][um] - k * mat->data[i][um]);
}

double count_data_b(Matrix *b, int i, int j, double k){
	return (b -> data[j][i] - k * b -> data[i][0]);
}

int eliminate(Matrix *mat, Matrix *b){

	for (int i = 0; i < mat -> r ; i++){
		for (int j = 1; j < mat -> c; j++){
			if (mat -> data[i][i] != 0){
				double k = count_k(mat, i, j);

				for (int um = 0; um < mat -> r; um++){
					mat -> data[j][um] = count_data_mat(mat, i, j, um, k);
					//mat -> data[j][um] - k * mat->data[i][um];
				}
				
				b -> data[i][j] = count_data_b(mat, i, j, k);
				//b -> data[j][i] - k * b -> data[i][0];
			}
			else {
				fprintf(stderr,"Macierz osobliwa , nie mozna utworzyc macierzy trojkatnej. Program skonczy dzialanie.");
				return EXIT_FAILURE;
			}
		}
	}

	return EXIT_SUCCESS;
}