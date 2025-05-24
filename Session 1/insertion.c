#include <stdio.h>

int main() {
    int a[10] = {1, 2, 3}; // Initial array
    int size = 3;          // Current size of array

    printf("Original array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");

    // Case 1: Insertion at End
    int endValue = 4;
    if (size < 10) {
        a[size] = endValue;
        size++;
        printf("After inserting %d at end: ", endValue);
        for (int i = 0; i < size; i++)
            printf("%d ", a[i]);
        printf("\n");
    }

    // Case 2: Insertion in Middle (insert 10 at index 2)
    int midIndex = 2;
    int midValue = 10;
    if (size < 10 && midIndex >= 0 && midIndex <= size) {
        // Shift elements to the right
        for (int i = size; i > midIndex; i--)
            a[i] = a[i - 1];
        a[midIndex] = midValue;
        size++;
        printf("After inserting %d at index %d: ", midValue, midIndex);
        for (int i = 0; i < size; i++)
            printf("%d ", a[i]);
        printf("\n");
    }

    // Case 3: Insertion at Beginning (insert 0 at index 0)
    int beginValue = 0;
    if (size < 10) {
        // Shift all elements to the right
        for (int i = size; i > 0; i--)
            a[i] = a[i - 1];
        a[0] = beginValue;
        size++;
        printf("After inserting %d at beginning: ", beginValue);
        for (int i = 0; i < size; i++)
            printf("%d ", a[i]);
        printf("\n");
    }

    return 0;
}
