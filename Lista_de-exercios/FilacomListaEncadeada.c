#include <stdio.h>
#include <stdlib.h>

// Nó da lista
typedef struct Node {
    int valor;
    struct Node* prox;
} Node;

// Estrutura da fila
typedef struct {
    Node* inicio;
    Node* fim;
} Fila;

// Inicializa a fila
void inicializa(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

// Verifica se a fila está vazia
int esta_vazia(Fila* f) {
    return f->inicio == NULL;
}

// Enfileira um elemento
int enfileirar(Fila* f, int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (!novo) return 0;
    novo->valor = valor;
    novo->prox = NULL;
    if (esta_vazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    return 1;
}

// Desenfileira um elemento
int desenfileirar(Fila* f, int* valor) {
    if (esta_vazia(f)) return 0;
    Node* temp = f->inicio;
    *valor = temp->valor;
    f->inicio = temp->prox;
    if (f->inicio == NULL)
        f->fim = NULL;
    free(temp);
    return 1;
}

// Consulta o elemento da frente da fila sem remover
int frente(Fila* f, int* valor) {
    if (esta_vazia(f)) return 0;
    *valor = f->inicio->valor;
    return 1;
}

// Libera toda a fila
void libera(Fila* f) {
    int valor;
    while (desenfileirar(f, &valor));
}

// Exemplo de uso
int main() {
    Fila f;
    inicializa(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);

    int valor;
    if (frente(&f, &valor))
        printf("Frente: %d\n", valor);

    while (desenfileirar(&f, &valor))
        printf("Desenfileirado: %d\n", valor);

    if (esta_vazia(&f))
        printf("Fila está vazia.\n");

    return 0;
}