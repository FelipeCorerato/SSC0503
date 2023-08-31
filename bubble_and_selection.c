#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define IS_EQUAL 0

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int array[], int size) {
    int i = size - 1, lastSwappedIndex;
    while (i >= 1) {
        lastSwappedIndex = -1;

        for (int j = 0; j < i; j++) {
            printf("C %d %d\n", j, j + 1);
            if (array[j] > array[j + 1]) {
                printf("T %d %d\n", j, j + 1);
                swap(&array[j], &array[j + 1]);
                lastSwappedIndex = j;
            }
        }

        i = lastSwappedIndex;

        if (lastSwappedIndex == -1)
            break;
    }
}

void selectionSort(int array[], int size) {
    int minIndex;

    for (int i = 0; i < size-1; i++) {
        minIndex = i;
        for (int j = i+1; j < size; j++) {
            printf("C %d %d\n", minIndex, j);
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        if(minIndex != i) {
            printf("T %d %d\n", i, minIndex);
            swap(&array[minIndex], &array[i]);
        }
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

int main() {
    char sortMethod[100];
    scanf("%s", &sortMethod);

    int numberOfElements;
    scanf("%d", &numberOfElements);

    int* array = malloc(numberOfElements * sizeof (int));
    for (int i = 0; i < numberOfElements; i++) {
        scanf("%d", &array[i]);
    }

    if (strcmp(sortMethod, "selecao") == IS_EQUAL) {
        selectionSort(array, numberOfElements);
    } else if (strcmp(sortMethod, "bolha") == IS_EQUAL) {
        bubbleSort(array, numberOfElements);
    } else {
        return 1;
    }

    printArray(array, numberOfElements);

    return 0;
}
