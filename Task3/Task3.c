#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int countWords(const char* str) {
    int count = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') count++;
    }
    return count;
}

int compare(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;
    return countWords(str1) - countWords(str2);
}

int main() {
    FILE* file = fopen("books.txt", "r");

    char* lines[100];
    int lineCount = 0;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        lines[lineCount++] = _strdup(buffer);
    }
    fclose(file);

    qsort(lines, lineCount, sizeof(char*), compare);

    printf("Отсортированный список строк:\n");
    for (int i = 0; i < lineCount; i++) {
        printf("%s\n", lines[i]);
        free(lines[i]);
    }
}