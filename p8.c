#include <stdio.h>
#include <time.h>

typedef struct {
    int id;
    char name[50];
} Student;

void merge(Student arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    Student L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i].id <= R[j].id) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(Student arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    clock_t start, end;
    
    printf("Enter number of students: ");
    scanf("%d", &n);
    Student students[n];
    
    printf("Enter student details (ID and Name):\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d ID: ", i + 1);
        scanf("%d", &students[i].id);
        printf("Student %d Name: ", i + 1);
        scanf("%s", students[i].name);
    }

    start = clock();
    mergeSort(students, 0, n - 1);
    end = clock();

    printf("Sorted student details by ID:\n");
    for (int i = 0; i < n; i++)
        printf("ID: %d, Name: %s\n", students[i].id, students[i].name);

    printf("Time taken to sort: %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    return 0;
}