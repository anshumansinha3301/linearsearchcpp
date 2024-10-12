#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the key is at mid
        if (arr[mid] == key)
            return mid;

        // If key is greater, ignore left half
        if (arr[mid] < key)
            left = mid + 1;

        // If key is smaller, ignore right half
        else
            right = mid - 1;
    }
    
    // Key is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int result = binarySearch(arr, size, key);
    
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array" << endl;

    return 0;
}
