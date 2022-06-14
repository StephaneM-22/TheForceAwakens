#include "forca_bruta.h"

int forca_bruta(int p, int pc, int *peso)
{
  /*
  Entrada: p --> numero de planetas possíveis
           pc --> número de planetas a serem conquistados
           peso --> peso das viagens entre os planetas
  
  Saida: valor do maior caminho para conquistar pc planetas de forma ótima

  Para o força bruta utilizamos a ideia de combinações tomados pc planetas,
  para identificar esses combinações utilizamos sequêcias de números binarios
  que contiam pc quantidades de 1s. Ou seja, supondo que gostariamos de conquistar
  2 planetas dentre 3 possíveis, as possibilidades seriam: [011, 101, 110]. Após isso,
  avaliamos maior custo de cada uma dessas viagens e encontramos aquele que seja ótima.
  */

  int planets[p];

  for (int i = 0; i < p; i++)
  {
    planets[i] = i;
  }

  int max_combination = pow(2, p) - 1;
  int size_combination;

  int *combination;
  int start;
  int end;
  int value;

  int min_global = (int)INFINITY;
  int max_local;

  for (int i = 0; i <= max_combination; i++)
  {
    start = 0;
    end = 0;
    max_local = -1;

    size_combination = n_bits_1(max_combination, i);

    if (size_combination == pc)
    {
      combination = combinacao(i, planets);

      for (int z = 0; z < pc; z++)
      {
        end = combination[z];
        value = custo(start, end + 1, peso);

        if (value > max_local)
        {
          max_local = value;
        }

        start = combination[z] + 1;
      }

      end = p;
      value = custo(start, end + 1, peso);

      if (value > max_local)
      {
        max_local = value;
      }

      if (max_local < min_global)
      {
        min_global = max_local;
      }
      free(combination);
    }
  }

  return min_global;
}
