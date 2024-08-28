#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = 0;

  if (A == NULL || A->matrix == NULL) {
    error = 1;
  } else {
    int n = A->rows;
    int m = A->columns;
    error = s21_create_matrix(m, n, result);
    if (error == 0) {
      for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  }

  return error;
}
