#include <stdio.h>

// Função sucessor
int sucessor(int n) {
    return n + 1;
}

// Função Menor Que (MQ) não recursiva
void menor_que_nao_recursivo(int i) {
    int MQ[i + 1][i + 1];

    // Inicializa o conjunto MQ0
    for (int j = 0; j <= i; j++) {
        MQ[0][j] = 1;
    }

    // Gera os conjuntos MQi
    for (int j = 1; j <= i; j++) {
        for (int k = 0; k <= j; k++) {
            MQ[j][k] = MQ[j - 1][k];
            if (k > 0) {
                MQ[j][k] = MQ[j][k] || MQ[j - 1][k - 1];
            }
        }
    }

    // Imprime o conjunto final MQi
    printf("Conjunto MQ%d:\n", i);
    for (int j = 0; j <= i; j++) {
        for (int k = 0; k <= j; k++) {
            if (MQ[j][k]) {
                printf("[%d, %d] ", k, sucessor(j));
            }
        }
    }
    printf("\n");
}

int main() {
    int i;

    // Solicita ao usuário o valor de "i"
    printf("Informe o valor de \"i\": ");
    scanf("%d", &i);

    // Gera e imprime o conjunto MQi de forma não recursiva
    menor_que_nao_recursivo(i);

    return 0;
}
