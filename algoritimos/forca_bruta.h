#ifndef FORCABRUTA_H
#define FORCABRUTA_H

#include "../biblioteca/combinacao.h"
#include "../biblioteca/planeta.h"

int forca_bruta(int p, int pc, int* peso);
/*
  Entrada: p --> numero de planetas possíveis
           pc --> número de planetas a serem conquistados
           peso --> peso das viagens entre os planetas
  
  Saida: valor do maior caminho para conquistar pc planetas de forma ótima
  */

#endif  