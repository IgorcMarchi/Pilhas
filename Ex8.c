#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
#include "PilhaDin.c"

int main() {
    struct aluno a[1] = {{2,"1110010",9.5,7.8,8.5}};
    Pilha* pi = cria_Pilha();
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    int i;
    for(i=0; i < 1; i++)
        insere_Pilha(pi,a[i]);

    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);
    if(verifica_metade_inverso(pi) == 1){
        printf("\n-> Os numeros sao totalmente diferentes!\n");
    } else {    
        printf("\n-> Os numeros nao sao todos diferentes!\n");
    }
    return 0;
}
// A ideia é pegar a metade do nome se for impar ele soma mais 1 e se for par só começa da outra metade(no2)
// Ele vai comparar a primeira metade(no) com a segunda metade(no2) e se for igual ele retorna 0, se não for igual ele retorna 1
// A função verifica_metade_inverso compara a primeira metade do nome do aluno com a segunda metade, verificando se são iguais ou não.