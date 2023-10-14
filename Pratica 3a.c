// Versão não recursiva

#include <stdio.h>

int main() {
    int limite;
    printf("Informe o limite: ");
    scanf("%d", &limite);

    for (int n = 0; n <= limite; n++) {
        int resultado;
        if (n % 2 == 0) {
            resultado = -n / 2;
        } else {
            resultado = (n / 2) + 1;
        }
        printf("[%d, %d], ", n, resultado);
    }

    printf("\n");

    return 0;
}

// Versão recursiva

#include <stdio.h>

int calcularResultado(int n) {
    if (n == 0) {
        return 0;
    } else if (n % 2 == 0) {
        return -calcularResultado(n - 1);
    } else {
        return calcularResultado(n - 1) + 1;
    }
}

void imprimirRelacao(int n, int limite) {
    if (n > limite) {
        return;
    }

    int resultado = calcularResultado(n);
    printf("[%d, %d], ", n, resultado);
    imprimirRelacao(n + 1, limite);
}

int main() {
    int limite;
    printf("Informe o limite: ");
    scanf("%d", &limite);

    imprimirRelacao(0, limite);
    printf("\n");

    return 0;
}
