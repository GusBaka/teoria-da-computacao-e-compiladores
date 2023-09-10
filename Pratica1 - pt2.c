#include <stdio.h>

int main() {
int ano;
int atual;
int future;

printf ("\nInforme seu ano de nascimento: ");
scanf ("%d", &ano);

atual = 2023 - ano;
future = 2050 - ano;


printf("%d\nSua idade atual é: ", atual);
printf("\n");
printf("%d\nSua idade em 2050 vai ser: ", future);

return 0;
}
