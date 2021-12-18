#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int matrix_cmp ( Matrix *first, Matrix *second);
int test_jeden ( void );
int test_dwa ( void );
int test_trzy ( void );
int test_cztery ( void );

int main( void ) {
  //TEST1: Dwa poprawne układy równań
  if (test_jeden() == 0){
    printf("Test 1 - POMYŚLNY!\n");
  } else {
    printf("Test 1 - BłĄD!\n");
  }

  //TEST2: Zero na pierwszym miejscu
  if (test_dwa() == 0){
    printf("Test 2 - POMYŚLNY!\n");
  } else {
    printf("Test 2 - BłĄD!\n");
  }

  //TEST3: Wyznacznik zerowy
  if (test_trzy() == 0){
    printf("Test 3 - POMYŚLNY!\n");
  } else {
    printf("Test 3 - BłĄD!\n");
  }
  if (test_cztery() == 0){
    printf("Test 4 - POMYŚLNY!\n");
  } else {
    printf("Test 4 - BłĄD!\n");
  }
  //TEST4: Litery w macierzy, za mało danych
}
int matrix_cmp (Matrix *first, Matrix *second){
  if( (first->r != second->r) || (first->r != second->r)){
    return 1; //inne rozmiary
  }
  for (int rows = 0; rows < first->r; rows++){
      double difference = fabs(first->data[rows][0] - second->data[rows][0]);
      if(difference > 0.0001){
        return 2; //rozne wartosci
      }
  }
  return 0;
}

int test_jeden ( void ){
  int howmamyerrors = 0;
  Matrix *cztery_rownania_A = readFromFile("./danetestowe/Zestaw_TEST1/cztery_rownania_A");
  Matrix *cztery_rownania_B = readFromFile("./danetestowe/Zestaw_TEST1/cztery_rownania_B");
  Matrix *cztery_rownania_C = readFromFile("./danetestowe/Zestaw_TEST1/cztery_rownania_C");
  Matrix *wynikjeden;

  eliminate(cztery_rownania_A,cztery_rownania_B, 1);
  wynikjeden = createMatrix(cztery_rownania_B->r,1);
  backsubst(wynikjeden, cztery_rownania_A, cztery_rownania_B);

  if(matrix_cmp(wynikjeden, cztery_rownania_C) != 0){
    howmamyerrors++;
  }
  freeMatrix(cztery_rownania_A);
  freeMatrix(cztery_rownania_B);
  freeMatrix(cztery_rownania_C);
  freeMatrix(wynikjeden);

  Matrix *dwa_rownania_A = readFromFile("./danetestowe/Zestaw_TEST1/dwa_rownania_A");
  Matrix *dwa_rownania_B = readFromFile("./danetestowe/Zestaw_TEST1/dwa_rownania_B");
  Matrix *dwa_rownania_C = readFromFile("./danetestowe/Zestaw_TEST1/dwa_rownania_C");
  Matrix *wynikdwa;

  eliminate(dwa_rownania_A,dwa_rownania_B, 1);
  wynikdwa = createMatrix(dwa_rownania_B->r,1);
  backsubst(wynikdwa, dwa_rownania_A, dwa_rownania_B);

  if(matrix_cmp(wynikdwa, dwa_rownania_C) != 0){
    howmamyerrors++;
  }
  freeMatrix(dwa_rownania_A);
  freeMatrix(dwa_rownania_B);
  freeMatrix(dwa_rownania_C);
  freeMatrix(wynikdwa);

  return howmamyerrors;
}
int test_dwa ( void ){
  int howmamyerrors = 0;
  Matrix *zero_na_pierw_A = readFromFile("./danetestowe/Zestaw_TEST2/zero_na_pierw_A");
  Matrix *zero_na_pierw_B = readFromFile("./danetestowe/Zestaw_TEST2/zero_na_pierw_B");
  Matrix *zero_na_pierw_C = readFromFile("./danetestowe/Zestaw_TEST2/zero_na_pierw_C");
  Matrix *wynik;

  eliminate(zero_na_pierw_A,zero_na_pierw_B, 1);
  wynik = createMatrix(zero_na_pierw_B->r,1);
  backsubst(wynik, zero_na_pierw_A, zero_na_pierw_B);

  if(matrix_cmp(wynik, zero_na_pierw_C) != 0){
    howmamyerrors++;
  }
  freeMatrix(zero_na_pierw_A);
  freeMatrix(zero_na_pierw_B);
  freeMatrix(zero_na_pierw_C);
  freeMatrix(wynik);

  return howmamyerrors;
}
int test_trzy ( void ){
  int howmamyerrors = 0;
  Matrix *uklad_osobliwy_A = readFromFile("./danetestowe/Zestaw_TEST3/uklad_osobliwy_A");
  if (det(uklad_osobliwy_A) == 0){
    howmamyerrors = 0;
  } else {
    howmamyerrors = 1;
  }
  return howmamyerrors;
}
int test_cztery ( void ){
  int howmamyerrors = 0;
  if (readFromFile("./danetestowe/Zestaw_TEST4/litery_A") != 0) { //blad bo litery
    howmamyerrors++;
  }
  if (readFromFile("./danetestowe/Zestaw_TEST4/litery_B") != 0) { //blad bo litery
    howmamyerrors++;
  }
  if (readFromFile("./danetestowe/Zestaw_TEST4/za_malo_A") != 0) { //blad bo za mało danych
    howmamyerrors++;
  }
  if (readFromFile("./danetestowe/Zestaw_TEST4/za_malo_B") == 0) { //brak błędu bo wszystko dobrze
    howmamyerrors++;
  }
  return howmamyerrors;
}
