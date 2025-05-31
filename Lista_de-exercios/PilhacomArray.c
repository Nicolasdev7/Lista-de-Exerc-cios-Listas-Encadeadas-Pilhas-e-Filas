#include <stdio.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

// Inicializa a pilha
void inicializa(Pilha* p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int esta_vazia(Pilha* p) {
    return p->topo == -1;
}

// Adiciona um elemento ao topo da pilha
int push(Pilha* p, int valor) {
    if (p->topo == MAX - 1) return 0; // Pilha cheia
    p->dados[++(p->topo)] = valor;
    return 1;
}

// Remove o elemento do topo da pilha
int pop(Pilha* p, int* valor) {
    if (esta_vazia(p)) return 0; // Pilha vazia
    *valor = p->dados[(p->topo)--];
    return 1;
}

// Consulta o elemento do topo da pilha sem remover
int topo(Pilha* p, int* valor) {
    if (esta_vazia(p)) return 0;
    *valor = p->dados[p->topo];
    return 1;
}

// Exemplo de uso
int main() {
    Pilha p;
    inicializa(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    int valor;
    if (topo(&p, &valor))
        printf("Topo: %d\n", valor);

    while (pop(&p, &valor))
        printf("Pop: %d\n", valor);

    if (esta_vazia(&p))
        printf("Pilha está vazia.\n");

    return 0;
}