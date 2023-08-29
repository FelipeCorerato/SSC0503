#include <stdio.h>

int main() {
    int numberOfElements;
    scanf("%d", &numberOfElements);

    int lowestIndex = 0, lowestValue, actual;
    scanf("%d", &lowestValue);

    for (int i = 1; i < numberOfElements; i++) {
        scanf("%d", &actual);

        if (lowestValue > actual) {
            lowestValue = actual;
            lowestIndex = i;
        }
    }

    printf("%d", lowestIndex);

    return 0;
}