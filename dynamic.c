#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxFriends(int* cache, int* paths, int start, int rows, int columns) {
    if (cache[start] == -1) {
        int res;

        if (start == rows * columns - 1) {
            res = 0;
        } else if ((start + 1) % columns == 0 && paths[2 * start + 1] != -1) {
            res = paths[2 * start + 1] + maxFriends(cache, paths, start + columns, rows, columns);
        } else if (start >= columns * (rows - 1) && (paths[2 * start] != -1)) {
            res = paths[2 * start] + maxFriends(cache, paths, start + 1, rows, columns);
        } else {
            int a = 0, b = 0;

            if (paths[2 * start + 1] != -1) {
                a = paths[2 * start + 1] + maxFriends(cache, paths, start + columns, rows, columns);
            }

            if (paths[2 * start] != -1) {
                b = paths[2 * start] + maxFriends(cache, paths, start + 1, rows, columns);
            }

            res = max(a, b);
        }

        cache[start] = res;
    }

    return cache[start];
}

int getMaxFriendsCount(int* paths, int start, int rows, int columns) {
    size_t cacheSize = rows * columns * sizeof(int);
    int* cache = (int *) malloc(cacheSize);
    memset(cache, -1, cacheSize);

    int res = maxFriends(cache, paths, start, rows, columns);
    free(cache);

    return res;
}

int main() {
    int rows, columns;
    scanf("%d %d", &rows, &columns);

    int pathsCount = (rows * columns - 1) * 2;
    size_t pathsSize = pathsCount * sizeof(int);

    int* paths = (int *) malloc(pathsSize);
    memset(paths, -1, pathsSize);

    int inputsCount = columns * (rows - 1) + rows * (columns - 1);
    for (int i = 0; i < inputsCount; i++) {
        int start, end, friendsCount;
        scanf("%d %d %d", &start, &end, &friendsCount);

        if (end - start == 1) {
            paths[2 * start] = friendsCount;
        } else {
            paths[2 * start + 1] = friendsCount;
        }
    }

    int maxFriendsCount = getMaxFriendsCount(paths, 0, rows, columns);
    printf("%d\n", maxFriendsCount);

    free(paths);

    return 0;
}
