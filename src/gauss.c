#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double count_k(Matrix *mat, int i, int j) {
	return (mat -> data[j][i]/mat->data[i][i]);
}

double count_data_mat(Matrix *mat, int i, int j, int um, double k){
	return (mat -> data[j][um] - k * mat->data[i][um]);
}

double count_data_b(Matrix *b, int i, int j, double k){
	return (b -> data[j][0] - k * b -> data[i][0]);
}

double count_second_det(Matrix *mat){
	return(mat -> data[0][0] * mat -> data[1][1] - mat -> data[1][0] * mat ->data[0][1]);
}

void swap(Matrix *mat, Matrix *b, int p){
	for(int i = p; i < p + 1; i++){
		double temp = b -> data[p][0];
		b -> data[p][0] = b -> data[p+1][0];
		b -> data[p+1][0] = temp;

		for (int j = 0; j < mat -> c; j++){
			temp = mat -> data[p][j];
			mat -> data[p][j] = mat -> data[p+1][j];
			mat -> data[p+1][j] = temp; 
		}
	}
}

void find_swap(Matrix *mat, Matrix *b, int k){
	int temp = 0;
	for (int p = k + 1; p < mat -> c; p++){
		if (mat -> data[k][p] != 0 && mat -> data[k][k] == 0){
			temp++;
			swap(mat, b, p - 1);
		}
		else {
			continue;
		}
	}
	if (temp == 0){
		fprintf(stderr, "Nie znaleziono wiersza do zamiany. Nie da sie obliczyc tej macierzy.\n");
		freeMatrix(mat);
		freeMatrix(b);
		exit(EXIT_FAILURE);
	}
}

double det(Matrix *mat){
	if (mat -> r == 1) {
		return (mat ->data[0][0]);
	}
	else if (mat -> r == 2){
		return count_second_det(mat);
	}
	else {
		Matrix *minor;
		minor = createMatrix(mat -> r - 1, mat -> c - 1);
		double sum = 0;
		
		for (int i = 0; i < mat -> r; i++){
				int rm = 0;
			for (register int w = 1; w < mat -> r; w++){
				int cm = 0;
				for (register int k = 0; k < mat -> c; k++){
					if (k == i){
						continue;
					}
					else{
						minor -> data[rm][cm] = mat -> data[w][k];
					}
					cm++;
				}
				rm++;
			}

			if (i % 2 == 0){
				sum += mat -> data[0][i] * det(minor);
			}
			else{
				sum -= mat -> data[0][i] * det(minor);
			}
		}
		freeMatrix(minor);
		return sum;
	}
}
void swap_rows (Matrix *matrix, int first, int second){
	double tmp;
	for (int i = 0; i < matrix->c; i++){
		tmp = matrix->data[first][i];
		matrix->data[first][i] = matrix->data[second][i];
		matrix->data[second][i] = tmp;
	}
}
void sort_for_max_element(Matrix *mat, Matrix *b, int current_ID){
	int biggestline = -1;
	//szukanie numeru wiersza w ktorym wspolczynnik mat[n][n] jest najwiekszy.
	biggestline = current_ID;
	for (int i = current_ID + 1; i < mat->r; i++){
		if(mat->data[i][current_ID] > mat->data[current_ID][current_ID]){
			if(mat->data[i][current_ID] > mat->data[biggestline][current_ID] && (fabs(mat->data[biggestline][current_ID]) > 0.0001)){
				biggestline = i;
			}
		}
	}
	//zamiana wiersza obecengo (current_ID) z najwiekszym (biggestline)
	swap_rows(mat, current_ID, biggestline);
	swap_rows(b, current_ID, biggestline);

}

void eliminate(Matrix *mat, Matrix *b){
	if (det(mat) != 0){
		for (int i = 0; i < mat -> r ; i++){
			sort_for_max_element(mat, b, i);
			for (int j = i + 1; j < mat -> c; j++){
				if (mat -> data[mat -> r - 1][mat -> c - 1] != 0){
					if (mat -> data[i][i] != 0){
						double k = count_k(mat, i, j);
						b -> data[j][0] = count_data_b(b, i, j, k);

						for (int um = i; um < mat -> r; um++){
							mat -> data[j][um] = count_data_mat(mat, i, j, um, k);
						}
					}
					else { //zamiana wierszy
						find_swap(mat, b, i);
					}
				}
				else{
					fprintf(stderr, "Wspolczynnik ann jest rowny 0. Uklad nie posiada jednoznacznego rozwiazania. Program zakonczy dzialanie.\n");
					freeMatrix(mat);
					freeMatrix(b);
					exit(EXIT_FAILURE);
				}
			}
		}		
	}
	else{
		fprintf(stderr, "Macierz jest osobliwa, nie mozna wyzynaczyc rozwiazan. Program zakonczy dzialanie.\n");
		freeMatrix(mat);
		freeMatrix(b);
		exit(EXIT_FAILURE);
	}
}
