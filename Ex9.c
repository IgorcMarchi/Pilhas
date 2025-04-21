#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
#include "PilhaDin.c"

int main() {
    struct aluno a[4] = {
        {2,"Andre",9.5,7.8,8.5},
        {4,"Ricardo",7.5,8.7,6.8},
        {1,"Bianca",9.7,6.7,8.4},
        {3,"Ana",5.7,6.1,7.4}
    };

    Pilha* pi = NULL;
    int op, num;

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                pi = cria_Pilha();
                if(pi != NULL)
                    printf("Pilha inicializada com sucesso.\n");
                else
                    printf("Erro ao inicializar a pilha.\n");
                system("pause");
                system("cls");
                break;

            case 2:
                if(pi == NULL || Pilha_vazia(pi))
                    printf("A pilha esta vazia.\n");
                else
                    printf("A pilha NAO esta vazia.\n");
                system("pause");
                system("cls");
                break;

            case 3:
                if(Pilha_cheia(pi))
                    printf("A pilha esta cheia.\n");
                else
                    printf("A pilha NAO esta cheia.\n");
                system("pause");
                system("cls");
                break;

            case 4:
                if(pi == NULL) {
                    printf("Inicialize a pilha primeiro.\n");
                } else {
                    for(int i = 0; i < 4; i++)
                        insere_Pilha(pi, a[i]);
                    printf("Elementos inseridos com sucesso.\n");
                }
                system("pause");
                system("cls");
                break;

            case 5:
                if(remove_Pilha(pi))
                    printf("Elemento removido com sucesso.\n");
                else
                    printf("Erro ao remover elemento.\n");
                system("pause");
                system("cls");
                break;

            case 6: {
                struct aluno al;
                if(consulta_topo_Pilha(pi, &al)) {
                    printf("Dados do topo:\n");
                    printf("Matricula: %d\n", al.matricula);
                    printf("Nome: %s\n", al.nome);
                    printf("Notas: %.2f %.2f %.2f\n", al.n1, al.n2, al.n3);
                } else {
                    printf("Erro ao acessar o topo.\n");
                }
                system("pause");
                system("cls");
                break;
            }

            case 7:
                printf("Digite um numero decimal: ");
                scanf("%d", &num);
                converte_binario(num);
                system("pause");
                system("cls");
                break;

            case 8:
                printf("Saindo...\n");
                system("pause");
                system("cls");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                system("pause");
                system("cls");
        }

    } while(op != 8);

    if (pi != NULL) libera_Pilha(pi);
    return 0;
}

// Ele utiliza do void menu para ver as opções e usando o switch para escolher a opção desejada,
// ele usa o system("pause") para pausar o código e o system("cls") para limpar a tela,
// Ele utiliza de funções ja criadas, apenas na opção 7 que ele chama a função converte_binario que não foi criada antes.
