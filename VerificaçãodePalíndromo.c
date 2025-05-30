#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char dados[MAX];
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

// Adiciona um caractere ao topo da pilha
int push(Pilha* p, char c) {
    if (p->topo == MAX - 1) return 0;
    p->dados[++(p->topo)] = c;
    return 1;
}

// Remove o caractere do topo da pilha
int pop(Pilha* p, char* c) {
    if (esta_vazia(p)) return 0;
    *c = p->dados[(p->topo)--];
    return 1;
}

// Função para verificar se uma string é palíndromo usando pilha
int eh_palindromo(const char* str) {
    Pilha p;
    inicializa(&p);
    int len = strlen(str);

    // Empilha todos os caracteres da string
    for (int i = 0; i < len; i++) {
        push(&p, str[i]);
    }

    // Compara desempilhando
    for (int i = 0; i < len; i++) {
        char c;
        pop(&p, &c);
        if (c != str[i]) return 0;
    }
    return 1;
}

// Exemplo de uso
int main() {
    char str[MAX];
    printf("Digite uma palavra: ");
    fgets(str, MAX, stdin);

    // Remove o '\n' do final, se houver
    str[strcspn(str, "\n")] = '\0';

    if (eh_palindromo(str))
        printf("É palíndromo!\n");
    else
        printf("Não é palíndromo.\n");

    return 0;
}