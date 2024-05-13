#include <stdio.h>

/* Selection sort is called so as this algorithm wworks by selecting the
  minimun/maximum element for each index as required and placing it in that
 index until all indexes have it's correct element*/
void selectionSort(int arr[], int size) {
  int i, j, temp, min;

  for (i = 0; i < size - 1; i++) {
    // start by considering item at that index be the min itself.
    min = i;

    for (j = i + 1; j < size; j++) {
      // if the index is min than the considered min, replace min index.
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    // Select min element for the index and swap it's position.
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
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

  selectionSort(arr, size);
  printf("Sorted Array is: \n");
  printArray(arr, size);
}