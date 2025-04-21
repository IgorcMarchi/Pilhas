#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
#include "PilhaDin.c"

int main(){
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Pilha* pi = cria_Pilha();
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    int i;
    for(i=0; i < 4; i++)
        insere_Pilha(pi,a[i]);

    imprime_Pilha(pi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));


    printf("Removendo N elementos\n\n");
    popN(pi, 3);
    imprime_Pilha(pi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));


    
    libera_Pilha(pi);
    system("pause");
    return 0;
}
// Nessa questão eu criei uma função que remove N elementos da pilha, é usado a praticamente a mesma função que remove um elemento, mas com um loop que remove N elementos,
// É verificado se o número de elementos a serem removidos é maior que o tamanho da pilha, se for sai do código, se não remove os elementos e imprime a pilha depois da remoção.
// A função popN percorre a pilha e remove os elementos um por um, até que o número de elementos removidos atinja o valor N.

