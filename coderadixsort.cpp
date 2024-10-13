#include <iostream>
using namespace std;

// Function to get the maximum value in an array
int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];  
    return max;
}

// Function to do counting sort of arr[] according to the digit represented by exp (exponent)
void countingSort(int arr[], int size, int exp) {
    int output[size]; // Output array
    int count[10] = {0};

    // Store the count of occurrences in count[]
    for (int i = 0; i < size; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that it contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to the current digit
    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

// Main function to implement Radix Sort
void radixSort(int arr[], int size) {
    // Find the maximum number to determine the number of digits
    int max = getMax(arr, size);

    // Do counting sort for every digit. Note that exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, size, exp);
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    radixSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
