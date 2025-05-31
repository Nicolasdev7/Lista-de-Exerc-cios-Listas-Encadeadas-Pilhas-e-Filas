#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Função para inserir em uma posição específica (0-indexada)
void inserir_posicao(No **lista, int valor, int pos) {
    No *novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocação!\n");
        return;
    }
    novo->valor = valor;

    if (pos == 0) {
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    No *atual = *lista;
    int i = 0;
    while (atual != NULL && i < pos - 1) {
        atual = atual->prox;
        i++;
    }

    if (atual == NULL) {
        printf("Posição inválida!\n");
        free(novo);
        return;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

// Função para imprimir a lista
void imprimir_lista(No *lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->valor);
        lista = lista->prox;
    }
    printf("NULL\n");
}

// Teste da função inserir_posicao
int main() {
    No *lista = NULL;

    inserir_posicao(&lista, 10, 0); // 10
    inserir_posicao(&lista, 20, 1); // 10 -> 20
    inserir_posicao(&lista, 15, 1); // 10 -> 15 -> 20
    inserir_posicao(&lista, 5, 0);  // 5 -> 10 -> 15 -> 20

    imprimir_lista(lista); // Esperado: 5 -> 10 -> 15 -> 20 -> NULL

    // Liberar memória
    No *aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }

    return 0;
}