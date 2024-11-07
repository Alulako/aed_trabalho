#include <stdio.h>
#include "lnse.h"
#include "lnse.c"

int main() {
    LNSE lista;
    printf("inicializando a lista\n");
    inicializar(&lista);
printf("inserindo elemento 10 na lista\n");
    inserir(&lista, 10);
printf("inserindo elemento 20 na lista\n");
    inserir(&lista, 20);
printf("inserindo elemento 30 na lista\n");
    inserir(&lista, 30);
printf("imprimindo a lista\n");
    imprimir(&lista);
printf("removendo elemento da posicao 1 da lista\n");
    remover(&lista, 1);
printf("imprimindo a lista\n");
    imprimir(&lista);
    printf("Elemento 20 esta na posicao: %d\n", buscar(&lista, 20));
    printf("Tamanho atual: %d\n", size(&lista));
printf("limpando toda a lista\n");
    clear(&lista);
printf("impimindo a lista\n");
    imprimir(&lista);

    return 0;
}
