#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Função para contar o número de nós na lista
int contar_nos(No *lista) {
    int cont = 0;
    while (lista != NULL) {
        cont++;
        lista = lista->prox;
    }
    return cont;
}

// Teste da função contar_nos
int main() {
    // Criando manualmente uma lista: 1 -> 2 -> 3 -> NULL
    No *n1 = (No*)malloc(sizeof(No));
    No *n2 = (No*)malloc(sizeof(No));
    No *n3 = (No*)malloc(sizeof(No));
    n1->valor = 1; n1->prox = n2;
    n2->valor = 2; n2->prox = n3;
    n3->valor = 3; n3->prox = NULL;

    printf("Quantidade de nós: %d\n", contar_nos(n1)); // Esperado: 3

    // Liberar memória
    free(n1);
    free(n2);
    free(n3);

    return 0;
}