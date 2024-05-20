#include <stdio.h>

/* It works by dividing array in half and comparing either the element is in
 * left, right  or middle of the array until it finds the element in the
 * middle.
 * Time Complexity: O(log n)
 * Space Complexity:
 *       Recursive implementation: O(log n)
 *       Iterative implementation: O(1)
 */

int binarySearchRecursive(int arr[], int key, int left, int right) {
  int middle = (left + right) / 2;

  if (left <= right) {
    if (arr[middle] == key) {
      return middle;
    } else if (key < arr[middle]) {
      return binarySearchRecursive(arr, key, left, middle - 1);
    } else {
      return binarySearchRecursive(arr, key, middle + 1, right);
    }
  } else {
    return -99;
  }
}

int binarySearchIterative(int arr[], int key, int left, int right) {
  while (left <= right) {
    int middle = left + (right - left) / 2;
    int value = arr[middle];

    if (key > value) {
      left = middle + 1;
    } else if (key < value) {
      right = middle - 1;
    } else
      return middle;
  }
  return -99;
}

int main(void) {
  int arr[] = {1, 3, 8, 18, 38, 48, 58, 73, 87, 98, 134, 188};
  int size = sizeof(arr) / sizeof(arr[0]);
  int flag = binarySearchRecursive(arr, 98, 0, size - 1);
  if (flag == -99) {
    printf("Search Unsuccessful\n");
  } else {
    printf("Element Found at location %d\n", flag + 1);
  }
}