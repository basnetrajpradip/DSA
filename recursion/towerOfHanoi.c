#include <stdio.h>

void TOH(int n, char src_pole, char dest_pole, char temp_pole) {
  if (n == 1) {
    printf("Move disk 1 from %c to %c\n", src_pole, dest_pole);
  } else {
    TOH(n - 1, src_pole, temp_pole, dest_pole);
    printf("Move disk %d from %c to %c\n", n, src_pole, dest_pole);
    TOH(n - 1, temp_pole, dest_pole, src_pole);
  }
}

int main() {
  int n = 3;
  TOH(n, 'A', 'B', 'C');
}