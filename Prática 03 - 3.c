#include <stdio.h>

// Função sucessor
int sucessor(int n) {
    return n + 1;
}

// Função Menor Que (MQ) recursiva
void menor_que(int i) {
    int j, k;

    // Inicializa o conjunto MQ0
    int MQ[i + 1][i + 1];
    for (j = 0; j <= i; j++) {
        MQ[0][j] = 1;
    }

    // Gera os conjuntos MQi
    for (j = 1; j <= i; j++) {
        for (k = 0; k <= j; k++) {
            MQ[j][k] = MQ[j - 1][k];
            if (k > 0) {
                MQ[j][k] = MQ[j][k] || MQ[j - 1][k - 1];
            }
        }
    }

    // Imprime o conjunto final MQi
    printf("Conjunto MQ%d:\n", i);
    for (j = 0; j <= i; j++) {
        for (k = 0; k <= j; k++) {
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

    // Gera e imprime o conjunto MQi
    menor_que(i);

    return 0;
}
