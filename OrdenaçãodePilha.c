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
    if (p->topo == MAX - 1) return 0;
    p->dados[++(p->topo)] = valor;
    return 1;
}

// Remove o elemento do topo da pilha
int pop(Pilha* p, int* valor) {
    if (esta_vazia(p)) return 0;
    *valor = p->dados[(p->topo)--];
    return 1;
}

// Consulta o elemento do topo da pilha sem remover
int topo(Pilha* p, int* valor) {
    if (esta_vazia(p)) return 0;
    *valor = p->dados[p->topo];
    return 1;
}

// Função para ordenar a pilha usando uma pilha auxiliar
void ordenar_pilha(Pilha* p) {
    Pilha aux;
    inicializa(&aux);
    int temp;

    while (!esta_vazia(p)) {
        pop(p, &temp);

        // Move elementos maiores de aux para p
        int topo_aux;
        while (!esta_vazia(&aux) && topo(&aux, &topo_aux) && topo_aux > temp) {
            int val;
            pop(&aux, &val);
            push(p, val);
        }

        push(&aux, temp);
    }

    // Move de volta para a pilha original (ordenada)
    while (!esta_vazia(&aux)) {
        int val;
        pop(&aux, &val);
        push(p, val);
    }
}

// Exemplo de uso
int main() {
    Pilha p;
    inicializa(&p);

    push(&p, 3);
    push(&p, 1);
    push(&p, 4);
    push(&p, 2);

    printf("Pilha antes da ordenação (do topo para base):\n");
    for (int i = p.topo; i >= 0; i--)
        printf("%d ", p.dados[i]);
    printf("\n");

    ordenar_pilha(&p);

    printf("Pilha após a ordenação (do topo para base):\n");
    for (int i = p.topo; i >= 0; i--)
        printf("%d ", p.dados[i]);
    printf("\n");

    return 0;
}