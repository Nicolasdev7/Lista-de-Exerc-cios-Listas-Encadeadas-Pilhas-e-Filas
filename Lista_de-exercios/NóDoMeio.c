#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Função para encontrar o nó do meio usando ponteiro rápido e lento
No* encontrar_meio(No *lista) {
    No *lento = lista;
    No *rapido = lista;

    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }
    return lento;
}

// Função para imprimir a lista
void imprimir_lista(No *lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->valor);
        lista = lista->prox;
    }
    printf("NULL\n");
}

// Teste da função encontrar_meio
int main() {
    // Criando lista: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    No *n1 = (No*)malloc(sizeof(No));
    No *n2 = (No*)malloc(sizeof(No));
    No *n3 = (No*)malloc(sizeof(No));
    No *n4 = (No*)malloc(sizeof(No));
    No *n5 = (No*)malloc(sizeof(No));
    n1->valor = 1; n1->prox = n2;
    n2->valor = 2; n2->prox = n3;
    n3->valor = 3; n3->prox = n4;
    n4->valor = 4; n4->prox = n5;
    n5->valor = 5; n5->prox = NULL;

    No *lista = n1;

    imprimir_lista(lista); // 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    No *meio = encontrar_meio(lista);
    if (meio != NULL)
        printf("Nó do meio: %d\n", meio->valor); // Esperado: 3

    // Liberar memória
    No *aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }

    return 0;
}