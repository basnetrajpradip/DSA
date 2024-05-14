#include <stdio.h>
/* In this sorting algorithm, we insert elements into it's correct position for
 * that iteration. For every iteration we achieve a sub array within the array
 * such that it is sorted up until the iteration position. */
void insertionSort(int arr[], int size) {
  int i, j, temp;
  // We consider first element to be sorted. So start off at index 1.
  for (i = 1; i < size; i++) {
    temp = arr[i];
    j = i - 1;

    // In each iteration we look at the elements at the left of i and  compare
    // with the temp and if condition fulfills,swap it.
    while (j >= 0 && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j--; // iterate until the begining of the list
    }
    // finally place the temp value at it's correct position for that iteration
    arr[j + 1] = temp;
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

int main(void) {
  int arr[] = {4, 1, 2, 9, 3, 8, 7, 14, 6};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Input array is: \n");
  printArray(arr, size);

  insertionSort(arr, size);
  printf("Sorted Array is: \n");
  printArray(arr, size);
}