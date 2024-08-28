#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = 0;

  if (A == NULL || A->matrix == NULL) {
    error = 1;
  } else if (A->rows != A->columns) {
    error = 2;
  } else {
    int n = A->rows;
    error = s21_create_matrix(n, n, result);
    if (error == 0) {
      if (n == 1) {
        result->matrix[0][0] = A->matrix[0][0];
      } else {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            matrix_t temp_matrix;
            error = s21_create_matrix(n - 1, n - 1, &temp_matrix);
            if (error == 0) {
              s21_minor(A, i, j, &temp_matrix);
              int sign = pow(-1, i + j);
              result->matrix[i][j] = s21_det(&temp_matrix) * sign;

              s21_remove_matrix(&temp_matrix);
            }
          }
        }
      }
    }
  }

  return error;
}
