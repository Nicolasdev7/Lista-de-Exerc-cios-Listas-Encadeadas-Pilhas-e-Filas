#include <stdio.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

// Inicializa a fila
void inicializa(Fila* f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

// Verifica se a fila está vazia
int esta_vazia(Fila* f) {
    return f->tamanho == 0;
}

// Verifica se a fila está cheia
int esta_cheia(Fila* f) {
    return f->tamanho == MAX;
}

// Enfileira um elemento
int enfileirar(Fila* f, int valor) {
    if (esta_cheia(f)) return 0;
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->tamanho++;
    return 1;
}

// Desenfileira um elemento
int desenfileirar(Fila* f, int* valor) {
    if (esta_vazia(f)) return 0;
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}

// Consulta o elemento da frente da fila sem remover
int frente(Fila* f, int* valor) {
    if (esta_vazia(f)) return 0;
    *valor = f->dados[f->inicio];
    return 1;
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