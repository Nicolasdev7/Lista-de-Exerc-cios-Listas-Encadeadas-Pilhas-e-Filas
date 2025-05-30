#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista
typedef struct Node {
    int valor;
    struct Node* prox;
} Node;

// Função para detectar ciclo usando o Algoritmo de Floyd
int detectar_ciclo(Node* head) {
    Node* lento = head;
    Node* rapido = head;

    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
        if (lento == rapido)
            return 1; // Ciclo detectado
    }
    return 0; // Não há ciclo
}

// Função auxiliar para inserir no início da lista
Node* insere_inicio(Node* head, int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->prox = head;
    return novo;
}

// Exemplo de uso
int main() {
    Node* lista = NULL;
    lista = insere_inicio(lista, 10);
    lista = insere_inicio(lista, 20);
    lista = insere_inicio(lista, 30);

    // Sem ciclo
    printf("Ciclo? %s\n", detectar_ciclo(lista) ? "Sim" : "Não");

    // Criando um ciclo manualmente
    lista->prox->prox->prox = lista; // Aponta o último nó para o primeiro

    printf("Ciclo? %s\n", detectar_ciclo(lista) ? "Sim" : "Não");

    // Atenção: não liberar memória se houver ciclo para evitar loop infinito

    return 0;
}