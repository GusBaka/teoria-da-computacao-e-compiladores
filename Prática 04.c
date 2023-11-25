#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para determinar o tamanho da string de forma recursiva
int tamanhoStringRecursiva(char *str) {
    if (*str == '\0') {
        return 0; // Caso base: fim da string
    } else {
        // Chamada recursiva para o restante da string
        return 1 + tamanhoStringRecursiva(str + 1);
    }
}

// Função para inverter a string de forma recursiva
void inverterStringRecursiva(char *str, char *resultado) {
    if (*str == '\0') {
        *resultado = '\0'; // Caso base: fim da string original
    } else {
        // Chamada recursiva para o restante da string
        inverterStringRecursiva(str + 1, resultado);
        
        // Concatenar o caractere atual no resultado
        strcat(resultado, str);
    }
}

int main() {
    FILE *arquivo;
    char nomeArquivo[100];
    
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    // Abrir o arquivo para leitura e escrita
    arquivo = fopen(nomeArquivo, "r+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Ler a string do arquivo
    char str[1000];
    fgets(str, sizeof(str), arquivo);

    // Determinar o tamanho da string e armazenar no arquivo
    int tamanho = tamanhoStringRecursiva(str);
    fprintf(arquivo, "Tamanho da string: %d\n", tamanho);

    // Determinar o reverso da string e armazenar no arquivo
    char reverso[1000] = "";
    inverterStringRecursiva(str, reverso);
    fprintf(arquivo, "Reverso da string: %s\n", reverso);

    // Fechar o arquivo
    fclose(arquivo);

    printf("Operações concluídas com sucesso.\n");

    return 0;
}
