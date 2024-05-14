#include <stdio.h>

/* Quick sort is a divide and conquer algorithm in which the array is divied
 * into smaller subarrays with the help of partition which moves smaller
 * elements to the left of pivot and recursively divides array in two
 * partitions.

  run-time complexity :
    Best case O(n log(n))
    Average case O(n log(n))
    Worst case O(n^2) (if already sorted one partition contains n-1 elements and
                       other contains no element)
space complexity O(log(n)) due to recursion */

// This is a helper function of quickSort that arranges the elements to the left
// of pivot to be smaller than the right of pivot and returns pivot index.
int partition(int arr[], int start, int end) {
  int pivot = arr[end];

  int i = start - 1, temp;

  for (int j = start; j <= end; j++) {
    if (arr[j] < pivot) {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  i++;
  temp = arr[i];
  arr[i] = arr[end];
  arr[end] = temp;

  return i; // Here i is the pivot index.
}

void quickSort(int arr[], int start, int end) {
  if (end <= start) {
    return;
  }
  int pivot = partition(arr, start, end);
  quickSort(arr, start, pivot - 1);
  quickSort(arr, pivot + 1, end);
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

  quickSort(arr, 0, size - 1);
  printf("Sorted Array is: \n");
  printArray(arr, size);
}