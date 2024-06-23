#include <stdio.h>
#include "fila_decolagem.h"

void inicializarFila(FilaDecolagem *fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->total = 0;
}

int tamanhoFila(FilaDecolagem *fila) {
    return fila->total;
}

void autorizarDecolagem(FilaDecolagem *fila) {
    if (fila->total > 0) {
        printf("\n");
        printf("=====================================================\n");
        printf("                       __|__\n    -----o-----o-------(___)-------o--------o-----\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("   Decolagem autorizada para o aviao %s (ID: %d).    \n", fila->avioes[fila->inicio].nome, fila->avioes[fila->inicio].id);
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("======================================================\n");
        
        fila->inicio++;
        fila->total--;
        
    } else {
        printf("======================================================\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|Pista Vazia - Nenhum Aviao aguardando para decolagem|\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("======================================================\n");
        
    }
}

void adicionarAviao(FilaDecolagem *fila, char *nome, int id) {
    if (fila->total < MAX_AVIOES) {
        fila->fim++;
        if (fila->fim >= MAX_AVIOES) {
            fila->fim = 0;
        }
        strcpy(fila->avioes[fila->fim].nome, nome);
        fila->avioes[fila->fim].id = id;
        fila->total++;
        
        
        printf("======================================================\n");
        printf("Aviao %s (ID: %d) adicionado na fila de espera.\n", nome, id);
        printf("|                        |                           |\n");
        printf("|                        V                           |\n");
        printf("                       __|__\n    -----o-----o-------(___)-------o--------o-----\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
    } else {
        printf("======================================================\n");
        printf("                             __|__\n          -----o-----o-------(___)-------o--------o-----\n");
        printf("|                             | |                                |\n");
        printf("                             __|__\n          -----o-----o-------(___)-------o--------o-----\n");
        printf("Fila de espera de decolagem cheia - Nao foi possivel adicionar o aviao %s (ID: %d).\n", nome, id);
        printf("                             __|__\n          -----o-----o-------(___)-------o--------o-----\n");
        printf("|                             | |                                |\n");
        printf("                             __|__\n          -----o-----o-------(___)-------o--------o-----\n");
        printf("|                             | |                                |\n");
        printf("======================================================\n");
    }
}

void listarAvioes(FilaDecolagem *fila) {
    printf("=====================================================\n");
    printf("Avioes aguardando na fila de espera:\n");
    if (fila->total > 0) {
        int i;
        for (i = fila->inicio; i <= fila->fim; i++) {
            printf("                        __|__\n    -----o-----o-------(ID:%d)-------o--------o-----\n", fila->avioes[i].id);
            printf("|                        | |                           |\n");
            /*printf("- Aviao %s (ID: %d)\n", fila->avioes[i].nome, fila->avioes[i].id);*/
        }
    } else {
        printf("======================================================\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|     Nenhum aviao aguardando na fila de espera.     |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("======================================================\n");
    }
}

void caracteristicasPrimeiroAviao(FilaDecolagem *fila) {
    if (fila->total > 0) {
        printf("Caracteristicas do primeiro aviao da fila:\n");
        printf("- Nome: %s\n", fila->avioes[fila->inicio].nome);
        printf("- ID: %d\n", fila->avioes[fila->inicio].id);
    } else {
        printf("=====================================================\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|     Nenhum aviao aguardando na fila de espera.     |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("|                       | |                          |\n");
        printf("======================================================\n");
    }
}
