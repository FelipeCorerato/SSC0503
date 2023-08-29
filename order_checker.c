#include <stdio.h>

int main() {
    int numberOfElements;
    scanf("%d", &numberOfElements);

    int previous, actual;
    scanf("%d", &previous);

    int canBeAscendant = 1, canBeDescendent = 1, canBeAllTheSame = 1;

    if (numberOfElements <= 2) {
        for (int i = 1; i < numberOfElements; i++) {
            scanf("%d", &actual);

            if (canBeAscendant == 1 && previous > actual) {
                canBeAscendant = 0;
            }

            if (canBeDescendent == 1 && previous < actual) {
                canBeDescendent = 0;
            }

            if (canBeAllTheSame == 1 && previous != actual) {
                canBeAllTheSame = 0;
            }
        }
    } else {
        int mostPrevious = previous;
        scanf("%d", &previous);

        for (int i = 2; i < numberOfElements; i++) {
            scanf("%d", &actual);

            if (canBeAscendant == 1 && (mostPrevious > previous || mostPrevious > actual || previous > actual)) {
                canBeAscendant = 0;
            }

            if (canBeDescendent == 1 && (mostPrevious < previous || mostPrevious < actual || previous < actual)) {
                canBeDescendent = 0;
            }

            if (canBeAllTheSame == 1 && previous != actual) {
                canBeAllTheSame = 0;
            }

            mostPrevious = previous;
            previous = actual;
        }
    }

    if (canBeAllTheSame == 1 || canBeAscendant == 1) {
        printf("1");
    } else if (canBeDescendent == 1) {
        printf("-1");
    } else {
        printf("0");
    }

    return 0;
}