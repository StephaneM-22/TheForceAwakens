#include "prog_dinamica.h"

int dinamico(int atual, int p, int pc, int *peso)
{
  /*
  Entrada: atual --> o planeta atual, iniciado por p+1
           p --> numero de planetas possíveis
           pc --> número de planetas a serem conquistados
           peso --> peso das viagens entre os planetas
  
  Saida: valor do maio caminho para conquistar pc planetas de forma ótima

  Basendo na recorrência (função recorrencia logo em baixo desse
  script) utilizou-se a técnica da programação dinamica para resolver o ploblema. 
  de forma que i representou a variação de p, j a variação de pc e l a variação do
  atual.
  */

  int ***mat = criar(p, pc); //[atual + 1][p + 1][pc + 1];
  int i, j, l;

  for (i = 0; i <= atual; i++)
  {
    for (j = 0; j <= pc; j++)
    {
      mat[i][0][j] = 0;
    }
  }

  for (i = 0; i <= atual; i++)
  {
    for (j = 0; j <= p; j++)
    {
      mat[i][j][0] = custo(0, i, peso);
    }
  }

  for (i = 1; i <= p; i++)
  {
    for (j = 1; j <= pc; j++)
    {
      for (l = 1; l <= atual; l++)
      {

        if (i <= j)
        {
          mat[l][i][j] = max(
              mat[i][i - 1][j - 1],
              custo(i, l, peso));
        }

        else
        {
          mat[l][i][j] = min(
              max(
                  mat[i][i - 1][j - 1],
                  custo(i, l, peso)),

              max(
                  mat[l][i - 1][j],
                  custo(i - 1, l, peso)));
        }
      }
    }
  }

  int answer = mat[atual][p][pc];
  free_matrix(mat,p); 

  return answer;
}

int recorrencia(int atual, int p, int pc, int *peso)
{
  /*
  Entrada: atual --> o planeta atual, iniciado por p+1
           p --> numero de planetas possíveis
           pc --> número de planetas a serem conquistados
           peso --> peso das viagens entre os planetas
  
  Saida: valor do maio caminho para conquistar pc planetas de forma ótima

  Para o programação dinâmica criamos essa recorrência que segue a seguinte 
  lógica:
    se pc = 0, já foi conquistado todos os planetas possíveis;
    se p = 0, não tem planeta para ser conquistado
    se p <=pc, eu preciso conquistar o próximos planetas
    caso o contrátio, avalio se é melhor conquistar o planeta ou pular ele.
  */

  if (pc == 0)
  {
    return custo(0, atual, peso);
  }

  else if (p == 0)
  {
    return 0;
  }

  else if (p <= pc)
  {
    return max(
        custo(p, atual, peso),
        recorrencia(p, p - 1, pc - 1, peso));
  }

  int maxL =
      max(
          custo(p, atual, peso),
          recorrencia(p, p - 1, pc - 1, peso));

  int maxL1 =
      max(
          custo(p - 1, atual, peso),
          recorrencia(atual, p - 1, pc, peso));

  return min(
      maxL,
      maxL1);
}