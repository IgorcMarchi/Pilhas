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

    printf("Adicionando 2 elementos\n\n");
    push2_pilha(pi,a[2],a[3]);
    imprime_Pilha(pi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));

    printf("Removendo 2 elementos\n\n");
    pop2_pilha(pi);
    imprime_Pilha(pi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));


    
    libera_Pilha(pi);
    system("pause");
    return 0;
}

// // Nessa questão eu criei uma função que adiciona dois elementos na pilha, e depois remove dois elementos da pilha,
// A função push2_pilha adiciona dois elementos na pilha, e a função pop2_pilha remove dois elementos da pilha,
// Ela usa a mesma lógica da função insere_Pilha e remove_Pilha, mas ao invés de um agora é dois.