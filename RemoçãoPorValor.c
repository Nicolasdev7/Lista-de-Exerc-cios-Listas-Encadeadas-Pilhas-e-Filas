#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Função para remover a primeira ocorrência de um valor na lista
void remover_valor(No **lista, int valor) {
    No *atual = *lista;
    No *anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                // Remover o primeiro nó
                *lista = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

// Função para imprimir a lista
void imprimir_lista(No *lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->valor);
        lista = lista->prox;
    }
    printf("NULL\n");
}

// Teste da função remover_valor
int main() {
    // Criando lista: 1 -> 2 -> 3 -> 2 -> NULL
    No *n1 = (No*)malloc(sizeof(No));
    No *n2 = (No*)malloc(sizeof(No));
    No *n3 = (No*)malloc(sizeof(No));
    No *n4 = (No*)malloc(sizeof(No));
    n1->valor = 1; n1->prox = n2;
    n2->valor = 2; n2->prox = n3;
    n3->valor = 3; n3->prox = n4;
    n4->valor = 2; n4->prox = NULL;

    No *lista = n1;

    imprimir_lista(lista); // 1 -> 2 -> 3 -> 2 -> NULL

    remover_valor(&lista, 2);

    imprimir_lista(lista); // Esperado: 1 -> 3 -> 2 -> NULL

    // Liberar memória
    No *aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }

    return 0;
}