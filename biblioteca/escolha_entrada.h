#ifndef INPUT_FUNCTION
#define INPUT_FUNCTION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insere_peso(int p, int *pesos);
/*
  Entrada: p --> número de planetas
           pesos --> lista com os pesos das viagens.

  Saida: essa função irá inserir os pesos de entrada do usuário
  dentro do array pesos.
  */
 
int escolha_metodo(int numargs, char *args[]);
 /*
  Entrada: numargs --> número de argumetos
           args --> argumentos de entrada.

  Saida: inteiro que representa o argumento de entrada.
        se FB então retorna 1
        se AG então retorna 2
        se PD então retorna 3
  */

#endif