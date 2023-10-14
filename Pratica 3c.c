#include <stdio.h>

int sucessor(int n) {
    return n + 1;
}

// Função que verifica se [n, m] pertence ao conjunto MQ
int pertenceMQ(int n, int m) {
    if (n == 0 && m == 1) {
        return 1; // [0, 1] pertence ao MQ
    } else if (n < m) {
        return pertenceMQ(n, sucessor(m)); // [n, s(m)] pertence ao MQ
    } else {
        return 0; // Caso contrário, [n, m] não pertence ao MQ
    }
}

void gerarMQ(int n, int m) {
    if (pertenceMQ(n, m)) {
        printf("[%d, %d] ", n, m);
        gerarMQ(n, sucessor(m)); // Gera os próximos elementos do MQ recursivamente
    }
}

int main() {
    int limite;
    printf("Informe o limite para gerar o conjunto MQ: ");
    scanf("%d", &limite);

    printf("Conjunto MQ gerado até [0, 1]: ");
    gerarMQ(0, 1);
    printf("\n");

    return 0;
}
