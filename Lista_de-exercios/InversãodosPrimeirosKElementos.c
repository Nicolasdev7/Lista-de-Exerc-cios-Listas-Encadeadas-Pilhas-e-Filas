#include <stdio.h>
#define MAX 100

// Estrutura da fila
typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

// Estrutura da pilha
typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

// Inicializa a fila
void inicializa_fila(Fila* f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

// Inicializa a pilha
void inicializa_pilha(Pilha* p) {
    p->topo = -1;
}

// Verifica se a fila está vazia
int fila_vazia(Fila* f) {
    return f->tamanho == 0;
}

// Verifica se a fila está cheia
int fila_cheia(Fila* f) {
    return f->tamanho == MAX;
}

// Enfileira um elemento
int enfileirar(Fila* f, int valor) {
    if (fila_cheia(f)) return 0;
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->tamanho++;
    return 1;
}

// Desenfileira um elemento
int desenfileirar(Fila* f, int* valor) {
    if (fila_vazia(f)) return 0;
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}

// Adiciona um elemento ao topo da pilha
int push(Pilha* p, int valor) {
    if (p->topo == MAX - 1) return 0;
    p->dados[++(p->topo)] = valor;
    return 1;
}

// Remove o elemento do topo da pilha
int pop(Pilha* p, int* valor) {
    if (p->topo == -1) return 0;
    *valor = p->dados[(p->topo)--];
    return 1;
}

// Função para inverter os primeiros K elementos da fila
void inverter_primeiros_k(Fila* f, int k) {
    if (k <= 0 || k > f->tamanho) return;

    Pilha p;
    inicializa_pilha(&p);

    // Passo 1: Desenfileira os primeiros K elementos e empilha
    int valor;
    for (int i = 0; i < k; i++) {
        desenfileirar(f, &valor);
        push(&p, valor);
    }

    // Passo 2: Desempilha e enfileira de volta (invertendo)
    while (p.topo != -1) {
        pop(&p, &valor);
        enfileirar(f, valor);
    }

    // Passo 3: Move os restantes para o final para manter a ordem
    int resto = f->tamanho - k;
    for (int i = 0; i < resto; i++) {
        desenfileirar(f, &valor);
        enfileirar(f, valor);
    }
}

// Exemplo de uso
int main() {
    Fila f;
    inicializa_fila(&f);

    // Preenche a fila com alguns valores
    for (int i = 1; i <= 7; i++)
        enfileirar(&f, i);

    int k = 4;
    printf("Fila original: ");
    for (int i = 0, idx = f.inicio; i < f.tamanho; i++, idx = (idx + 1) % MAX)
        printf("%d ", f.dados[idx]);
    printf("\n");

    inverter_primeiros_k(&f, k);

    printf("Fila após inverter os primeiros %d elementos: ", k);
    for (int i = 0, idx = f.inicio; i < f.tamanho; i++, idx = (idx + 1) % MAX)
        printf("%d ", f.dados[idx]);
    printf("\n");

    return 0;
}