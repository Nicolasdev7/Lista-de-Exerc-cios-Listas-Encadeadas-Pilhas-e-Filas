#include <stdio.h>
#define MAX 100

// Função para calcular a água retida usando pilha
int trappingRainWater(int* altura, int n) {
    int pilha[MAX];
    int topo = -1;
    int agua = 0;

    for (int i = 0; i < n; i++) {
        while (topo != -1 && altura[i] > altura[pilha[topo]]) {
            int fundo = pilha[topo--];
            if (topo == -1)
                break;
            int distancia = i - pilha[topo] - 1;
            int altura_min = (altura[i] < altura[pilha[topo]] ? altura[i] : altura[pilha[topo]]) - altura[fundo];
            if (altura_min > 0)
                agua += distancia * altura_min;
        }
        pilha[++topo] = i;
    }
    return agua;
}

// Exemplo de uso
int main() {
    int barras[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(barras) / sizeof(barras[0]);
    int resultado = trappingRainWater(barras, n);
    printf("Água retida: %d\n", resultado); // Saída esperada: 6
    return 0;
}