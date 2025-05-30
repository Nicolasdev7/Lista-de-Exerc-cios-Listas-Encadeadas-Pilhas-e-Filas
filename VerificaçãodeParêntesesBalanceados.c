#include <stdio.h>
#include <string.h>

#define MAX 100

// Pilha com array para caracteres
typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializa(Pilha* p) {
    p->topo = -1;
}

int esta_vazia(Pilha* p) {
    return p->topo == -1;
}

int push(Pilha* p, char c) {
    if (p->topo == MAX - 1) return 0;
    p->dados[++(p->topo)] = c;
    return 1;
}

int pop(Pilha* p, char* c) {
    if (esta_vazia(p)) return 0;
    *c = p->dados[(p->topo)--];
    return 1;
}

// Função para verificar se os parênteses são balanceados
int verificar_balanceamento(const char* str) {
    Pilha p;
    inicializa(&p);
    char c, topo;

    for (int i = 0; str[i] != '\0'; i++) {
        c = str[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&p, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (esta_vazia(&p)) return 0;
            pop(&p, &topo);
            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{')) {
                return 0;
            }
        }
    }
    return esta_vazia(&p);
}

// Exemplo de uso
int main() {
    const char* exemplos[] = {
        "({[]})",
        "([)]",
        "([]{})",
        "((())",
        "",
        "{[()()]}"
    };

    for (int i = 0; i < 6; i++) {
        printf("\"%s\" -> %s\n", exemplos[i],
            verificar_balanceamento(exemplos[i]) ? "Válido" : "Inválido");
    }

    return 0;
}