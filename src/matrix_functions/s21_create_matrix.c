#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;

  if (result != NULL) {
    result->matrix = NULL;
    result->rows = 0;
    result->columns = 0;
  }

  if (rows > 0 && columns > 0 && result != NULL) {
    result->rows = rows;
    result->columns = columns;

    result->matrix = (double **)malloc(result->rows * sizeof(double *));
    if (result->matrix == NULL) error = 1;

    for (int i = 0; i < result->rows && error == 0; ++i) {
      result->matrix[i] = (double *)malloc(result->columns * sizeof(double));
      if (result->matrix[i] == NULL) error = 1;
    }
  } else
    error = 1;

  return error;
}
