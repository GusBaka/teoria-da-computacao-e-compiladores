#include <stdio.h>

#define NUM_CIDADES 4

// Estrutura que representa o grafo
struct Grafo {
    int matriz[NUM_CIDADES][NUM_CIDADES];
};

// Função para inicializar o grafo com valores iniciais
void inicializarGrafo(struct Grafo *grafo) {
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            grafo->matriz[i][j] = 0;
        }
    }
}

// Função para adicionar uma aresta de um nó para outro com um rótulo
void adicionarAresta(struct Grafo *grafo, int origem, int destino, int rotulo) {
    grafo->matriz[origem][destino] = rotulo;
}

// Função para calcular o comprimento do caminho entre duas cidades de forma recursiva
int calcularComprimentoCaminho(struct Grafo *grafo, int cidadeA, int cidadeB) {
    if (cidadeA == cidadeB) {
        return 0; // Chegou ao destino
    }
    int menorComprimento = -1; // Inicializa com um valor impossível

    for (int i = 0; i < NUM_CIDADES; i++) {
        if (grafo->matriz[cidadeA][i] > 0) {
            int comprimentoCaminho = calcularComprimentoCaminho(grafo, i, cidadeB);
            if (comprimentoCaminho >= 0) {
                int comprimentoAresta = grafo->matriz[cidadeA][i];
                if (menorComprimento == -1 || comprimentoCaminho + comprimentoAresta < menorComprimento) {
                    menorComprimento = comprimentoCaminho + comprimentoAresta;
                }
            }
        }
    }

    return menorComprimento;
}

// Função para verificar se há ciclos no grafo
int possuiCiclos(struct Grafo *grafo) {
    for (int i = 0; i < NUM_CIDADES; i++) {
        int visitados[NUM_CIDADES];
        for (int j = 0; j < NUM_CIDADES; j++) {
            visitados[j] = 0;
        }

        if (dfs(grafo, i, visitados)) {
            return 1; // Encontrou um ciclo
        }
    }
    return 0; // Não encontrou ciclos
}

// Função de busca em profundidade (DFS) para verificar ciclos
int dfs(struct Grafo *grafo, int cidade, int visitados[]) {
    if (visitados[cidade] == 1) {
        return 1; // Encontrou um ciclo
    }
    if (visitados[cidade] == 2) {
        return 0; // Visitado, mas não encontrou ciclo
    }

    visitados[cidade] = 1;

    for (int i = 0; i < NUM_CIDADES; i++) {
        if (grafo->matriz[cidade][i] > 0) {
            if (dfs(grafo, i, visitados)) {
                return 1; // Encontrou um ciclo
            }
        }
    }

    visitados[cidade] = 2;
    return 0;
}

// Função para calcular o grau de entrada de cada nó
void calcularGrauEntrada(struct Grafo *grafo) {
    int grauEntrada[NUM_CIDADES];
    for (int i = 0; i < NUM_CIDADES; i++) {
        grauEntrada[i] = 0;
    }

    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            if (grafo->matriz[j][i] > 0) {
                grauEntrada[i]++;
            }
        }
    }

    printf("Grau de Entrada de cada cidade:\n");
    for (int i = 0; i < NUM_CIDADES; i++) {
        printf("Cidade %d: %d\n", i, grauEntrada[i]);
    }
}

// Função para calcular o grau de saída de cada nó
void calcularGrauSaida(struct Grafo *grafo) {
    int grauSaida[NUM_CIDADES];
    for (int i = 0; i < NUM_CIDADES; i++) {
        grauSaida[i] = 0;
    }

    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            if (grafo->matriz[i][j] > 0) {
                grauSaida[i]++;
            }
        }
    }

    printf("Grau de Saída de cada cidade:\n");
    for (int i = 0; i < NUM_CIDADES; i++) {
        printf("Cidade %d: %d\n", i, grauSaida[i]);
    }
}

int main() {
    struct Grafo grafo;
    inicializarGrafo(&grafo);

    adicionarAresta(&grafo, 0, 1, 50); // Cidade 0 para Cidade 1
    adicionarAresta(&grafo, 1, 2, 30); // Cidade 1 para Cidade 2
    adicionarAresta(&grafo, 2, 3, 40); // Cidade 2 para Cidade 3
    adicionarAresta(&grafo, 3, 0, 20); // Cidade 3 para Cidade 0

    printf("Comprimento do caminho entre cidades:\n");
    int cidadeA, cidadeB;
    printf("Informe as cidades (0 a %d) para calcular o comprimento do caminho: ", NUM_CIDADES - 1);
    scanf("%d %d", &cidadeA, &cidadeB);
    int comprimento = calcularComprimentoCaminho(&grafo, cidadeA, cidadeB);
    if (comprimento >= 0) {
        printf("Comprimento do caminho entre Cidade %d e Cidade %d: %d\n", cidadeA, cidadeB, comprimento);
    } else {
        printf("Não há caminho entre as cidades.\n");
    }

    int possuiCiclo = possuiCiclos(&grafo);
    if (possuiCiclo) {
        printf("O grafo possui ciclos.\n");
    } else {
        printf("O grafo não possui ciclos.\n");
    }

    calcularGrauEntrada(&grafo);
    calcularGrauSaida(&grafo);

    return 0;
}
