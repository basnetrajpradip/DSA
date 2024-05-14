#include <stdio.h>

/* Merge sort is also a divide and conquer algorithm which basically divides
 * array into sub arrays until there is only one element per array and compare
 * them, sort them and group them into an array*
 *
 * run time complexity: O(n log n)
 * space complexity: O(n)
 * /

/* This is a helper function to merge two subarrays into an array by comparing
 * them and placing them in correct position in array. */
void merge(int leftArr[], int leftSize, int rightArr[], int rightSize,
           int arr[]) {
  int l = 0, r = 0, i = 0; // indices for the arrays

  // while both left array and right array elements aren't filled to array,
  // compare and fill them.
  while (l < leftSize && r < rightSize) {
    if (leftArr[l] < rightArr[r]) {
      arr[i] = leftArr[l];
      i++;
      l++;
    } else {
      arr[i] = rightArr[r];
      i++;
      r++;
    }
  }
  // While right array elements are filled already.
  while (l < leftSize) {
    arr[i] = leftArr[l];
    i++;
    l++;
  }

  // while left array elements are filled already.
  while (r < rightSize) {
    arr[i] = rightArr[r];
    i++;
    r++;
  }
}

void mergeSort(int arr[], int size) {
  if (size <= 1) {
    return;
  }

  int middle = size / 2;
  int leftArr[middle];
  int rightArr[size - middle];

  int i = 0, j = 0;

  for (; i < size; i++) {
    if (i < middle) {
      leftArr[i] = arr[i];
    } else {
      rightArr[j] = arr[i];
      j++;
    }
  }

  mergeSort(leftArr, middle);
  mergeSort(rightArr, size - middle);
  merge(leftArr, middle, rightArr, size - middle, arr);
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

  mergeSort(arr, size);
  printf("Sorted Array is: \n");
  printArray(arr, size);
}