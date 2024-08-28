#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;

  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL) {
    error = 1;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    error = 2;
  } else {
    int n = A->rows;
    int m = A->columns;
    error = s21_create_matrix(n, m, result);
    if (error == 0) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }

  return error;
}
