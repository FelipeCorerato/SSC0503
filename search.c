#include <stdio.h>
#include <stdlib.h>

void sort(int* array, int firstIndex, int lastIndex) {
    if (firstIndex >= lastIndex) {
        return;
    }

    int middle = (lastIndex + firstIndex) / 2;
    int pivot = array[middle];
    int i = firstIndex;
    int j = lastIndex;

    for(;;) {
        while(array[i] < pivot) {
            i++;
        }

        while(array[j] > pivot) {
            j--;
        }

        if (i >= j) {
            break;
        }

        int aux = array[i];
        array[i] = array[j];
        array[j] = aux;

        i++;
        j--;
    }

    sort(array, firstIndex, j);
    sort(array, j+1, lastIndex);
}

int binarySearch(int array[], int end, int search) {
    int start = 0;

    while (start <= end) {
        int middle = start + (end - start) / 2;

        if (array[middle] == search) {
            return 1;
        }

        if (array[middle] < search) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }

    return 0;
}

int main() {
    int numberOfElements;
    scanf("%d", &numberOfElements);

    int* array = malloc(numberOfElements * sizeof (int));
    for (int i = 0; i < numberOfElements; i++) {
        scanf("%d", &array[i]);
    }

    sort(array, 0, numberOfElements-1);

    int numberOfSearches;
    scanf("%d", &numberOfSearches);

    int search;
    for (int i = 0; i < numberOfSearches; i++) {
        scanf("%d", &search);

        int found = binarySearch(array, numberOfElements-1, search);
        printf("%d\n", found);
    }

    free(array);

    return 0;
}