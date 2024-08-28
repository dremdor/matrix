#include "../s21_matrix.h"
// #include <stdio.h>
////void s21_print_matrix(matrix_t A) {
//    int n = A.rows;
//    int m = A.columns;
////    for(int i = 0 ;i < n; ++i) {
//        for(int j = 0; j < m; ++j) {
//            if(j < m - 1)
//                printf("%lf ", A.matrix[i][j]);
//            else
//                printf("%lf", A.matrix[i][j]);
//        }
//        printf("\n");
//    }
//    for(int i = 0; i < 15; ++i) {
//        printf("-");
//    }
//    printf("\n");
//}

void s21_fill_matrix(double *values, matrix_t *A) {
  int n = A->rows;
  int m = A->columns;
  int index = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      A->matrix[i][j] = values[index];
      ++index;
    }
  }
}

double s21_det(matrix_t *A) {
  if (A->rows == 1) {
    return A->matrix[0][0];
  }

  double det = 0;
  int n = A->rows;

  for (int j = 0; j < n; ++j) {
    int sign = pow(-1, j);

    matrix_t sub_matrix;
    s21_create_matrix(n - 1, n - 1, &sub_matrix);
    s21_minor(A, 0, j, &sub_matrix);

    double sub_det = s21_det(&sub_matrix);
    s21_remove_matrix(&sub_matrix);

    det += sign * A->matrix[0][j] * sub_det;
  }
  return det;
}

void s21_minor(matrix_t *A, int row, int col, matrix_t *minor) {
  int n = A->rows;
  int shift_i = 0;

  for (int i = 0; i < n - 1; ++i) {
    if (i == row) {
      shift_i = 1;
    }
    int shift_j = 0;
    for (int j = 0; j < n - 1; ++j) {
      if (j == col) {
        shift_j = 1;
      }
      minor->matrix[i][j] = A->matrix[i + shift_i][j + shift_j];
    }
  }
}
