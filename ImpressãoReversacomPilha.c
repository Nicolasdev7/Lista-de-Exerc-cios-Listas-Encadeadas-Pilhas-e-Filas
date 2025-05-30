#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Definição da estrutura da lista ligada
typedef struct Node {
    int valor;
    struct Node* prox;
} Node;

// Definição da pilha com array
typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

// Funções da pilha
void inicializaPilha(Pilha* p) {
    p->topo = -1;
}

int pilhaVazia(Pilha* p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha* p) {
    return p->topo == MAX - 1;
}

int push(Pilha* p, int valor) {
    if (pilhaCheia(p)) return 0;
    p->dados[++(p->topo)] = valor;
    return 1;
}

int pop(Pilha* p, int* valor) {
    if (pilhaVazia(p)) return 0;
    *valor = p->dados[(p->topo)--];
    return 1;
}

// Função para imprimir a lista em ordem reversa usando pilha
void imprimeReverso(Node* head) {
    Pilha p;
    inicializaPilha(&p);

    // Empilha todos os elementos da lista
    Node* atual = head;
    while (atual != NULL) {
        push(&p, atual->valor);
        atual = atual->prox;
    }

    // Desempilha e imprime
    int valor;
    while (pop(&p, &valor)) {
        printf("%d ", valor);
    }
    printf("\n");
}

// Função auxiliar para inserir no início da lista
Node* insereInicio(Node* head, int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->prox = head;
    return novo;
}

// Exemplo de uso
int main() {
    Node* lista = NULL;
    lista = insereInicio(lista, 10);
    lista = insereInicio(lista, 20);
    lista = insereInicio(lista, 30);

    printf("Impressão reversa: ");
    imprimeReverso(lista);

    // Libera memória
    Node* temp;
    while (lista) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}