#include <stdio.h>

int main() {
    // Declaring and initializing an array
    // Syntax: data_type name[size] = {a1, a2, a3, ...}
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    // Accessing and printing elements of arr[]
    printf("Predefined array elements:\n");
    for(int i = 0; i < 10; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Declaring another array to take user input
    int a[3];

    // Taking input from the user for array a[]
    printf("\nEnter 3 integers:\n");
    for (int i = 0; i < 3; i++) {
        printf("Enter a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    // Displaying the user-input array elements
    printf("\nYou entered:\n");
    for (int i = 0; i < 3; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
