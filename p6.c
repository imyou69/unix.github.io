#include <stdio.h>
#include <time.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size, key, result;
    clock_t start, end;
    double cpu_time_used;

    // Input array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    // Input array elements
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the element to search for
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Start time
    start = clock();

    // Perform linear search
    result = linearSearch(arr, size, key);

    // End time
    end = clock();

    // Calculate time taken
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    printf("Time taken to execute the search: %f seconds\n", cpu_time_used);

    return 0;
}