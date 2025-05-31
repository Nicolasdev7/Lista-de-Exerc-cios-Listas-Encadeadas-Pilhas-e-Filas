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

// Função para inverter uma string usando pilha
void inverte_string(const char* str, char* invertida) {
    Pilha p;
    inicializa(&p);

    // Empilha todos os caracteres da string
    for (int i = 0; str[i] != '\0'; i++) {
        push(&p, str[i]);
    }

    // Desempilha para inverter
    int i = 0;
    char c;
    while (pop(&p, &c)) {
        invertida[i++] = c;
    }
    invertida[i] = '\0';
}

// Exemplo de uso
int main() {
    char str[MAX], invertida[MAX];
    printf("Digite uma string: ");
    fgets(str, MAX, stdin);

    // Remove o '\n' do final, se houver
    str[strcspn(str, "\n")] = '\0';

    inverte_string(str, invertida);
    printf("String invertida: %s\n", invertida);

    return 0;
}