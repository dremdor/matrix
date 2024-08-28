#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = 0;

  if (A == NULL || A->matrix == NULL) {
    error = 1;
  } else {
    int n = A->rows;
    int m = A->columns;
    error = s21_create_matrix(n, m, result);
    if (error == 0) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }

  return error;
}
