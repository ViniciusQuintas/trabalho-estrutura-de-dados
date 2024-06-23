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
