#ifndef LNSE_H
#define LNSE_H

#define CAPACIDADE 10 // Capacidade máxima da lista

typedef struct {
    int elementos[CAPACIDADE]; // Vetor que armazena os elementos da LNSE
    int prox[CAPACIDADE];      // Vetor para indicar o próximo índice
    int fila[CAPACIDADE];      // Fila de índices livres
    int head, tail;            // Índices do primeiro e último elementos
    int tamanho;               // Tamanho atual da lista
    int fila_inicio, fila_fim; // Controle da fila de índices
} LNSE;

void inicializar(LNSE *lista);
void inserir(LNSE *lista, int x);
int remover(LNSE *lista, int i);
int buscar(LNSE *lista, int x);
int size(LNSE *lista);
void clear(LNSE *lista);
void imprimir(LNSE *lista);

#endif
