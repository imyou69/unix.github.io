#include <stdio.h>
#include <time.h>

// Structure to represent a student
typedef struct {
    int id;
    char name[50];
} Student;

// Function to heapify a subtree rooted with node i
void heapify(Student arr[], int n, int i) {
    int largest = i;   // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left].id > arr[largest].id)
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right].id > arr[largest].id)
        largest = right;

    // If largest is not root
    if (largest != i) {
        Student temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(Student arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        Student temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    clock_t start, end;

    // Input number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student students[n];

    // Input student details
    printf("Enter student details (ID and Name):\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d ID: ", i + 1);
        scanf("%d", &students[i].id);
        printf("Student %d Name: ", i + 1);
        scanf("%s", students[i].name);
    }

    // Start time
    start = clock();

    // Perform heap sort
    heapSort(students, n);

    // End time
    end = clock();

    // Calculate time taken
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print sorted student details
    printf("Sorted student details by ID:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s\n", students[i].id, students[i].name);
    }

    // Print time taken
    printf("Time taken to sort: %f seconds\n", time_taken);

    return 0;
}