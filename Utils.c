#include <stdio.h>
#include "Utils.h"

void printArray(int* arr, int arrSize) {
    printf("Pooping here: ");
    for(int i=0; i<arrSize; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}