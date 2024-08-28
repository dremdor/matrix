#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;

  if (A == NULL || A->matrix == NULL) {
    error = 1;
  } else if (A->rows != A->columns) {
    error = 2;
  } else {
    double det = s21_det(A);
    if (det == 0) {
      error = 2;
    } else {
      matrix_t alg_comp_matrix;
      matrix_t transpose_matrix;
      if (A->columns == 1) {
        error = s21_mult_number(A, 1.0 / det, result);
      } else {
        error = s21_calc_complements(A, &alg_comp_matrix);
        if (error == 0 &&
            s21_transpose(&alg_comp_matrix, &transpose_matrix) == 0) {
          s21_mult_number(&transpose_matrix, 1.0 / det, result);
          s21_remove_matrix(&transpose_matrix);
        }
        s21_remove_matrix(&alg_comp_matrix);
      }
    }
  }
  return error;
}
