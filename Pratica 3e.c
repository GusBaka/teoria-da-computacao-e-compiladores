#include <stdio.h>

#define NUM_CIDADES 4

// Estrutura que representa o grafo
struct Grafo {
    int matriz[NUM_CIDADES][NUM_CIDADES];
};

// Função para inicializar o grafo com distâncias inicialmente zeradas
void inicializarGrafo(struct Grafo *grafo) {
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            grafo->matriz[i][j] = 0;
        }
    }
}

// Função para inserir a distância entre duas cidades na matriz do grafo
void inserirDistancia(struct Grafo *grafo, int cidadeA, int cidadeB, int distancia) {
    grafo->matriz[cidadeA][cidadeB] = distancia;
    grafo->matriz[cidadeB][cidadeA] = distancia; // A matriz é simétrica para representar a ida e a volta
}

// Função para contar quantas estradas ligam as cidades
int contarEstradas(struct Grafo *grafo) {
    int contador = 0;
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = i + 1; j < NUM_CIDADES; j++) {
            if (grafo->matriz[i][j] > 0) {
                contador++;
            }
        }
    }
    return contador;
}

// Função para imprimir a matriz do grafo
void imprimirMatriz(struct Grafo *grafo) {
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            printf("%d ", grafo->matriz[i][j]);
        }
        printf("\n");
    }
}

// Função recursiva para obter a distância entre duas cidades
int obterDistancia(struct Grafo *grafo, int cidadeA, int cidadeB) {
    if (grafo->matriz[cidadeA][cidadeB] > 0) {
        return grafo->matriz[cidadeA][cidadeB];
    }
    return 0;
}

int main() {
    struct Grafo grafo;
    inicializarGrafo(&grafo);

    inserirDistancia(&grafo, 0, 1, 50); // Cidade 0 para Cidade 1
    inserirDistancia(&grafo, 1, 2, 30); // Cidade 1 para Cidade 2
    inserirDistancia(&grafo, 2, 3, 40); // Cidade 2 para Cidade 3

    printf("Matriz do Grafo:\n");
    imprimirMatriz(&grafo);

    int estradas = contarEstradas(&grafo);
    printf("Total de estradas: %d\n", estradas);

    int cidadeA, cidadeB;
    printf("Informe as cidades para calcular a distância (0 a %d): ", NUM_CIDADES - 1);
    scanf("%d %d", &cidadeA, &cidadeB);
    int distancia = obterDistancia(&grafo, cidadeA, cidadeB);
    if (distancia > 0) {
        printf("Distância entre Cidade %d e Cidade %d: %d\n", cidadeA, cidadeB, distancia);
    } else {
        printf("Não há estrada ligando as cidades.\n");
    }

    return 0;
}
