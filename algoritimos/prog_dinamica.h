#ifndef DYNAMIC_H
#define DYNAMIC_H

#include "../biblioteca/planeta.h"
#include "../biblioteca/matriz.h"

int dinamico(int atual, int p, int pc, int *path);
/*
  Entrada: atual --> o planeta atual, iniciado por p+1
           p --> numero de planetas possíveis
           pc --> número de planetas a serem conquistados
           path --> peso das viagens entre os planetas
  
  Saida: valor do maio caminho para conquistar pc planetas de forma ótima
  */

int recorrencia(int atual, int p, int pc, int *path);
/*
  Entrada: atual --> o planeta atual, iniciado por p+1
           p --> numero de planetas possíveis
           pc --> número de planetas a serem conquistados
           path --> peso das viagens entre os planetas
  
  Saida: valor do maio caminho para conquistar pc planetas de forma ótima
  */

#endif  