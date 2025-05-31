#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Função para rotacionar a lista em K posições
No* rotacionar_lista(No* head, int k) {
    if (!head || k == 0) return head;

    // Primeiro, conta o tamanho da lista
    int tamanho = 1;
    No* atual = head;
    while (atual->prox) {
        atual = atual->prox;
        tamanho++;
    }

    // Faz a lista circular
    atual->prox = head;

    // Calcula o novo final da lista
    k = k % tamanho;
    int passos = tamanho - k;
    No* novo_fim = head;
    for (int i = 1; i < passos; i++) {
        novo_fim = novo_fim->prox;
    }

    // O novo início é o próximo do novo final
    No* novo_head = novo_fim->prox;
    novo_fim->prox = NULL;

    return novo_head;
}

// Função auxiliar para inserir no final da lista
void inserir_fim(No** lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    if (*lista == NULL) {
        *lista = novo;
    } else {
        No* aux = *lista;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
}

// Função para imprimir a lista
void imprimir_lista(No* lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->valor);
        lista = lista->prox;
    }
    printf("NULL\n");
}

// Exemplo de uso
int main() {
    No* lista = NULL;
    inserir_fim(&lista, 1);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 3);
    inserir_fim(&lista, 4);
    inserir_fim(&lista, 5);

    printf("Lista original: ");
    imprimir_lista(lista);

    int k = 2;
    lista = rotacionar_lista(lista, k);

    printf("Lista após rotacionar %d posições: ", k);
    imprimir_lista(lista);

    // Liberação de memória omitida por simplicidade

    return 0;
}