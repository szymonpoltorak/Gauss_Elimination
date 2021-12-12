#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

void swap(Matrix *mat, Matrix *b, int p);

void find_swap(Matrix *mat, Matrix *b, int k);

double det(Matrix *mat);

double count_second_det(Matrix *mat);

double count_k(Matrix *mat, int i, int j);

double count_data_mat(Matrix *mat, int i, int j, int um, double k);

double count_data_b(Matrix *b, int i, int j, double k);

int eliminate(Matrix *mat, Matrix *b);

#endif
