#include <stdio.h>

int main() {
float peso;
float peso1;
float peso2;

printf ("\nQual seu peso? ");
scanf ("%e", &peso);


peso1 = peso * 1.15;
peso2 = peso * 1.20;

printf("%f\nSeu peso seria: ", peso1);
printf("%f\nSeu peso seria: ", peso2);

return 0;
}
