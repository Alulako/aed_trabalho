#include <stdio.h>
#include "lnse.h"

// Função para inicializar a LNSE
void inicializar(LNSE *lista) {
    lista->tamanho = 0;
    lista->head = -1;
    lista->tail = -1;
    lista->fila_inicio = 0;
    lista->fila_fim = 0;

    // Inicializa a fila de índices livres
    for (int i = 0; i < CAPACIDADE; i++) {
        lista->fila[i] = i;
        lista->elementos[i] = -1; // Marca a posição como vazia
        lista->prox[i] = -1;      // Define o próximo como vazio
    }
}

// Enfileirar um índice livre
void enqueue(LNSE *lista, int indice) {
    lista->fila[lista->fila_fim] = indice;
    lista->fila_fim = (lista->fila_fim + 1) % CAPACIDADE;
}

// Desenfileirar um índice livre
int dequeue(LNSE *lista) {
    int indice = lista->fila[lista->fila_inicio];
    lista->fila_inicio = (lista->fila_inicio + 1) % CAPACIDADE;
    return indice;
}

// Função para inserir um elemento na LNSE
void inserir(LNSE *lista, int x) {
    if (lista->tamanho == CAPACIDADE) {
        printf("Lista cheia!\n");
        return;
    }

    int posicao = dequeue(lista);
    lista->elementos[posicao] = x;

    if (lista->head == -1) {
        lista->head = posicao;
    } else {
        lista->prox[lista->tail] = posicao;
    }
    lista->tail = posicao;
    lista->prox[posicao] = -1;
    lista->tamanho++;
}

// Função para remover um elemento na posição i
int remover(LNSE *lista, int i) {
    if (lista->elementos[i] == -1) {
        printf("Posição vazia!\n");
        return -1;
    }

    int valor = lista->elementos[i];
    lista->elementos[i] = -1;

    if (i == lista->head) {
        lista->head = lista->prox[i];
    } else {
        for (int j = lista->head; j != -1; j = lista->prox[j]) {
            if (lista->prox[j] == i) {
                lista->prox[j] = lista->prox[i];
                break;
            }
        }
    }

    if (i == lista->tail) {
        lista->tail = -1;
    }

    enqueue(lista, i);
    lista->tamanho--;
    return valor;
}

// Função para buscar um elemento x na lista
int buscar(LNSE *lista, int x) {
    for (int i = lista->head; i != -1; i = lista->prox[i]) {
        if (lista->elementos[i] == x) {
            return i;
        }
    }
    return -1;
}

// Função para obter o tamanho da lista
int size(LNSE *lista) {
    return lista->tamanho;
}

// Função para limpar a lista
void clear(LNSE *lista) {
    inicializar(lista);
}

// Função para imprimir a lista
void imprimir(LNSE *lista) {
    printf("LNSE: ");
    for (int i = 0; i < CAPACIDADE; i++) {
        if (lista->elementos[i] == -1) {
            printf(" - ");
        } else {
            printf("%d ", lista->elementos[i]);
        }
    }
    printf("\nHead: %d\n", lista->head);
    printf("Tail: %d\n", lista->tail);
}

