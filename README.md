# Sistema de Decolagem de Aviões

Este projeto implementa um sistema de controle de pista de decolagem de aviões em um aeroporto. O usuário pode listar aviões na fila de espera, autorizar decolagens, adicionar aviões à fila e obter características dos aviões.

## Funcionalidades

1. **Listar o número de aviões aguardando na fila de decolagem**
2. **Autorizar a decolagem do primeiro avião da fila**
3. **Adicionar um avião à fila de espera**
4. **Listar todos os aviões na fila de espera**
5. **Listar as características do primeiro avião da fila**

## Estrutura do Projeto

O projeto está organizado em três arquivos:

1. `fila_decolagem.c`: Implementação das funções relacionadas à fila de decolagem.
2. `fila_decolagem.h`: Declarações de funções e definições de estruturas.
3. `main.c`: Função principal para interagir com o usuário.

## Estruturas e Definições

### Estrutura Aviao

```c
typedef struct {
    char nome[50];
    int id;
} Aviao;
```

### Estrutura FilaDecolagem
```c
typedef struct {
    Aviao avioes[MAX_AVIOES];
    int inicio;
    int fim;
    int total;
} FilaDecolagem;
```

## Funções

### Inicializar Fila
Inicializa a fila de decolagem, configurando os índices e o total de aviões para zero.
```c
void inicializarFila(FilaDecolagem *fila);
```

### Tamanho da Fila
Retorna o número de aviões aguardando na fila de decolagem.
```c
int tamanhoFila(FilaDecolagem *fila);
```

### Autorizar Decolagem
Autoriza a decolagem do primeiro avião da fila e o remove da fila.
```c
void autorizarDecolagem(FilaDecolagem *fila);
```

### Adicionar Avião
Adiciona um avião à fila de espera de decolagem.
```c
void adicionarAviao(FilaDecolagem *fila, char *nome, int id);
```

### Listar Aviões
Lista todos os aviões na fila de espera.
```c
void listarAvioes(FilaDecolagem *fila);
```

### Características do Primeiro Aviãos
Lista as características do primeiro avião na fila.
```c
void caracteristicasPrimeiroAviao(FilaDecolagem *fila);
```

# Código Fonte
### `fila_decolagem.c`
```c
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
```

### `fila_decolagem.h`
```c
#ifndef FILA_DECOLAGEM_H
#define FILA_DECOLAGEM_H

#define MAX_AVIOES 2  // Tamanho máximo da fila de espera

typedef struct {
    char nome[50];
    int id;
} Aviao;

typedef struct {
    Aviao avioes[MAX_AVIOES];
    int inicio;
    int fim;
    int total;
} FilaDecolagem;

void inicializarFila(FilaDecolagem *fila);
int tamanhoFila(FilaDecolagem *fila);
void autorizarDecolagem(FilaDecolagem *fila);
void adicionarAviao(FilaDecolagem *fila, char *nome, int id);
void listarAvioes(FilaDecolagem *fila);
void caracteristicasPrimeiroAviao(FilaDecolagem *fila);

#endif /* FILA_DECOLAGEM_H */
```

### `main.c`
```c
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
```

# Conclusão
Este sistema simples de controle de decolagem de aviões demonstra o uso de filas em C para gerenciar uma sequência de aviões aguardando para decolar. Ele permite adicionar aviões, autorizar decolagens e visualizar o status da fila.

# Contribuidores
- [Arthur Mendes](https://github.com/Arthur0020)
- [Vinícius Quintas](https://github.com/ViniciusQuintas)
