#include <stdio.h>
int fib(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else {
    return fib(n - 1) + fib(n - 2);
  }
}

int main(void) {
  printf("Enter the positive nth term: ");
  int n;
  scanf("%d", &n);
  printf("The fibonacci series upto %dth term is:\n ", n);
  for (int i = 0; i <= n; i++) {
    printf("%d\t", fib(i));
  }
  printf("\n");
}