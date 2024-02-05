/*
Lets do some sorting. 
Start with QuickSort
*/ 
#include <stdio.h>
#include "Utils.h"

/*
Weakly sorts the array around chosen pivot index (in this case, we chose hi to make it simple)
Note about weakly sort: it is fancy since if arr[i] > pivot we don't swap, but it arr[i] < pivot, we swap the lower with most recent number that is higher than pivot to array low numbers in one side and highs in one. 
Returns the index where the pivot ends up being after weakly sorting the array.
Future me comment here if something doesn't make sense:
*/
int partition(int* arr, int lo, int hi) {
    int pivot = arr[hi];
    int finalPivotIdx = lo - 1; // Accounts for sub array not starting at one.

    for (int i=lo; i<hi; i++) {
        if (arr[i] <= pivot) {
            finalPivotIdx++;
            int tmp = arr[i];
            arr[i] = arr[finalPivotIdx];
            arr[finalPivotIdx] = tmp;
        }
    }

    finalPivotIdx++;
    arr[hi] = arr[finalPivotIdx];
    arr[finalPivotIdx] = pivot;

    return finalPivotIdx;
}

/* The recurse lord function*/
void qs(int* arr, int lo, int hi, int arrSize) {
    // Recursion base case
    if (lo>=hi) {
        return; // The sub array has no remaining elements to weakly sort, i.e., the arr is sorted.
    }

    int pivotIdx = partition(arr, lo, hi);

    // printArray(arr, arrSize);

    // Left partitioning
    qs(arr, lo, pivotIdx-1, arrSize);
    // Right partitioning
    qs(arr, pivotIdx+1, hi, arrSize);

    return;
}

/* Function to initiate the quicksort recursion */
void quicksort(int* arr, int arrSize) {
    qs(arr, 0, arrSize-1, arrSize);
}

int main() {
    printf("Hello from QuickSort!\n");

    int arr[] = {1, 5, 10, 8, 11, 4, 2, 9, 3, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printf("Intial: ");
    printArray(arr, arrSize);

    quicksort(arr, arrSize);

    printf("Final: ");
    printArray(arr, arrSize);
}