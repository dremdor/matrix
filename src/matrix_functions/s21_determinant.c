#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error = 0;

  if (A == NULL || A->matrix == NULL || result == NULL) {
    error = 1;
  } else if (A->rows != A->columns) {
    error = 2;
  } else {
    *result = s21_det(A);
  }

  return error;
}
