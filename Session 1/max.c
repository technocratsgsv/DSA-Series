#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a[10] = {0}; // Initialize array of size 10 with all zeros

    // Seed the random number generator with current time
    srand(time(0));

    // Generate and store 10 random numbers between 1 and 100
    for (int i = 0; i < 10; i++) {
        int num = 1 + rand() % 100;
        a[i] = num;
    }

    // Print the generated random numbers
    printf("Generated Random Numbers:\n");
    for (int i = 0; i < 10; i++) {
        printf("a[%d]: %d\n", i, a[i]);
    }

    // Initialize max and min with the first element
    int max = a[0];
    int min = a[0];

    // Find max and min values in the array
    for (int i = 1; i < 10; i++) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }

    // Print the maximum and minimum
    printf("\nMax: %d\nMin: %d\n", max, min);

    return 0;
}
