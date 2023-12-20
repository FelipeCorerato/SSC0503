#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 200

int min(int a, int b) {
    return (a < b) ? a : b;
}

int isSubstring(char* string, char* substring) {
    return strstr(string, substring) ? 1 : 0;
}

char* substring(char* string, int size) {
    char* result = (char*) malloc((strlen(string) + 1) * sizeof(char));

    if (size <= strlen(string)) {
        strcpy(result, string);
        result[size] = '\0';
    }

    return result;
}

int getOverlap(char* string1, char* string2) {
    int size1 = strlen(string1), size2 = strlen(string2);
    if (size2 <= size1 && isSubstring(string1, string2)) {
        return size2;
    }

    int max = -1, smallestSize = min(size1, size2);
    for (int i = 1; i <= smallestSize; i++) {
        char* subStr = substring(string2, i);
        max = (strcmp(&string1[size1 - i], subStr) == 0 && max < i) ? i : max;
    }

    return max;
}

int** createOverlapsMatrix(char** reads, int numberOfReads) {
    int** overlapsMatrix = (int**) malloc(numberOfReads * sizeof(int*));

    for (int i = 0; i < numberOfReads; i++) {
        overlapsMatrix[i] = (int*) malloc(numberOfReads * sizeof(int));
        memset(overlapsMatrix[i], -1, numberOfReads * sizeof(int));
    }

    for (int i = 0; i < numberOfReads; i++) {
        for (int j = 0; j < numberOfReads; j++) {
            if (i != j) {
                overlapsMatrix[i][j] = getOverlap(reads[i], reads[j]);
            }
        }
    }

    return overlapsMatrix;
}

char** getCombinations(char** reads, int numberOfReads) {
    int** overlapsMatrix = createOverlapsMatrix(reads, numberOfReads);
    int str1Index = 0, str2Index = 1, max = -1;

    for (int i = 0; i < numberOfReads; i++) {
        for (int j = 0; j < numberOfReads; j++) {
            if (max < overlapsMatrix[i][j]) {
                max = overlapsMatrix[i][j];
                str1Index = i;
                str2Index = j;
            }
        }
    }

    size_t finalStringSize = (max > -1) ?
            strlen(reads[str1Index]) + strlen(&reads[str2Index][max]) + 1 :
            strlen(reads[str1Index]) + strlen(reads[str2Index]) + 1;
    char* finalString = (char*) malloc(finalStringSize * sizeof(char));

    finalString[0] = '\0';
    finalString = strcat(finalString, reads[str1Index]);
    finalString = (max > -1) ? strcat(finalString, &reads[str2Index][max]) : strcat(finalString, reads[str2Index]);

    char** ret = (char**) malloc((numberOfReads - 1) * sizeof(char*));
    ret[0] = (char*) malloc((strlen(finalString) + 1) * sizeof(char));
    strcpy(ret[0], finalString);

    int idx = 1;
    for (int i = 0; i < numberOfReads; i++) {
        if (i != str1Index && i != str2Index) {
            ret[idx] = (char*) malloc((strlen(reads[i]) + 1) * sizeof(char));
            strcpy(ret[idx], reads[i]);
            idx++;
        }
    }

    return ret;
}

int main() {
    int numberOfReads;
    scanf("%d", &numberOfReads);
    getchar();

    char** reads = (char**) malloc(numberOfReads * sizeof(char*));;
    char input[MAX_INPUT_SIZE];
    for (int i = 0; i < numberOfReads; i++) {
        fgets(input, MAX_INPUT_SIZE, stdin);
        reads[i] = substring(input, strlen(input) - 1);
    }

    for (int i = numberOfReads; i > 1; i--) {
        reads = getCombinations(reads, i);
    }

    printf("%s\n", reads[0]);

    return 0;
}
