#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i;
    
    // Ask user for the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Declare array
    int arr[n];

    // Seed random number generator
    srand(time(0));

    // Generate and print array
    printf("Generated array: ");
    for(i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random number between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Initialize largest and second largest
    int largest, second;

    if(arr[0] > arr[1]) {
        largest = arr[0];
        second = arr[1];
    } else {
        largest = arr[1];
        second = arr[0];
    }

    // Find second largest
    for(i = 2; i < n; i++) {
        if(arr[i] > largest) {
            second = largest;
            largest = arr[i];
        } else if(arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }

    // Handle edge case
    if(largest == second) {
        printf("All elements are equal or no distinct second largest.\n");
    } else {
        printf("Second largest number is: %d\n", second);
    }

    return 0;
}
