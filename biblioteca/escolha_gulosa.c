#include "escolha_gulosa.h"

void escolhe_planeta(int *p, int *peso_planeta, int *planetas_escolhidos){

    int max = -1, indice = -1;

    for(int i = 0; i<*p; i++)
    {
        if(peso_planeta[i] > max && planetas_escolhidos[i] != 1){
            max = peso_planeta[i];
            indice = i;
        }

    }

    planetas_escolhidos[indice] = 1;

    return;
}
