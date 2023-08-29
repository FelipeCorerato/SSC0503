#include <stdio.h>
#include <stdlib.h>

double calculateIMC(double height, double weight) {
    return weight / (height * height);
}

int calculateSeconds(int h, int m, int s) {
    return 3600 * h + 60 * m + s;
}

void calculateTimer(int h1, int m1, int s1, int h2, int m2, int s2) {
    int totalInSeconds = 3600 * (h1+h2) + 60 * (m1+m2) + s1+s2;
    int secondsRemaining = totalInSeconds;

    int hours = totalInSeconds / 3600;
    secondsRemaining -= (3600 * hours);

    int minutes = secondsRemaining / 60;
    secondsRemaining -= (60 * minutes);

    char ret[9];
    sprintf(ret, "%02d:%02d:%02d", hours % 24, minutes, secondsRemaining);

    printf("%s", ret);
}

double lbsToKgs(double lbs) {
    if (lbs < 0) {
        printf("%s", "Invalid lbs value");
        return 0;
    }

    return lbs / 2.2;
}

char* analyseIMC(double height, double weight) {
    double imc = calculateIMC(height, weight);

    if (imc < 18.5)
        return "Lean";

    if (imc >= 18.5 && imc < 25)
        return "Ideal";

    if (imc >= 25 && imc < 30)
        return "Average";

    if (imc >= 30)
        return "Above average";

    return "Invalid params";
}

double calculateTax(double wage) {
    if (wage >= 1499.16 && wage <= 3743.19)
        return wage * 7.5 / 100;

    if (wage >= 3743.20)
        return wage * 27.5 / 100;

    return 0;
}

int getGreatest(int a, int b) {
    return a > b ? a : b;
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int array[], int n) {
    int i, j, minIdx;

    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++)
            if (array[j] < array[minIdx])
                minIdx = j;

        swap(&array[minIdx], &array[i]);
    }
}

int getLowest(int a, int b, int c) {
    int array[] = {a, b, c};
    selectionSort(array, 3);

    return array[0];
}

int getGreatestUsingArray(int a, int b) {
    int array[] = {a, b, };
    selectionSort(array, 2);

    return array[1];
}

char* intToString(int i) {
    int length = snprintf(NULL, 0, "%d", i);
    char intString[length];
    sprintf(intString, "%d", i);

    return intString;
}

 void analyseDivisibilityByThreeAndFive(int number) {
    int lengthOfNumber = snprintf(NULL, 0, "%d", number);
    char numberString[lengthOfNumber];
    sprintf(numberString, "%d", number);

    if(number % 3 == 0) {
        if (number % 5 == 0) {
            printf("PirlimPimpim");
        } else {
            printf("Pirlim");
        }
    } else if (number % 5 == 0) {
        printf("Pimpim");
    } else {
        printf("%s", numberString);
    }
}

const float defaultAmount = 50;

int extraExercise() {
    int consumption;
    double totalAmount, variableFee;

    scanf("%d", &consumption);

    if (consumption < 500) {
        if (consumption < 250) {
            variableFee = consumption < 100 ? 0.5 : 0.75;
        } else {
            variableFee = 1;
        }
    } else {
        variableFee = 1.25;
    }

    totalAmount = defaultAmount + variableFee * consumption;
    printf("%.2f", totalAmount);

    return 0;
}

int main() {
    printf("Calculate IMC: ");
    printf("%.2f", calculateIMC(1.72, 80.4));
    printf("\n");
    printf("\n");

    printf("Calculate seconds from time: ");
    printf("%d", calculateSeconds(23, 59, 59));
    printf("\n");
    printf("\n");

    printf("Adding time: ");
    // It's 00:59:59 and i'm adding 04:10:10
    calculateTimer(0, 59, 59, 4, 10, 10);
    printf("\n");
    printf("\n");

    printf("Convert pounds to kilograms: ");
    printf("%.2fKg", lbsToKgs(2.2));
    printf("\n");
    printf("\n");

    printf("Analyse IMC: ");
    printf("%s", analyseIMC(1.75, 60));
    printf("\n");
    printf("\n");

    printf("Calculate tax: ");
    printf("R$ %.2f", calculateTax(3743.20));
    printf("\n");
    printf("\n");

    printf("Get greatest number: ");
    printf("%d", getGreatest(4, 2));
    printf("\n");
    printf("\n");

    printf("Ascending sort list of three numbers: ");
    int array[] = {3, 1, 8};
    selectionSort(array, 3);
    printArray(array, 3);
    printf("\n");
    printf("\n");

    printf("Get lowest number: ");
    printf("%d", getLowest(4,5,3));
    printf("\n");
    printf("\n");

    printf("Get greatest number (using array): ");
    printf("%d", getGreatestUsingArray(4, 1));
    printf("\n");
    printf("\n");

    analyseDivisibilityByThreeAndFive(33);
    printf("\n");
    analyseDivisibilityByThreeAndFive(30);
    printf("\n");
    analyseDivisibilityByThreeAndFive(35);
    printf("\n");
    analyseDivisibilityByThreeAndFive(37);
    printf("\n");

    printf("Digite 15 valores \n");
    int *arr = malloc(15 * sizeof(int));

    for (int i = 0; i < 15; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array: ");
    printArray(arr, 15);
    printf("\n");

    selectionSort(arr, 15);

    printf("Sorted array: ");
    printArray(arr, 15);
    printf("\n");

    printf("Output: ");
    for (int i = 0; i < 14; i++) {
        if (arr[i] == arr[i+1] && arr[i] != arr[i-1]) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
