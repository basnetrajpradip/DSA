#include <stdio.h>

int nthSum(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return n + nthSum(n - 1);
}

int main() {
  int n;
  printf("Enter the nth number: ");
  scanf("%d", &n);
  printf("The sum of first %d natural numbers is: %d\n", n, nthSum(n));
}