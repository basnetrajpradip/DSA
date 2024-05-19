#include <stdio.h>

/* Shell sort is the generalization/optimization of insertion sort which
 * overcomes the drawback of insertion sort by comparing elements separated by
 * gap of several positions. */

void shellSort(int arr[], int size) {
  int i, j, gap, temp;
  // Start off with biggest gap of n/2 and decrease gap by dividing by 2.
  for (gap = size / 2; gap >= 1; gap /= 2) {
    // This loop tracks elements of right of gap until the end.
    for (i = gap; i < size; i++) {
      // This loop tracks elements from start to left of the gap.
      for (j = i - gap; j >= 0; j -= gap) {
        if (arr[j] > arr[j + gap]) {
          temp = arr[j];
          arr[j] = arr[j + gap];
          arr[j + gap] = temp;
        } else {
          break;
        }
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

  shellSort(arr, size);
  printf("Sorted Array is: \n");
  printArray(arr, size);
}