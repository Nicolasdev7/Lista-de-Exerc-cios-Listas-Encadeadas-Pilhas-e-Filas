#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Função para inverter a lista iterativamente
void inverter_lista(No **lista) {
    No *anterior = NULL;
    No *atual = *lista;
    No *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    *lista = anterior;
}

// Função para imprimir a lista
void imprimir_lista(No *lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->valor);
        lista = lista->prox;
    }
    printf("NULL\n");
}

// Teste da função inverter_lista
int main() {
    // Criando lista: 1 -> 2 -> 3 -> NULL
    No *n1 = (No*)malloc(sizeof(No));
    No *n2 = (No*)malloc(sizeof(No));
    No *n3 = (No*)malloc(sizeof(No));
    n1->valor = 1; n1->prox = n2;
    n2->valor = 2; n2->prox = n3;
    n3->valor = 3; n3->prox = NULL;

    No *lista = n1;

    imprimir_lista(lista); // 1 -> 2 -> 3 -> NULL

    inverter_lista(&lista);

    imprimir_lista(lista); // Esperado: 3 -> 2 -> 1 -> NULL

    // Liberar memória
    No *aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }

    return 0;
}