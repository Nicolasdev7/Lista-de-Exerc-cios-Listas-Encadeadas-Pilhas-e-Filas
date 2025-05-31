#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

// Função para avaliar expressão pós-fixa
int avaliar_posfixa(const char* expr) {
    Pilha p;
    inicializa(&p);

    char token[MAX];
    int i = 0, j = 0;
    while (expr[i] != '\0') {
        // Ignora espaços
        if (isspace(expr[i])) {
            i++;
            continue;
        }

        // Se for número, lê o número inteiro
        if (isdigit(expr[i]) || (expr[i] == '-' && isdigit(expr[i+1]))) {
            j = 0;
            if (expr[i] == '-') {
                token[j++] = expr[i++];
            }
            while (isdigit(expr[i])) {
                token[j++] = expr[i++];
            }
            token[j] = '\0';
            push(&p, atoi(token));
        }
        // Se for operador
        else if (strchr("+-*/", expr[i])) {
            int b, a, res;
            pop(&p, &b);
            pop(&p, &a);
            switch (expr[i]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            push(&p, res);
            i++;
        } else {
            // Ignora outros caracteres
            i++;
        }
    }

    int resultado = 0;
    pop(&p, &resultado);
    return resultado;
}

// Exemplo de uso
int main() {
    char expr[MAX];
    printf("Digite a expressão pós-fixa: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    int resultado = avaliar_posfixa(expr);
    printf("Resultado: %d\n", resultado);

    return 0;
}