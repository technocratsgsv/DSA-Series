#include <stdio.h>

int main() {
    int a[10] = {1, 2, 3, 4, 5}; // Initial array
    int size = 5;               // Current size of array

    printf("Original array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");

    // Case 1: Deletion from End
    if (size > 0) {
        size--; // Just reduce size by 1
        printf("After deleting from end: ");
        for (int i = 0; i < size; i++)
            printf("%d ", a[i]);
        printf("\n");
    }

    // Case 2: Deletion from Middle (delete index 1)
    int midIndex = 1;
    if (midIndex >= 0 && midIndex < size) {
        // Shift elements to the left from midIndex
        for (int i = midIndex; i < size - 1; i++)
            a[i] = a[i + 1];
        size--;
        printf("After deleting element at index %d: ", midIndex);
        for (int i = 0; i < size; i++)
            printf("%d ", a[i]);
        printf("\n");
    }

    // Case 3: Deletion from Beginning
    if (size > 0) {
        // Shift elements to the left
        for (int i = 0; i < size - 1; i++)
            a[i] = a[i + 1];
        size--;
        printf("After deleting from beginning: ");
        for (int i = 0; i < size; i++)
            printf("%d ", a[i]);
        printf("\n");
    }

    return 0;
}
