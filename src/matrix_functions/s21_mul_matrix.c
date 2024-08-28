#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;

  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL) {
    error = 1;
  } else if (A->columns != B->rows) {
    error = 2;
  } else {
    int n = A->rows;
    int m = A->columns;
    int l = B->columns;
    error = s21_create_matrix(n, l, result);
    if (error == 0) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          double sum = 0;
          for (int k = 0; k < m; ++k) {
            sum += A->matrix[i][k] * B->matrix[k][j];
          }
          result->matrix[i][j] = sum;
        }
      }
    }
  }

  return error;
}
