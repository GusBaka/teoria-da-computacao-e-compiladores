#include <stdio.h>

// Função para gerar a relação entre números naturais e inteiros de forma não recursiva
void generate_mapping_non_recursive(int limit) {
    int n;
    for (n = 0; n <= limit; n++) {
        if (n % 2 == 0) {
            printf("[%d, %d], ", n, -n / 2);
        } else {
            printf("[%d, %d], ", n, n / 2 + 1);
        }
    }
    printf("\n");
}

// Função para gerar a relação entre números naturais e inteiros de forma recursiva
void generate_mapping_recursive(int n, int limit) {
    if (n <= limit) {
        if (n % 2 == 0) {
            printf("[%d, %d], ", n, -n / 2);
        } else {
            printf("[%d, %d], ", n, n / 2 + 1);
        }
        generate_mapping_recursive(n + 1, limit);
    }
}

int main() {
    int limite;

    // Solicita ao usuário o número limite
    printf("Informe o limite: ");
    scanf("%d", &limite);

    // Gera e imprime a relação de forma não recursiva
    printf("Versão não recursiva: ");
    generate_mapping_non_recursive(limite);

    // Gera e imprime a relação de forma recursiva
    printf("Versão recursiva: ");
    generate_mapping_recursive(0, limite);
    printf("\n");

    return 0;
}
