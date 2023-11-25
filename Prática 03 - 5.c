#include <stdio.h>

// Tamanho máximo para o número de cidades
#define MAX_CIDADES 4

// Estrutura para representar o grafo
typedef struct {
    int matriz[MAX_CIDADES][MAX_CIDADES];
} GrafoRotulado;

// Procedimento não recursivo para inserir a distância entre duas cidades na matriz
void inserir_distancia(GrafoRotulado *grafo, int cidade_origem, int cidade_destino, int distancia) {
    grafo->matriz[cidade_origem][cidade_destino] = distancia;
    grafo->matriz[cidade_destino][cidade_origem] = distancia;
}

// Procedimento não recursivo para contar quantas estradas ligam as cidades
int contar_estradas(GrafoRotulado *grafo, int cidade) {
    int cont = 0;
    for (int i = 0; i < MAX_CIDADES; i++) {
        if (grafo->matriz[cidade][i] > 0) {
            cont++;
        }
    }
    return cont;
}

// Procedimento não recursivo para imprimir a matriz
void imprimir_matriz(GrafoRotulado *grafo) {
    printf("Matriz de distâncias:\n");
    for (int i = 0; i < MAX_CIDADES; i++) {
        for (int j = 0; j < MAX_CIDADES; j++) {
            printf("%d\t", grafo->matriz[i][j]);
        }
        printf("\n");
    }
}

// Função recursiva para obter a distância entre duas cidades
int obter_distancia_recursiva(GrafoRotulado *grafo, int cidade_origem, int cidade_destino) {
    if (grafo->matriz[cidade_origem][cidade_destino] > 0) {
        return grafo->matriz[cidade_origem][cidade_destino];
    } else {
        return 0;
    }
}

int main() {
    GrafoRotulado grafo;

    // Inicializa a matriz de distâncias
    for (int i = 0; i < MAX_CIDADES; i++) {
        for (int j = 0; j < MAX_CIDADES; j++) {
            grafo.matriz[i][j] = 0;
        }
    }

    // Insere algumas distâncias no grafo
    inserir_distancia(&grafo, 0, 1, 10);
    inserir_distancia(&grafo, 0, 2, 15);
    inserir_distancia(&grafo, 1, 3, 20);
    inserir_distancia(&grafo, 2, 3, 25);

    // Conta e imprime o número de estradas ligando as cidades
    for (int i = 0; i < MAX_CIDADES; i++) {
        printf("Cidade %d possui %d estradas\n", i, contar_estradas(&grafo, i));
    }

    // Imprime a matriz de distâncias
    imprimir_matriz(&grafo);

    // Testa a função recursiva para obter distância entre duas cidades
    int cidade_origem, cidade_destino;
    printf("Informe a cidade de origem (0 a 3): ");
    scanf("%d", &cidade_origem);
    printf("Informe a cidade de destino (0 a 3): ");
    scanf("%d", &cidade_destino);

    int distancia = obter_distancia_recursiva(&grafo, cidade_origem, cidade_destino);

    if (distancia > 0) {
        printf("A distância entre as cidades %d e %d é: %d\n", cidade_origem, cidade_destino, distancia);
    } else {
        printf("Não há estrada ligando as cidades %d e %d\n", cidade_origem, cidade_destino);
    }

    return 0;
}
