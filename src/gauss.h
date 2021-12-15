#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"

void swap(Matrix *mat, Matrix *b, int p); // zamien wiersze

void find_swap(Matrix *mat, Matrix *b, int k); //znajdz wiersze do zamiany

double det(Matrix *mat); // policz wyznacznik macierzy

double count_second_det(Matrix *mat); //oblicz wyznacznik 2 stopnia

double count_k(Matrix *mat, int i, int j); //wyznacz wspolczynnik k

double count_data_mat(Matrix *mat, int i, int j, int um, double k); // wyznacza wartość w indexie w tablicy data dla mat

double count_data_b(Matrix *b, int i, int j, double k); //wyznacz wartość indexie w tablicy data w macierzy b

void swap_rows (Matrix *matrix, int first, int second); //zamienia wiersze first z second w macierzy matrix

void sort_for_max_element(Matrix *mat, Matrix *b, int current_ID); //ustawia najwiekszy element na A[i][i]

void eliminate(Matrix *mat, Matrix *b); //wykonaj eliminacje gausa

#endif
