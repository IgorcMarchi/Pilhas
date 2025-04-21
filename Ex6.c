#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
#include "PilhaDin.c"

int main() {
    struct aluno a[1] = {{2,"Ana",9.5,7.8,8.5}};
    Pilha* pi = cria_Pilha();
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    int i;
    for(i=0; i < 1; i++)
        insere_Pilha(pi,a[i]);

    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);
    printf("\nInverso:\n");
    reverso(pi);

    if (Verificapalindromo(pi)) {
        printf("\n-> Frase palindroma!\n");
    } else {
        printf("\n-> Frase nao palindroma!\n");
    }

    // A função palindromo verifica se o nome do aluno é palíndroma, ou seja, se a sequência de caracteres lida de trás para frente é igual à lida de frente para trás.
    // Além disso ele também inverte o nome do aluno, imprimindo o nome na ordem inversa.
    
    libera_Pilha(pi);
    system("pause");
    return 0;
}
