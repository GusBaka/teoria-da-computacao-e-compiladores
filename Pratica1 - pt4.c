#include <stdio.h>

int main() {
float sal;


printf ("\nQual seu sálario? ");
scanf ("%e", &sal);

sal = sal * 1.25;

printf("%e\nSeu novo salario é: ", sal);

return 0;
}
