#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // calculating mid 

        // Check if x is present at mid
        if (arr[mid] == target)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;

        // If x is smaller, ignore right half
        else
            right = mid - 1;
    }

    // if we reach here, then element was not present
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarySearch(arr, 0, n - 1, target);
    // checking condition using ternary operator
    (result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", result);

    return 0;
}

