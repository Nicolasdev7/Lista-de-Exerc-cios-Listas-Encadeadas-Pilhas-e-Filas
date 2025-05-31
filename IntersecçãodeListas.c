#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Função para encontrar o nó de interseção entre duas listas
No* encontrar_intersecao(No* l1, No* l2) {
    // Calcula o tamanho das duas listas
    int tam1 = 0, tam2 = 0;
    No* p1 = l1;
    No* p2 = l2;
    while (p1) {
        tam1++;
        p1 = p1->prox;
    }
    while (p2) {
        tam2++;
        p2 = p2->prox;
    }

    // Ajusta os ponteiros para que ambos tenham a mesma distância até o final
    p1 = l1;
    p2 = l2;
    if (tam1 > tam2) {
        for (int i = 0; i < tam1 - tam2; i++)
            p1 = p1->prox;
    } else {
        for (int i = 0; i < tam2 - tam1; i++)
            p2 = p2->prox;
    }

    // Avança ambos até encontrar a interseção ou o final
    while (p1 && p2) {
        if (p1 == p2)
            return p1;
        p1 = p1->prox;
        p2 = p2->prox;
    }
    return NULL;
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
    // Cria duas listas que se intersectam
    No* comum = NULL;
    inserir_fim(&comum, 7);
    inserir_fim(&comum, 8);

    No* l1 = NULL;
    inserir_fim(&l1, 1);
    inserir_fim(&l1, 2);
    inserir_fim(&l1, 3);

    No* l2 = NULL;
    inserir_fim(&l2, 4);
    inserir_fim(&l2, 5);

    // Faz as listas se encontrarem no nó 'comum'
    No* aux = l1;
    while (aux->prox != NULL) aux = aux->prox;
    aux->prox = comum;

    aux = l2;
    while (aux->prox != NULL) aux = aux->prox;
    aux->prox = comum;

    printf("Lista 1: ");
    imprimir_lista(l1);
    printf("Lista 2: ");
    imprimir_lista(l2);

    No* intersecao = encontrar_intersecao(l1, l2);
    if (intersecao)
        printf("Interseção encontrada no nó com valor: %d\n", intersecao->valor);
    else
        printf("Não há interseção.\n");

    // Liberação de memória omitida por simplicidade

    return 0;
}