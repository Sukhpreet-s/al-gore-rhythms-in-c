/**
Implement Head DS
- operations: insert, delete
*/

#include <stdio.h>
#include <stdlib.h>

#define NIL 999999999

void printArray(int arr[], int arrSize) {
    printf("Pooping here: ");
    for(int i=0; i<arrSize; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void heapify(int* arr, int* size) {

    int currIdx = *size - 1;
    int parentIdx = (currIdx-1)/2;
    
    // Swap with parent until self smallar than parent or if already at the root.
    while ((arr[currIdx] < arr[parentIdx]) && (currIdx > 0 && parentIdx >= 0)) {
        int tmp = arr[parentIdx];
        arr[parentIdx] = arr[currIdx];
        arr[currIdx] = tmp;

        currIdx = parentIdx;
        parentIdx = (currIdx-1)/2;
    }

}

void insert(int* arr, int value, int* size, int capacity) {
    // Check if place is available to insert in array.
    if (*size == capacity) {
        printf("No more space available in array!\n");
        return;
    }

    // Insert at the last spot
    arr[*size] = value;

    *size = *size + 1;

    heapify(arr, size);
}

int getMin(int* arr, int* size) {
    if (*size == 0) {
        printf("Empty head!");
        return NIL;
    }

    int min = arr[0];
    arr[0] = arr[*size - 1];
    arr[*size - 1] = NIL;
    *size = *size - 1;

    heapify(arr, size);

    return min;
}

int main() {
    printf("Hello from the head!\n");

    int size = 0;
    int capacity = 10;
    int arr[capacity];

    // Initialize empty array with 0 values
    for (int i=0; i<capacity; i++) {
        arr[i] = NIL;
    }

    printArray(arr, size);

    insert(arr, 4, &size, capacity);
    printArray(arr, size);

    insert(arr, 10, &size, capacity);
    printArray(arr, size);

    int min = getMin(arr, &size);
    printf("Min: %d\n", min);
    printArray(arr, size);
}