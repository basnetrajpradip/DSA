#include <stdio.h>

int gcd(int x, int y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}

int main() {
  int x, y;
  printf("Enter two numbers to find gcd: ");
  scanf("%d %d", &x, &y);
  printf("The gcd of %d and %d is %d\n", x, y, gcd(x, y));
}