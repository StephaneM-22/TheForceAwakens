#include "escolha_entrada.h"

void insere_peso(int p, int *pesos)
{
  /*
  Entrada: p --> número de planetas
           pesos --> lista com os pesos das viagens.

  Saida: essa função irá inserir os pesos de entrada do usuário
  dentro do array pesos.
  */

  int j;

  for (j = 0; j <= p; j++)
  {
    scanf("%d", &pesos[j]);
  }
}

int escolha_metodo(int numargs, char *args[])
{
  /*
  Entrada: numargs --> número de argumetos
           args --> argumentos de entrada.

  Saida: inteiro que representa o argumento de entrada.
        se FB então retorna 1
        se AG então retorna 2
        se PD então retorna 3
  */

  int j;

  for (j = 1; j < numargs; j++)
  {
    if (strcmp(args[j], "FB") == 0)
    {
      return 1;
    }

    else if (strcmp(args[j], "AG") == 0)
    {
      return 2;
    }

    else if (strcmp(args[j], "PD") == 0)
    {
      return 3;
    }
  }

  return 0;
}