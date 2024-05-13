#include <stdio.h>

/*  It is called bubble sort as just like bubbles in water, each element of the
 array bubbles towards it's correct position(towards the end) in each
 iteration */
void bubbleSort(int arr[], int size) {
  int temp, i, j;
  // loop to access elements of array
  for (i = 0; i < size - 1; i++) {
    // loop to compare array elements
    for (j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
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

  bubbleSort(arr, size);
  printf("Sorted Array is: \n");
  printArray(arr, size);
}