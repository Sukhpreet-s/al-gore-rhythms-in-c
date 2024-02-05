#include <stdio.h>

void printArray(int* arr, int arrSize) {
    printf("Pooping here: ");
    for(int i=0; i<arrSize; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void bubblesort(int arr[], int arrSize) {

    for (int j=0; j<arrSize-1; j++) { // need to run sort len-1 times: 0-8 if len==10.

        for (int i=0; i<(arrSize-1-j); i++) {
            if (arr[i] > arr[i+1]) {
                int tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
            }
        }
    }
}

int main() {
    printf("Hewwo from BubbleSort!\n");

    int arr[] = {12, 5, 10, 8, 11, 4, 2, 9, 3, 7};
    int arrSize = 10;

    printArray(arr, arrSize);
    bubblesort(arr, arrSize);
    printArray(arr, arrSize);

}