#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at node i
void heapify(int arr[], int size, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // Left child
    int right = 2 * i + 2;    // Right child

    // If the left child is larger than root
    if (left < size && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than largest so far
    if (right < size && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, size, largest);
    }
}

// Main function to implement Heap Sort
void heapSort(int arr[], int size) {
    // Build the max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // Extract elements one by one from the heap
    for (int i = size - 1; i >= 0; i--) {
        // Move the current root to the end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    heapSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
