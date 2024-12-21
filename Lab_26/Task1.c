#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** init(int size) {
    static char* sports[] = { "golf", "hockey", "football", "cricket" };
    int N = sizeof(sports) / sizeof(sports[0]);

    char** arr = (char**)malloc(size * sizeof(char*));

    for (int i = 0; i < size; i++) {
        arr[i] = (char*)malloc(strlen(sports[i % N]) + 1);

        strcpy(arr[i], sports[i % N]);
    }
    return arr;
}

void printArray(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("[%d]: %s\n", i, arr[i]);
    }
}


void replaceString(char** arr, int index, const char* newString) {
    free(arr[index]);
    arr[index] = (char*)malloc(strlen(newString) + 1);
 
    strcpy(arr[index], newString);
}

int main() {
    int size = 10;
    char** arr = init(size);

    printf("Изначальный массив строк:\n");
    printArray(arr, size);

    int index;
    char newString[100];
    printf("\nВведите индекс строки для замены (0-%d): ", size - 1);
    scanf("%d", &index);

    printf("Введите новую строку: ");
    scanf("%s", newString);

    replaceString(arr, index, newString);

    printf("\nПосле замены:\n");
    printArray(arr, size);

    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);

}