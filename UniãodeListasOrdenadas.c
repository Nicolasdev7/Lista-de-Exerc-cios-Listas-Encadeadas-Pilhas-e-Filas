#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Função para unir duas listas ordenadas em uma única lista ordenada
No* unir_listas_ordenadas(No* l1, No* l2) {
    No dummy;
    No* tail = &dummy;
    dummy.prox = NULL;

    while (l1 && l2) {
        if (l1->valor <= l2->valor) {
            tail->prox = l1;
            l1 = l1->prox;
        } else {
            tail->prox = l2;
            l2 = l2->prox;
        }
        tail = tail->prox;
    }
    // Liga o restante da lista não vazia
    tail->prox = (l1) ? l1 : l2;
    return dummy.prox;
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
    No* l1 = NULL;
    No* l2 = NULL;

    // Lista 1: 1 -> 3 -> 5
    inserir_fim(&l1, 1);
    inserir_fim(&l1, 3);
    inserir_fim(&l1, 5);

    // Lista 2: 2 -> 4 -> 6
    inserir_fim(&l2, 2);
    inserir_fim(&l2, 4);
    inserir_fim(&l2, 6);

    printf("Lista 1: ");
    imprimir_lista(l1);
    printf("Lista 2: ");
    imprimir_lista(l2);

    No* unida = unir_listas_ordenadas(l1, l2);

    printf("Lista unida: ");
    imprimir_lista(unida);

    // Liberar memória
    No* aux;
    while (unida != NULL) {
        aux = unida;
        unida = unida->prox;
        free(aux);
    }

    return 0;
}