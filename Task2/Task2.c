#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** init(int size) {
    static char* sports[] = { "golf", "hockey", "football", "cricket" };
    int N = sizeof(sports) / sizeof(sports[0]);

    char** arr = (char**)malloc(size * sizeof(char*));
    if (!arr) {
        perror("Ошибка выделения памяти");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        arr[i] = (char*)malloc(strlen(sports[i % N]) + 1);
        if (!arr[i]) {
            perror("Ошибка выделения памяти для строки");
            exit(1);
        }
        strcpy(arr[i], sports[i % N]);
    }
    return arr;
}

void printArray(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("[%d]: %s\n", i, arr[i]);
    }
}

int compareStrings(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;
    return strcmp(str1, str2);
}

int main() {
    int size = 10;
    char** arr = init(size);

    printf("Изначальный массив:\n");
    printArray(arr, size);

    char** sortedArr = (char**)malloc(size * sizeof(char*));

    for (int i = 0; i < size; i++) {
        sortedArr[i] = _strdup(arr[i]);
    }

    qsort(sortedArr, size, sizeof(char*), compareStrings);

    printf("\nОтсортированный массив:\n");
    printArray(sortedArr, size);


}