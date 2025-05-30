#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista
typedef struct Node {
    int valor;
    struct Node* prox;
} Node;

// Estrutura da pilha
typedef struct {
    Node* topo;
} Pilha;

// Inicializa a pilha
void inicializa(Pilha* p) {
    p->topo = NULL;
}

// Verifica se a pilha está vazia
int esta_vazia(Pilha* p) {
    return p->topo == NULL;
}

// Adiciona um elemento ao topo da pilha
int push(Pilha* p, int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (!novo) return 0; // Falha na alocação
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
    return 1;
}

// Remove o elemento do topo da pilha
int pop(Pilha* p, int* valor) {
    if (esta_vazia(p)) return 0;
    Node* temp = p->topo;
    *valor = temp->valor;
    p->topo = temp->prox;
    free(temp);
    return 1;
}

// Consulta o elemento do topo da pilha sem remover
int topo(Pilha* p, int* valor) {
    if (esta_vazia(p)) return 0;
    *valor = p->topo->valor;
    return 1;
}

// Libera toda a pilha
void libera(Pilha* p) {
    int valor;
    while (pop(p, &valor));
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