#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Insere um novo nó no início da lista
void inserir_inicio(No **lista, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocação!\n");
        return;
    }
    novo->valor = valor;
    novo->prox = *lista;
    *lista = novo;
}

// Insere um novo nó no fim da lista
void inserir_fim(No **lista, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocação!\n");
        return;
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No *aux = *lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
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

// Exemplo de uso
int main() {
    No *lista = NULL;

    inserir_fim(&lista, 10);
    inserir_inicio(&lista, 5);
    inserir_fim(&lista, 20);

    imprimir_lista(lista); // Esperado: 5 -> 10 -> 20 -> NULL

    printf("Quantidade de nós: %d\n", contar_nos(lista)); // Esperado: 3

    // Liberar memória
    No *aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }

    return 0;
}