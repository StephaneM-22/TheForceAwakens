#include "alg_guloso.h"

int guloso(int p, int pc, int* peso)
{

    int i, max = 0, soma1 = 0;
    int *peso_planeta, *planetas_escolhidos;

    peso_planeta = (int *) calloc(p, sizeof(int));
    planetas_escolhidos = (int *) calloc(p+1, sizeof(int));
    planetas_escolhidos[p] = 1;

    for(i = 0; i < p; i++){
        peso_planeta[i] = peso[i] + peso[i+1];
        planetas_escolhidos[i] = 0;
    }

    // Escolha gulosa
    for(i = 0; i < pc; i++){
        escolhe_planeta(&p, peso_planeta, planetas_escolhidos);
    }

    for(i = 0; i <= p; i++)
    {
        if(planetas_escolhidos[i]){
            soma1 = soma1 + peso[i];

            if(soma1 > max){
                max = soma1;
            }

            soma1 = 0;
        }
        else{
            soma1 = soma1 + peso[i];
        }
        
    }

    free(peso_planeta);
    free(planetas_escolhidos);

    return max;

}