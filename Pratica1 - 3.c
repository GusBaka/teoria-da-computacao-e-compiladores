#include <stdio.h>

int main() {
float cot;
float dol;
float real;

printf ("\nQuanto vale 1 Dólar? ");
scanf ("%e", &cot);

printf ("\nQuantos Dólares você tem? ");
scanf ("%e", &dol);

real = dol * cot;

printf("%e\nIsso vale: ", real);

return 0;
}
