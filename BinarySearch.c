/*
    Binary Search only works on sorted dataset.
    Dataset: 
    10 length
    100 length 
    1000 length

    Objective: (Objective successfully not completed because I had to go shower!) 
    1. Search element using BinarySearch
    2. Compare the performance with linear search.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Utils.h"

// Returns index of the needle in array.
int binarySearch(int* arr, int arrSize, int needle) {
    int lo = 0;
    int hi = arrSize-1;
    int mid;

    while (lo<=hi) {

        mid = lo + ((hi-lo)/2);

        printf("lo: %d, mid: %d, hi: %d\n", lo, mid, hi);

        if (needle == arr[mid]) {
            return mid;
        } else if (needle < arr[mid]) {
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    return -1;

}

// Not going extreme by using this to poop in array.
// Also, this is generated by ChatJipity.
int generateRandomIntInRange(int min, int max) {
    // Seed the random number generator with current time
    srand(time(NULL));
    
    // Generate a random integer between min and max
    return min + rand() % (max - min + 1);
}

void poopOnEmptyArray(int* arr, int arrSize) {
    int startingNumber = -6;
    int skipNumber = 3;
    for (int i=0; i<arrSize; i++) {
        arr[i] = startingNumber;
        startingNumber += skipNumber;
    }
}

int main() {
    printf("Binary search says hello!\n");

    int arrSize = 10;
    int arr[arrSize];
    int needle = 18;

    poopOnEmptyArray(arr, arrSize);
    printArray(arr, arrSize);

    int needleIndex = binarySearch(arr, arrSize, needle);

    printf("Needle %d found at index %d\n", needle, needleIndex);

}