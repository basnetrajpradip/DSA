#include <stdio.h>

/* Linear/Sequential Search works by interating over each element and comparing
 * it with the target element.
 * Time Complexity: O(n)
 */

int linearSearch(int arr[], int key, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -99;
}

int main(void) {
  int arr[] = {1, 3, 8, 18, 38, 48, 58, 73, 87, 98, 134, 188};
  int size = sizeof(arr) / sizeof(arr[0]);
  int flag = linearSearch(arr, 98, size);
  if (flag == -99) {
    printf("Search Unsuccessful\n");
  } else {
    printf("Element Found at location %d\n", flag + 1);
  }
}