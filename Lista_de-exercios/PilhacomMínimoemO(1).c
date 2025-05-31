#include <stdio.h>
#include <limits.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int minimos[MAX];
    int topo;
} PilhaMin;

// Inicializa a pilha
void inicializa(PilhaMin* p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int esta_vazia(PilhaMin* p) {
    return p->topo == -1;
}

// Adiciona um elemento ao topo da pilha
int push(PilhaMin* p, int valor) {
    if (p->topo == MAX - 1) return 0;
    p->dados[++(p->topo)] = valor;
    if (p->topo == 0)
        p->minimos[p->topo] = valor;
    else
        p->minimos[p->topo] = (valor < p->minimos[p->topo - 1]) ? valor : p->minimos[p->topo - 1];
    return 1;
}

// Remove o elemento do topo da pilha
int pop(PilhaMin* p, int* valor) {
    if (esta_vazia(p)) return 0;
    *valor = p->dados[(p->topo)--];
    return 1;
}

// Consulta o elemento do topo da pilha sem remover
int topo(PilhaMin* p, int* valor) {
    if (esta_vazia(p)) return 0;
    *valor = p->dados[p->topo];
    return 1;
}

// Retorna o menor elemento da pilha em O(1)
int obter_minimo(PilhaMin* p, int* minimo) {
    if (esta_vazia(p)) return 0;
    *minimo = p->minimos[p->topo];
    return 1;
}

// Exemplo de uso
int main() {
    PilhaMin p;
    inicializa(&p);

    push(&p, 5);
    push(&p, 3);
    push(&p, 7);
    push(&p, 2);

    int valor, minimo;
    if (obter_minimo(&p, &minimo))
        printf("Mínimo: %d\n", minimo);

    pop(&p, &valor);
    if (obter_minimo(&p, &minimo))
        printf("Mínimo após pop: %d\n", minimo);

    return 0;
}