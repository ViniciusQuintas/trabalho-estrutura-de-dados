#include <stdio.h>
#include <stdlib.h>
#include "fila_decolagem.h"

int main() {
    FilaDecolagem fila;
    inicializarFila(&fila);
    int opcao;
    char nome[50];
    int id;

    do {
        printf("\n====== Gerenciamento de decolagem ======\n");
        printf("1. Listar numero de avioes aguardando\n");
        printf("2. Autorizar decolagem do primeiro aviao\n");
        printf("3. Adicionar aviao a fila de espera\n");
        printf("4. Listar todos os avioes na fila de espera\n");
        printf("5. Listar caracteristicas do primeiro aviao\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: \n");
        printf("=================================================\n-> ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nNumero de avioes aguardando na fila: %d\n", tamanhoFila(&fila));
                break;
            case 2:
                autorizarDecolagem(&fila);
                break;
            case 3:
                printf("Digite o nome do aviao: \n->");
                scanf("%s", nome);
                printf("Digite o ID do aviao: \n->");
                scanf("%d", &id);
                adicionarAviao(&fila, nome, id);
                break;
            case 4:
                listarAvioes(&fila);
                break;
            case 5:
                caracteristicasPrimeiroAviao(&fila);
                break;
            case 0:
                printf("Encerrando programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
