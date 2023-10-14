#include <stdio.h>

// Função para ler uma sequência de números naturais a partir do teclado
void lerSequencia(int sequencia[], int tamanho) {
    printf("Digite a sequência de números naturais:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &sequencia[i]);
    }
}

// Função para apresentar uma sequência na tela
void apresentarSequencia(int sequencia[], int tamanho) {
    printf("Sequência: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", sequencia[i]);
    }
    printf("\n");
}

// Função para armazenar uma sequência em um arquivo de texto
void armazenarSequenciaEmArquivo(int sequencia[], int tamanho, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", sequencia[i]);
    }

    fclose(arquivo);
}

int main() {
    int tamanhoA, tamanhoB;

    printf("Digite o tamanho da sequência A: ");
    scanf("%d", &tamanhoA);

    printf("Digite o tamanho da sequência B: ");
    scanf("%d", &tamanhoB);

    int sequenciaA[tamanhoA];
    int sequenciaB[tamanhoB];

    lerSequencia(sequenciaA, tamanhoA);
    lerSequencia(sequenciaB, tamanhoB);

    apresentarSequencia(sequenciaA, tamanhoA);
    apresentarSequencia(sequenciaB, tamanhoB);

    armazenarSequenciaEmArquivo(sequenciaA, tamanhoA, "sequenciaA.txt");
    armazenarSequenciaEmArquivo(sequenciaB, tamanhoB, "sequenciaB.txt");

    // Outras operações e funções podem ser implementadas aqui

    return 0;
}
