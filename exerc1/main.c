#include <stdio.h>
#include "fila_estaticaCircular.h"
#include "pilhaDinamica.h"
#include "pilhaDinamica.c"

int verificaBalanceamento(Fila* fila) {
    if (fila == NULL) {
        return 0;  // Retorna n�o balanceado se fila � inv�lida
    }

    Pilha* pilha = criarPilha();
    if (pilha == NULL) {
        return 0;  // Retorna n�o balanceado se falhar em criar pilha
    }

    // Cria uma fila auxiliar para preservar a fila original
    Fila* filaAux = criarFila(fila->capacity);
    if (filaAux == NULL) {
        free(pilha);
        return 0;
    }

    int balanceada = 1;  // Assume que est� balanceada at� provar o contr�rio

    while (!isEmpty(fila)) {
        char elemento = dequeue(fila);
        enqueue(filaAux, elemento);  // Preserva o elemento

        if (elemento == '(' || elemento == '[' || elemento == '{') {
            push(pilha, elemento);
        } else if (elemento == ')' || elemento == ']' || elemento == '}') {
            if (isEmpty(pilha)) {
                balanceada = 0;
                break;
            }

            char topo = pop(pilha);
            if ((elemento == ')' && topo != '(') ||
                (elemento == ']' && topo != '[') ||
                (elemento == '}' && topo != '{')) {
                balanceada = 0;
                break;
            }
        }
    }

    // Verifica se sobrou algum par�ntese aberto
    if (!isEmpty(pilha)) {
        balanceada = 0;
    }

    // Restaura a fila original
    while (!isEmpty(filaAux)) {
        enqueue(fila, dequeue(filaAux));
    }

    clear(pilha);
    free(pilha);
    clear(filaAux);
    free(filaAux);

    return balanceada;
}

int main() {
    // Exemplo de uso direto
    Fila* fila = criarFila(6);  // Tamanho definido diretamente (alterar aqui)
    if (fila == NULL) {
        printf("Erro ao criar a fila.\n");
        return 1;
    }

    // Sequ�ncia de teste: "{[()]}"
    enqueue(fila, '{');
    enqueue(fila, '[');
    enqueue(fila, '(');
    enqueue(fila, ')');
    enqueue(fila, ']');
    enqueue(fila, '}');

    printf("Sequencia %s.\n", verificaBalanceamento(fila) ? "balanceada" : "nao balanceada");

    clear(fila);
    free(fila);
    return 0;
}
