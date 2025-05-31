#include <stdio.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int topo1;
    int topo2;
} DuasPilhas;

// Inicializa as duas pilhas
void inicializa(DuasPilhas* p) {
    p->topo1 = -1;
    p->topo2 = MAX;
}

// Push na pilha 1
int push1(DuasPilhas* p, int valor) {
    if (p->topo1 + 1 == p->topo2) return 0; // Sem espaço
    p->dados[++(p->topo1)] = valor;
    return 1;
}

// Push na pilha 2
int push2(DuasPilhas* p, int valor) {
    if (p->topo2 - 1 == p->topo1) return 0; // Sem espaço
    p->dados[--(p->topo2)] = valor;
    return 1;
}

// Pop na pilha 1
int pop1(DuasPilhas* p, int* valor) {
    if (p->topo1 == -1) return 0;
    *valor = p->dados[(p->topo1)--];
    return 1;
}

// Pop na pilha 2
int pop2(DuasPilhas* p, int* valor) {
    if (p->topo2 == MAX) return 0;
    *valor = p->dados[(p->topo2)++];
    return 1;
}

// Exemplo de uso
int main() {
    DuasPilhas p;
    inicializa(&p);

    push1(&p, 10);
    push1(&p, 20);
    push2(&p, 100);
    push2(&p, 200);

    int valor;
    pop1(&p, &valor);
    printf("Pop pilha 1: %d\n", valor);

    pop2(&p, &valor);
    printf("Pop pilha 2: %d\n", valor);

    return 0;
}