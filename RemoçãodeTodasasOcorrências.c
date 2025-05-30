#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Função para remover todas as ocorrências de um valor na lista
No* remover_todas_ocorrencias(No* head, int valor) {
    // Remove ocorrências no início
    while (head != NULL && head->valor == valor) {
        No* temp = head;
        head = head->prox;
        free(temp);
    }
    // Remove ocorrências no restante da lista
    No* atual = head;
    while (atual != NULL && atual->prox != NULL) {
        if (atual->prox->valor == valor) {
            No* temp = atual->prox;
            atual->prox = temp->prox;
            free(temp);
        } else {
            atual = atual->prox;
        }
    }
    return head;
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
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 4);
    inserir_fim(&lista, 2);

    printf("Lista original: ");
    imprimir_lista(lista);

    int valor = 2;
    lista = remover_todas_ocorrencias(lista, valor);

    printf("Lista após remover todas as ocorrências de %d: ", valor);
    imprimir_lista(lista);

    // Liberar memória
    No* aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }

    return 0;
}