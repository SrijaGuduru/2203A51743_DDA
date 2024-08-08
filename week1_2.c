#include <stdio.h>

// Function to get the maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    int i;
    for ( i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Function to perform counting sort based on the digit represented by exp
void countingSort(int arr[], int n, int exp) {
    int output[n]; // output array
    int count[10] = {0};

    // Store count of occurrences in count[]
    int i;
	for ( i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains the actual position of this digit in output[]
    
	for ( i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to sort an array using Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int max = getMax(arr, n);

    // Do counting sort for every digit. Note that exp is 10^i where i is the current digit number
    int exp;
	for ( exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// Function to print the array
void printArray(int arr[], int n) {
	int i;
    for ( i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(",");
    }
    printf("\n");
}

int main() {
    int products1[] = {87, 67, 21, 59, 99, 46, 84, 32, 43, 12, 90, 23};
    int n1 = sizeof(products1) / sizeof(products1[0]);
    
    printf("Input Product IDs for Test Case 1:\n");
    printArray(products1, n1);

    radixSort(products1, n1);

    printf("After Sorting Product IDs for Test Case 1:\n");
    printArray(products1, n1);
    printf("\n");

    int products2[] = {64, 56, 21, 90, 32, 87, 59, 60, 43, 10, 29, 74};
    int n2 = sizeof(products2) / sizeof(products2[0]);
    
    printf("Input Product IDs for Test Case 2:\n");
    printArray(products2, n2);

    radixSort(products2, n2);

    printf("After Sorting Product IDs for Test Case 2:\n");
    printArray(products2, n2);
    printf("\n");

    return 0;
}

