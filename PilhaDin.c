#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PilhaDin.h" //inclui os Prot�tipos

//Defini��o do tipo Pilha
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}
int Pilha_cheia(Pilha* pi) {
    return 0; 
}

int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    *al = (*pi)->dados;
    return 1;
}

int insere_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}


int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;
    return 0;
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

int push2_pilha(Pilha* pi, struct aluno al1,  struct aluno al2){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem)); // vazia
    if(no == NULL) // no existe
        return 0;
    no->dados = al1; // dados vai receber o aluno al1
    no->prox = (*pi);   
    *pi = no;
    Elem* no2 = (Elem*) malloc(sizeof(Elem)); // vazia
    if(no2 == NULL) // no2 existe
        return 0;
    no2->prox = (*pi);
    no2->dados = al2; // dados vai receber o aluno al2
    *pi = no2; // pi vai receber o no2
    
    return 1;
}

int pop2_pilha(Pilha* pi){
    if(pi == NULL) //  Existe uma pilha? Se não sai do código
        return 0;
    if((*pi) == NULL) // A pilha esta vazia? Se sim sai do código
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    if(Pilha_vazia(pi)) // A pilha ficou vazia depois da primeira remoção?
        return 0;
    no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int popN(Pilha* pi, int n){
    if(n > tamanho_Pilha(pi)) // Se o número de elementos a serem removidos for maior que o tamanho da pilha, sai do código
        return 0;
    for(int i = 0; i < n; i++){
        if(pi == NULL) //  Existe uma pilha? Se não sai do código
            return 0;
        if((*pi) == NULL) // A pilha esta vazia? Se sim sai do código
            return 0;
        Elem *no = *pi;
        *pi = no->prox;
        free(no);
    }
    return 1;
}

Pilha* pilha_copia(Pilha* pi){
    if(pi == NULL) return NULL;

    Pilha* copia = cria_Pilha(); // cria pilha copia
    Pilha* aux = cria_Pilha(); // Cria A pilha que vai auxiliar na troca

    struct aluno temp;

    // Etapa 1: desempilha pi e empilha em aux (inverte)
    while (!Pilha_vazia(pi)) {
        consulta_topo_Pilha(pi, &temp);
        remove_Pilha(pi);
        insere_Pilha(aux, temp);
    }

    // Etapa 2: desempilha aux e empilha de volta em pi e também em copia
    while (!Pilha_vazia(aux)) {
        consulta_topo_Pilha(aux, &temp);
        remove_Pilha(aux);
        insere_Pilha(pi, temp);     // restaurando pi
        insere_Pilha(copia, temp);  // copiando
    }

    libera_Pilha(aux);
    return copia;
}

int NotasMedias(Pilha *pi) {
    if (pi == NULL || *pi == NULL) return 0;

    Elem* no = *pi;
    float mediaAtual = (no->dados.n1 + no->dados.n2 + no->dados.n3) / 3.0;
    float menor = mediaAtual;
    float maior = mediaAtual;
    float soma = mediaAtual;
    int count = 1;

    no = no->prox;

    while (no != NULL) {
        mediaAtual = (no->dados.n1 + no->dados.n2 + no->dados.n3) / 3.0;
        if (mediaAtual < menor) menor = mediaAtual;
        if (mediaAtual > maior) maior = mediaAtual;
        soma += mediaAtual;
        count++;
        no = no->prox;
    }

    float media = soma / count;
    printf("-> Menor media: %.2f\n", menor);
    printf("-> Maior media: %.2f\n", maior);
    printf("-> Media das medias: %.2f\n", media);

    return 1;
}

int ambasIguais(Pilha *pi1, Pilha *pi2) {
    if (pi1 == NULL || pi2 == NULL) return 0;

    Pilha* copia1 = pilha_copia(pi1);
    Pilha* copia2 = pilha_copia(pi2);

    if (tamanho_Pilha(copia1) != tamanho_Pilha(copia2)) {
        libera_Pilha(copia1);
        libera_Pilha(copia2);
        return 0;
    }

    struct aluno a1, a2;
    int iguais = 1;

    while (!Pilha_vazia(copia1) && !Pilha_vazia(copia2)) {
        consulta_topo_Pilha(copia1, &a1);
        consulta_topo_Pilha(copia2, &a2);

        if (a1.matricula != a2.matricula ||
            strcmp(a1.nome, a2.nome) != 0 ||
            a1.n1 != a2.n1 || a1.n2 != a2.n2 || a1.n3 != a2.n3) {
            iguais = 0;
            break;
        }

        remove_Pilha(copia1);
        remove_Pilha(copia2);
    }

    libera_Pilha(copia1);
    libera_Pilha(copia2);
    return iguais;
}
int Verificapalindromo(Pilha *pi) {
    if (Pilha_vazia(pi)) return 0;

    int Tamanho = 0;
    Elem *no = *pi;
    while (no != NULL) {
        for (int i = 0; no->dados.nome[i] != '\0'; i++) {
            if (no->dados.nome[i] != ' ' && no->dados.nome[i] != '.') {
                Tamanho++;
            }
        }
        no = no->prox;
    }
    char *caracteres = (char *)malloc(Tamanho * sizeof(char));
    if (caracteres == NULL) return 0;

    no = *pi;
    int pos = 0;
    while (no != NULL) {
        for (int i = 0; no->dados.nome[i] != '\0'; i++) {
            char c = no->dados.nome[i];
            if (c != ' ' && c != '.') {
                caracteres[pos++] = tolower(c);
            }
        }
        no = no->prox;
    }
    for (int i = 0; i < Tamanho / 2; i++) {
        if (caracteres[i] != caracteres[Tamanho - 1 - i]) {
            free(caracteres);
            return 0;
        }
    }
    free(caracteres);
    return 1;
}

int reverso(Pilha *pi) {
    if (pi == NULL || *pi == NULL) return 0;

    Elem *no = *pi;

    while (no != NULL) {
        int len = strlen(no->dados.nome);
        for (int i = len - 1; i >= 0; i--) {
            printf("%c", no->dados.nome[i]);
        }
        printf("\n");
        no = no->prox;
    }

    return 1;
}



int QuantImp(Pilha *pi) {
    Elem* no = *pi;
    if (Pilha_vazia(pi)) return 0;
    int impar = 0;

    while (no != NULL) {
        if (no->dados.matricula % 2 != 0) impar++;
        no = no->prox;
    }
    return impar;
}

int QuantPar(Pilha *pi) {
    Elem* no = *pi;
    if (Pilha_vazia(pi)) return 0;
    int par = 0;

    while (no != NULL) {
        if (no->dados.matricula % 2 == 0) par++;
        no = no->prox;
    }
    return par;
}

void menu()
{
    printf("1-Inicializa pilha.\n");
    printf("2-Verifica se a pilha e vazia.\n");
    printf("3-Verifica se a pilha e cheia.\n");
    printf("4-Empilha o elemento na pilha.\n");
    printf("5-Desempilha elemento da pilha.\n");
    printf("6-Le topo de um pilha.\n");
    printf("7-Converte um numero decimal em binario.\n");
    printf("8-Sair.\n");
}


void converte_binario(int num) {
    Pilha* bin = cria_Pilha();
    struct aluno temp;
    while (num > 0) {
        temp.matricula = num % 2;
        temp.n1 = temp.n2 = temp.n3 = 0;
        strcpy(temp.nome, "");
        insere_Pilha(bin, temp);
        num /= 2;
    }
    printf("Binário: ");
    while (!Pilha_vazia(bin)) {
        consulta_topo_Pilha(bin, &temp);
        printf("%d", temp.matricula);
        remove_Pilha(bin);
    }
    printf("\n");
    libera_Pilha(bin);
}