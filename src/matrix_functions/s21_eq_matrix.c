#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int equal = 1;
  int n = A->rows;
  int m = A->columns;

  if (n == B->rows && m == B->columns) {
    for (int i = 0; i < n && equal; ++i) {
      for (int j = 0; j < m && equal; ++j) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) equal = 0;
      }
    }
  } else
    equal = 0;

  return equal;
}
