#include <stdio.h>

int main() {
int diagMen;
int diagMai;
int result;


printf ("\nQual o tamanho das diagonais menores? ");
scanf ("%d", &diagMen);

printf ("\nQual o tamanho das diagonais maiores? ");
scanf ("%d", &diagMen);

diagMen = diagMen * 2;
diagMai = diagMai * 2;

result = (diagMen * diagMai) / 2;

printf("%d\nAréa é: ", result);

return 0;
}
