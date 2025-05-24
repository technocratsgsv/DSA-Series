#include <stdio.h>

int main() {
    // Declare and initialize an array of size 5 with 0
    int arr[5] = {0};

    // Take input for each element
    for (int i = 0; i < 5; i++) {
        printf("Enter arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Calculate the sum of array elements
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }

    // Calculate average (typecast to float to avoid integer division)
    float avg = (float)sum / 5;

    // Print the average with 2 decimal precision
    printf("Average = %.2f\n", avg);

    return 0;
}
