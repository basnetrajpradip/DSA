#include <stdio.h>

void traingle(int n) {
  if (n <= 0)
    return;
  else
    traingle(n - 1);
  for (int i = 1; i <= n; i++) {
    printf("*\t");
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter the size of the traingle: ");
  scanf("%d", &n);
  traingle(n);
}
