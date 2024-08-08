#include <stdio.h>
#include <stdlib.h>

// Function to get the maximum value in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    int i;
    for ( i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Counting sort function for Radix Sort
void countingSort(int arr[], int n, int exp) {
    int output[n]; 
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] contains the actual
    // position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort function
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is the current digit number
    int exp;
	for ( exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int n;

    // Test Case 1
    printf("Test Case 1\n");
    printf("Enter number of songs: ");
    scanf("%d", &n);
    int arr1[n];
    printf("Enter Song Prices:\n");
    int i;
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    
    radixSort(arr1, n);
    
    printf("Sorted Song Prices:\n");
    
    for ( i = 0; i < n; i++) {
        printf("%d\n", arr1[i]);
    }

    // Test Case 2
    printf("\nTest Case 2\n");
    printf("Enter number of songs: ");
    scanf("%d", &n);
    int arr2[n];
    printf("Enter Song Prices:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }
    
    radixSort(arr2, n);
    
    printf("Sorted Song Prices:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", arr2[i]);
    }

    return 0;
}
