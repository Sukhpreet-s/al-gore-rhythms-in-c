/**
Implement MinHead DS
- operations: insert, delete
*/

#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"

#define NIL 999999999

int parent(int idx, int size) {
   int pIdx = (currIdx-1)/2;

   if (pIdx < 0) {
        return -1;
   } else {
        return pIdx;
   }
}

int leftChild(int* arr, int idx, int size) {
    int lIdx = 2*idx + 1;

    if (lIdx > size-1) {
        return -1;
    } else {
        return lIdx;
    }
}

int rightChild(int* arr, int idx, int size) {
    int rIdx = 2*idx + 2;

    if (rIdx > size-1) {
        return -1;
    } else {
        return rIdx;
    }
}

void heapifyUp(int* arr, int* size) {

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

void heapifyDown(int* arr, int size) {
    int currIdx = 0;
    int lIdx, rIdx, currValue, lValue, rValue;

    while (lIdx<size || rIdx<size) {
        lIdx = leftChild(currIdx, size);
        rIdx = rightChild(currIdx, size);
        currValue = arr[currIdx];
        
        if (rIdx >= size) { // Right child does not exist. Only left exists
            lValue = arr[lIdx];
            if (currValue > lValue) {
                arr[currIdx] = lValue;
                arr[lIdx] = currValue;
                currIdx = lIdx;
            }
        } else { // both right and left child exists.
            lValue = arr[lIdx];
            rValue = arr[rIdx];

            if (lValue < rValue && (lValue < currValue)) {
                arr[currIdx] = lValue;
                arr[lIdx] = currValue;
                currIdx = lIdx;
            } else if (rValue < lValue && (rValue < currValue)) {
                arr[currIdx] = rValue;
                arr[rIdx] = currValue;
                currIdx = rIdx;
            }
        }
        
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

    heapifyUp(arr, size);
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

    heapifyDown(arr, size);

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