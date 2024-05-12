#include <stdio.h>

int fact(int n) {
  if (n == 1 || n == 0)
    return 1;
  else
    return n * fact(n - 1);
}

int main() {
  int n;
  printf("Enter the number: ");
  scanf("%d", &n);
  printf("The factorial of the given number is: %d\n", fact(n));
}