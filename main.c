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

    for(i=0; i < 4; i++)
        remove_Pilha(pi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);

    for(i=0; i < 4; i++)
        insere_Pilha(pi,a[i]);

    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);

    printf("Removendo 2 elementos\n\n");
    pop2_pilha(pi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);

    printf("Adicionando 2 elementos\n\n");
    push2_pilha(pi,a[2],a[3]);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);

    printf("Removendo N elementos\n\n");
    popN(pi, 3);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);

    printf("\n\nCriando uma copia da pilha:\n\n");
    Pilha* copia = pilha_copia(pi);
    printf("Pilha original:\n");
    imprime_Pilha(pi);
    printf("\n\nPilha copiada:\n");
    imprime_Pilha(copia);

    libera_Pilha(copia);


    
    libera_Pilha(pi);
    system("pause");
    return 0;
}

