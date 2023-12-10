#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define OPERATION_SUCCEED 0
#define OPERATION_FAILED (-1)
#define NOT_FOUND (-1)

int search(const int* table, int size, int item) {
    int key = item % size;

    for (int i = key; i < size; i++) {
        if (table[i] == item) {
            return i;
        }

        if (i == size - 1 && key != 0) {
            i = -1;
        }

        if (i == key - 1) {
            break;
        }
    }

    return NOT_FOUND;
}

int insert(int* table, int size, int item) {
    int isItemInArray = search(table, size, item) != NOT_FOUND;
    if (isItemInArray) {
        return OPERATION_FAILED;
    }

    int key = item % size;
    for (int i = key; i < size; i++) {
        if (table[i] == -1) {
            table[i] = item;
            return OPERATION_SUCCEED;
        }

        if (i == size - 1 && key != 0) {
            i = -1;
        }

        if (i == key - 1) {
            break;
        }
    }

    return OPERATION_FAILED;
}

int delete(int* table, int size, int item) {
    int id = search(table, size, item);

    if (id == -1) {
        return NOT_FOUND;
    }

    table[id] = -1;
    return OPERATION_SUCCEED;
}

int main() {
    int tableSize;
    scanf("%d", &tableSize);

    int* table = malloc(tableSize * sizeof(int));
    memset(table, -1, tableSize * sizeof(int));

    int numberOfInsertions, item;
    scanf("%d", &numberOfInsertions);
    for (int i = 0; i < numberOfInsertions; i++) {
        scanf("%d", &item);

        insert(table, tableSize, item);
    }

    int numberOfDeletions;
    scanf("%d", &numberOfDeletions);
    for (int i = 0; i < numberOfDeletions; i++) {
        scanf("%d", &item);

        delete(table, tableSize, item);
    }

    int numberOfSearches;
    scanf("%d", &numberOfSearches);
    for (int i = 0; i < numberOfSearches; i++) {
        scanf("%d", &item);

        int result = search(table, tableSize, item);
        printf("%d ", result);
    }

    return 0;
}
