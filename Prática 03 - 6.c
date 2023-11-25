#include <stdio.h>

// Tamanho máximo para o número de cidades
#define MAX_CIDADES 4

// Estrutura para representar o grafo
typedef struct {
    int matriz[MAX_CIDADES][MAX_CIDADES];
} GrafoRotuladoDirecionado;

// Função recursiva para calcular o comprimento do caminho entre duas cidades
int calcular_comprimento_caminho_recursivo(GrafoRotuladoDirecionado *grafo, int cidade_origem, int cidade_destino) {
    if (cidade_origem == cidade_destino) {
        return 0; // Caminho de uma cidade para ela mesma tem comprimento zero
    } else if (grafo->matriz[cidade_origem][cidade_destino] > 0) {
        return grafo->matriz[cidade_origem][cidade_destino];
    } else {
        int menor_caminho = -1;
        for (int i = 0; i < MAX_CIDADES; i++) {
            if (grafo->matriz[cidade_origem][i] > 0) {
                int caminho = calcular_comprimento_caminho_recursivo(grafo, i, cidade_destino);
                if (caminho >= 0 && (menor_caminho == -1 || caminho < menor_caminho)) {
                    menor_caminho = caminho;
                }
            }
        }
        return (menor_caminho == -1) ? -1 : menor_caminho + grafo->matriz[cidade_origem][cidade_destino];
    }
}

// Função para verificar se há ciclos no grafo
int verificar_ciclos(GrafoRotuladoDirecionado *grafo, int cidade) {
    // Implementação usando busca em profundidade (DFS)
    static int visitados[MAX_CIDADES] = {0};

    if (visitados[cidade] == 1) {
        return 1; // Ciclo detectado
    }

    if (visitados[cidade] == 0) {
        visitados[cidade] = 1;

        for (int i = 0; i < MAX_CIDADES; i++) {
            if (grafo->matriz[cidade][i] > 0) {
                if (verificar_ciclos(grafo, i)) {
                    return 1;
                }
            }
        }

        visitados[cidade] = 2;
    }

    return 0; // Não há ciclo
}

// Função para calcular o grau de entrada de cada nó
void calcular_grau_entrada(GrafoRotuladoDirecionado *grafo, int grau_entrada[]) {
    for (int i = 0; i < MAX_CIDADES; i++) {
        grau_entrada[i] = 0;
        for (int j = 0; j < MAX_CIDADES; j++) {
            if (grafo->matriz[j][i] > 0) {
                grau_entrada[i]++;
            }
        }
    }
}

// Função para calcular o grau de saída de cada nó
void calcular_grau_saida(GrafoRotuladoDirecionado *grafo, int grau_saida[]) {
    for (int i = 0; i < MAX_CIDADES; i++) {
        grau_saida[i] = 0;
        for (int j = 0; j < MAX_CIDADES; j++) {
            if (grafo->matriz[i][j] > 0) {
                grau_saida[i]++;
            }
        }
    }
}

int main() {
    GrafoRotuladoDirecionado grafo;

    // Inicializa a matriz de distâncias
    for (int i = 0; i < MAX_CIDADES; i++) {
        for (int j = 0; j < MAX_CIDADES; j++) {
            grafo.matriz[i][j] = 0;
        }
    }

    // Insere algumas distâncias no grafo
    grafo.matriz[0][1] = 4; // 4Km de 0 para 1
    grafo.matriz[0][2] = 5; // 5Km de 0 para 2
    grafo.matriz[1][3] = 2; // 2Km de 1 para 3
    grafo.matriz[2][3] = 3; // 3Km de 2 para 3

    // Calcula e imprime o comprimento do caminho entre duas cidades
    int cidade_origem, cidade_destino;
    printf("Informe a cidade de origem (0 a 3): ");
    scanf("%d", &cidade_origem);
    printf("Informe a cidade de destino (0 a 3): ");
    scanf("%d", &cidade_destino);

    int comprimento_caminho = calcular_comprimento_caminho_recursivo(&grafo, cidade_origem, cidade_destino);

    if (comprimento_caminho >= 0) {
        printf("O comprimento do caminho entre as cidades %d e %d é: %d Km\n", cidade_origem, cidade_destino, comprimento_caminho);
    } else {
        printf("Não há caminho entre as cidades %d e %d\n", cidade_origem, cidade_destino);
    }

    // Verifica se há ciclos no grafo
    if (verificar_ciclos(&grafo, 0)) {
        printf("Há ciclos no grafo.\n");
    } else {
        printf("Não há ciclos no grafo.\n");
    }

    // Calcula e imprime o grau de entrada de cada nó
    int grau_entrada[MAX_CIDADES];
    calcular_grau_entrada(&grafo, grau_entrada);
    printf("Grau de entrada de cada nó:\n");
    for (int i = 0; i < MAX_CIDADES; i++) {
        printf("Cidade %d: %d\n", i, grau_entrada[i]);
    }

    // Calcula e imprime o grau de saída de cada nó
    int grau_saida[MAX_CIDADES];
    calcular_grau_saida(&grafo, grau_saida);
    printf("Grau de saída de cada nó:\n");
    for (int i = 0; i < MAX_CIDADES; i++) {
        printf("Cidade %d: %d\n", i, grau_saida[i]);
    }

    return 0;
}
