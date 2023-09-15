#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int size) {
    int key, j, swapCount = 0, comparisonCount = 0;

    for (int i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        swapCount++;

        while (j >= 0) {
            comparisonCount++;
            if (array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
                swapCount++;
            } else break;
        }

        array[j + 1] = key;
        swapCount++;
    }

    printf("I %d %d %d\n", size, swapCount, comparisonCount);
}

void merge(int array[], int firstSubArrayInitIndex, int firstSubArrayLastIndex, int secondSubArrayLastIndex, int* swapCount, int* comparisonCount) {
    int i, j, k;
    int firstSubArraySize = firstSubArrayLastIndex - firstSubArrayInitIndex + 1;
    int secondSubArraySize = secondSubArrayLastIndex - firstSubArrayLastIndex;

    int FirstSubArray[firstSubArraySize], SecondSubArray[secondSubArraySize];

    for (i = 0; i < firstSubArraySize; i++)
        FirstSubArray[i] = array[firstSubArrayInitIndex + i];
    for (j = 0; j < secondSubArraySize; j++)
        SecondSubArray[j] = array[firstSubArrayLastIndex + 1 + j];

    i = 0;
    j = 0;
    k = firstSubArrayInitIndex;
    while (i < firstSubArraySize && j < secondSubArraySize) {
        *comparisonCount = *comparisonCount + 1;

        if (FirstSubArray[i] <= SecondSubArray[j]) {
            array[k] = FirstSubArray[i];
            i++;
        } else {
            array[k] = SecondSubArray[j];
            j++;
        }

        *swapCount = *swapCount + 1;
        k++;
    }

    while (i < firstSubArraySize) {
        array[k] = FirstSubArray[i];
        *swapCount = *swapCount + 1;

        i++;
        k++;
    }

    while (j < secondSubArraySize) {
        array[k] = SecondSubArray[j];
        *swapCount = *swapCount + 1;

        j++;
        k++;
    }

    k = 0;
    for (int z = firstSubArrayInitIndex; z <= secondSubArrayLastIndex; z++, k++) {
        *swapCount = *swapCount + 1;
        SecondSubArray[z] = array[z];
    }
}

void mergeSort(int array[], int initIndex, int endIndex, int* swapCount, int* comparisonCount) {
    if (initIndex < endIndex) {
        int middle = initIndex + (endIndex - initIndex) / 2;

        mergeSort(array, initIndex, middle, swapCount, comparisonCount);
        mergeSort(array, middle + 1, endIndex, swapCount, comparisonCount);

        merge(array, initIndex, middle, endIndex, swapCount, comparisonCount);
    }
}

int main() {
    int numberOfArrays;
    scanf("%d", &numberOfArrays);

    int* sizesOfArrays = (int*) malloc(numberOfArrays * sizeof(int));
    int** arrays = (int**) malloc(numberOfArrays * sizeof(int*));

    for (int i = 0; i < numberOfArrays; i++) {
        scanf("%d", &sizesOfArrays[i]);
        arrays[i] = (int*) malloc(sizesOfArrays[i] * sizeof(int));
    }

    for(int i = 0; i < numberOfArrays; i++) {
        for(int j = 0; j < sizesOfArrays[i]; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }

    for(int i = 0; i < numberOfArrays; i++) {
        int* arrayCopy = (int*) malloc(sizesOfArrays[i] * sizeof(int));
        for(int j = 0; j < sizesOfArrays[i]; j++) {
            arrayCopy[j] = arrays[i][j];
        }

        insertionSort(arrays[i], sizesOfArrays[i]);

        int mergeSwapCount = 0, mergeComparisonCount = 0;
        mergeSort(arrayCopy, 0, sizesOfArrays[i] - 1, &mergeSwapCount, &mergeComparisonCount);
        printf("M %d %d %d\n", sizesOfArrays[i], mergeSwapCount, mergeComparisonCount);
    }

    return 0;
}