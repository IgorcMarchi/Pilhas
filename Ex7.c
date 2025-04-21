#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
#include "PilhaDin.c"

int main() {
    struct aluno a[5] = {{2,"Andre",9.5,7.8,8.5}, // 8.6 
                        {4,"Ricardo",7.5,8.7,6.8}, // 7.66
                        {1,"Bianca",9.7,6.7,8.4}, // 8.26
                        {3,"Ana",5.7,6.1,7.4}, // 6.40 MENOR
                        {5,"Igor",7.3,9.7,10}}; // 9.0 Maior
                        // MEdDIA TOTAL: 8.36
    Pilha* pi = cria_Pilha();
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    int i;
    for(i=0; i < 5; i++)
        insere_Pilha(pi,a[i]);

    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);
    printf("\n\nTamanho quantidade de numeros de matriculas pares: %d", QuantPar(pi));
    printf("\n\nTamanho quantidade de numeros de matriculas Impar: %d\n", QuantImp(pi));
    
    libera_Pilha(pi);
    system("pause");
    return 0;
}

// Nessa questão uso duas funções para contar a quantidade de números pares e ímpares na pilha,
// Ele verifica o numero da matricula e conta quantos são pares e quantos são ímpares,
// retornando o valor total de cada um deles.