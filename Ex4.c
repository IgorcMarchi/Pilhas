#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
#include "PilhaDin.c"

int main() {
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5}, // 8.6 MAIOR
                        {4,"Ricardo",7.5,8.7,6.8}, // 7.66
                        {1,"Bianca",9.7,6.7,8.4}, // 8.26
                        {3,"Ana",5.7,6.1,7.4}}; // 6.40 MENOR
                        // MEdDIA TOTAL: 7.73
    Pilha* pi = cria_Pilha();
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    int i;
    for(i=0; i < 4; i++)
        insere_Pilha(pi,a[i]);

    imprime_Pilha(pi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));

    printf("Maior Media e Menor Media e Media Total: \n\n");
    NotasMedias(pi);
    
    libera_Pilha(pi);
    system("pause");
    return 0;
}
// Nessa questão eu criei uma função que calcula a maior e menor média da pilha das notas dos alunos,
// e também a média total de todas as notas dos alunos, retornando os valores para o usuário.
// A função percorre a pilha, calcula as médias e imprime os resultados.