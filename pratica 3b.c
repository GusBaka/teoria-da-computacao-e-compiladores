#include <stdio.h>

int sucessor(int n) {
    return n + 1;
}

int soma(int m, int n) {
    if (n == 0) {
        return m;
    } else {
        return soma(sucessor(m), n - 1);
    }
}

int main() {
    int m, n;
    printf("Informe dois números a serem somados (m n): ");
    scanf("%d %d", &m, &n);

    int resultado = soma(m, n);

    printf("A soma de %d + %d é igual a %d\n", m, n, resultado);

    return 0
