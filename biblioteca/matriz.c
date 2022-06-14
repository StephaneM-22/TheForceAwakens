#include "./matriz.h"

int ***criar(int p, int pc)
{
  int atual = p + 1;
  int ***mat;

  int a = atual + 1;
  int b = p + 1;
  int c = pc + 1;

  int i, j;

  mat = (int ***)malloc(a * sizeof(int *));

  for (i = 0; i < a; i++)
  {
    mat[i] = (int **)malloc(b * sizeof(int *));
  }

  for (i = 0; i < a; i++)
  {
    for (j = 0; j < b; j++)
    {
      mat[i][j] = (int *)malloc(c * sizeof(int *));
    }
  }

  return mat;
}

void free_matrix(int ***mat, int p)
{
  int a = p + 2;
  int b = p + 1;
  int i, j;

  for (i = 0; i < a; i++)
  {
    for (j = 0; j < b; j++)
    {
      free(mat[i][j]);
    }
  }
  for (i = 0; i < a; i++)
  {
    free(mat[i]);
  }

  free(mat);
}