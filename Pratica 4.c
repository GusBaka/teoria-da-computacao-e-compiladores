#include <stdio.h>
#include <string.h>

// Função recursiva para calcular o tamanho de uma string
int tamanhoStringRecursiva(const char *str, int index) {
    if (str[index] == '\0') {
        return 0;
    }
    return 1 + tamanhoStringRecursiva(str, index + 1);
}

// Função recursiva para inverter uma string
void inverterStringRecursiva(const char *str, int index, char *reverso) {
    if (str[index] == '\0') {
        return;
    }
    inverterStringRecursiva(str, index + 1, reverso);
    reverso[strlen(str) - index - 1] = str[index];
}

int main() {
    FILE *arquivo = fopen("input.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char string[1000]; // Tamanho máximo da string
    if (fgets(string, sizeof(string), arquivo) == NULL) {
        printf("Erro ao ler a string do arquivo.\n");
        fclose(arquivo);
        return 1;
    }

    fclose(arquivo);

    int tamanho = tamanhoStringRecursiva(string, 0);
    printf("Tamanho da string: %d\n", tamanho);

    char reverso[1000]; // Tamanho máximo do reverso
    inverterStringRecursiva(string, 0, reverso);
    reverso[tamanho] = '\0'; // Adicione o caractere nulo ao final

    arquivo = fopen("output.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    fprintf(arquivo, "Tamanho da string: %d\n", tamanho);
    fprintf(arquivo, "String reversa: %s\n", reverso);

    fclose(arquivo);

    printf("String reversa: %s\n", reverso);
    printf("Resultados armazenados no arquivo 'output.txt'.\n");

    return 0;
}
