#include "./algoritimos/forca_bruta.h"
#include "./algoritimos/alg_guloso.h"
#include "./algoritimos/prog_dinamica.h"
#include "./biblioteca/escolha_entrada.h"


int main(int numargs, char *args[])
{
  
  int t, i = 0;
  int p, pc, solution, *pesos;

  scanf("%d", &t);

  int algorithm = escolha_metodo(numargs, args);
 
  do
  {
    scanf("%d %d", &p, &pc);

    pesos = (int *)calloc(p + 1, sizeof(int));

    insere_peso(p, pesos);

    switch (algorithm)
    {
    case 1:
      solution = forca_bruta(p, pc, pesos);
      printf("%d\n", solution);
      break;

    case 2:
      solution = guloso(p, pc, pesos);
      printf("%d\n", solution);
      break;

    case 3:
      solution = dinamico(p + 1, p, pc, pesos);
      printf("%d\n", solution);

      break;
    default:
      printf("default/n");
    }

    i = i + 1;
    free(pesos);

  } while (i < t);

  return 0;
}