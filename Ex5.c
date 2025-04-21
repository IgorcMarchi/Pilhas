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
                        
    struct aluno b[4] = {{2,"Andre",9.5,7.8,8.5}, // 8.6 MAIOR
                        {4,"Ricardo",7.5,8.7,6.8}, // 7.66
                        {1,"Bianca",9.7,6.7,8.4}, // 8.26
                        {3,"Ana",5.7,6.1,7.4}}; // 6.40 MENOR
                        // MEdDIA TOTAL: 7.73
    Pilha* pi1 = cria_Pilha();
    int i, j;
    for(i=0; i < 4; i++)
        insere_Pilha(pi1,a[i]);

    printf("Imprimindo pilha 1:\n\n");
    imprime_Pilha(pi1);

    Pilha* pi2 = cria_Pilha();
    for(j=0; j < 4; j++)
        insere_Pilha(pi2,b[j]);

    printf("Imprimindo pilha 2:\n\n");
    imprime_Pilha(pi2);

        if (ambasIguais(pi1, pi2) == 1) {
            printf("\n\n As Pilhas tem os mesmo dados\n");
        } else {
            printf("\n\nAs Pilhas tem dados diferentes\n");
        }
    
    libera_Pilha(pi1);
    libera_Pilha(pi2);
    system("pause");
    return 0;
}

// // Nessa questão eu criei uma função que compara duas pilhas, verificando se os dados são iguais ou não,
// // retornando 1 se forem iguais e 0 se não forem iguais.
