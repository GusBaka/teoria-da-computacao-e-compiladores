#include <stdio.h>

int main() {
int x;
int y;
int z;
int result;

printf ("\nInforme um numero: ");
scanf ("%d", &x);

printf ("\nInforme um numero: ");
scanf ("%d", &y);

printf ("\nInforme um numero: ");
scanf ("%d", &z);

result = (x + y + z) / 3;

printf("%d\n", result);

return 0;
}
