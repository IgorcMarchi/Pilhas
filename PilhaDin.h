#ifndef PILHADIN_H_INCLUDED
#define PILHADIN_H_INCLUDED
//Arquivo PilhaDin.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};


typedef struct elemento* Pilha;

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int consulta_topo_Pilha(Pilha* pi, struct aluno *al);
int insere_Pilha(Pilha* pi, struct aluno al);
int remove_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int Pilha_cheia(Pilha* pi);
void imprime_Pilha(Pilha* pi);


int push2_pilha(Pilha* pi, struct aluno al,  struct aluno a2);
int pop2_pilha(Pilha* pi);
int popN(Pilha* pi, int n);
int NotasMedias(Pilha *pi);
int ambasIguais(Pilha *pi1, Pilha *pi2);
Pilha* pilha_copia(Pilha* pi);
int Verificapalindromo(Pilha *pi);
int reverso(Pilha *pi);
int verifica_metade_inverso(Pilha *pi);
int QuantImp(Pilha *pi);
int QuantPar(Pilha *pi);
void menu();
void converte_binario(int num);
#endif
