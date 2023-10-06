#include <stdio.h>
#include <stdlib.h>

void shellSort(int array[], int size, int* operationsCount) {
    int gap = 1;
    while(gap <= size) {
        gap *= 2;
    }

    gap = gap / 2 - 1;
    while(gap > 0) {
        for (int i = gap; i < size; i++){
            int x = array[i];
            *operationsCount  = *operationsCount + 1;

            int j = i - gap;

            while(j >= 0 && array[j] > x) {
                *operationsCount  = *operationsCount + 1;

                array[j + gap] = array[j];
                *operationsCount = *operationsCount + 1;

                j -= gap;
            }

            if (j >= 0) {
                *operationsCount = *operationsCount + 1;
            }

            array[j + gap] = x;
            *operationsCount = *operationsCount + 1;
        }

        gap /= 2;
    }
}

void quickSort(int array[], int firstIndex, int lastIndex, int* operationsCount) {
    if (firstIndex >= lastIndex) {
        return;
    }

    int middle = (lastIndex + firstIndex) / 2;
    int pivot = array[middle];
    *operationsCount = *operationsCount + 1;
    int i = firstIndex;
    int j = lastIndex;

    for(;;) {
        while(array[i] < pivot) {
            *operationsCount = *operationsCount + 1;
            i++;
        }
        *operationsCount = *operationsCount + 1;

        while(array[j] > pivot) {
            *operationsCount = *operationsCount + 1;
            j--;
        }
        *operationsCount = *operationsCount + 1;

        if (i >= j) {
            break;
        }

        int aux = array[i];
        array[i] = array[j];
        array[j] = aux;
        *operationsCount = *operationsCount + 3;

        i++;
        j--;
    }

    quickSort(array, firstIndex, j, operationsCount);
    quickSort(array, j+1, lastIndex, operationsCount);
}

int main() {
    int size;
    scanf("%d", &size);

    int* array = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    int** subArrays = (int**) malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        subArrays[i] = (int*) malloc((i + 1) * sizeof(int));

        for (int j = 0; j < i+1; j++) {
            subArrays[i][j] = array[j];
        }
    }

    free(array);

    for (int i = 0; i < size; i++) {
        int shellOperationsCount = 0, quickOperationsCount = 0;
        int* shellSubArray = (int*) malloc((i + 1) * sizeof(int));
        int* quickSubArray = (int*) malloc((i + 1) * sizeof(int));
        for(int j = 0; j < i+1; j++) {
            shellSubArray[j] = subArrays[i][j];
            quickSubArray[j] = subArrays[i][j];
        }

        shellSort(shellSubArray, i+1, &shellOperationsCount);
        quickSort(quickSubArray, 0, i, &quickOperationsCount);

        if (shellOperationsCount == quickOperationsCount) {
            printf("-");
        } else if (shellOperationsCount < quickOperationsCount) {
            printf("S");
        } else {
            printf("Q");
        }

        free(shellSubArray);
        free(quickSubArray);
    }

    for (int i = 0; i < size; i++) {
        free(subArrays[i]);
    }
    free(subArrays);

    return 0;
}