#include <stdio.h>

int sucessor(int n) {
    return n + 1;
}

// Função para verificar se [n, m] pertence ao conjunto MQ
int pertenceMQ(int n, int m) {
    while (n < m) {
        m = sucessor(m);
    }
    return n == m;
}

int main() {
    int limite;
    printf("Informe o limite para gerar o conjunto MQ: ");
    scanf("%d", &limite);

    printf("Conjunto MQ gerado até [0, 1]: ");
    for (int n = 0; n <= limite; n++) {
        for (int m = n + 1; m <= limite; m++) {
            if (pertenceMQ(n, m)) {
                printf("[%d, %d] ", n, m);
            }
        }
    }
    printf("\n");

    return 0;
}
