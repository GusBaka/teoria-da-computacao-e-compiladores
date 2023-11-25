#include <stdio.h>

// Função sucessor
int sucessor(int n) {
    return n + 1;
}

// Função soma recursiva
int soma(int m, int n) {
    // Base: se n = 0, então m + n = m
    if (n == 0) {
        return m;
    }
    // Passo recursivo: m + s(n) = s(m + n)
    else {
        return sucessor(soma(m, n - 1));
    }
}

int main() {
    int num1, num2;

    // Solicita ao usuário os números a serem somados
    printf("Informe o primeiro número: ");
    scanf("%d", &num1);
    printf("Informe o segundo número: ");
    scanf("%d", &num2);

    // Calcula e imprime a soma recursiva
    printf("A soma de %d e %d é: %d\n", num1, num2, soma(num1, num2));

    return 0;
}
