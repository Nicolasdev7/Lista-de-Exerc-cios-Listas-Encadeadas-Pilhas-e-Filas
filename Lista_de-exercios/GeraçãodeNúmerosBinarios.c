#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Fila para strings
typedef struct {
    char dados[MAX][MAX];
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

// Enfileira uma string
int enfileirar(Fila* f, const char* str) {
    if (esta_cheia(f)) return 0;
    strcpy(f->dados[f->fim], str);
    f->fim = (f->fim + 1) % MAX;
    f->tamanho++;
    return 1;
}

// Desenfileira uma string
int desenfileirar(Fila* f, char* str) {
    if (esta_vazia(f)) return 0;
    strcpy(str, f->dados[f->inicio]);
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}

// Gera os primeiros N números binários
void gera_binarios(int N) {
    Fila f;
    inicializa(&f);

    enfileirar(&f, "1");

    for (int i = 0; i < N; i++) {
        char atual[MAX];
        desenfileirar(&f, atual);
        printf("%s\n", atual);

        char bin0[MAX], bin1[MAX];
        snprintf(bin0, MAX, "%s0", atual);
        snprintf(bin1, MAX, "%s1", atual);

        enfileirar(&f, bin0);
        enfileirar(&f, bin1);
    }
}

// Exemplo de uso
int main() {
    int N;
    printf("Digite o valor de N: ");
    scanf("%d", &N);

    printf("Primeiros %d números binários:\n", N);
    gera_binarios(N);

    return 0;
}