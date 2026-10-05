#include <stdio.h>
#include <stdlib.h>

int my_strlen(char* s) {
    if (!s) return 0;
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

char* my_strip(char* param_1) {
    if (!param_1) {
        char* empty = (char*)malloc(1);
        if (empty) empty[0] = '\0';
        return empty;
    }

    int len = my_strlen(param_1);
    char* dest = (char*)malloc(len + 1);
    if (!dest) return NULL;

    int i = 0;
    int j = 0;

    while (param_1[i] != '\0' && (param_1[i] == ' ' || param_1[i] == '\t')) {
        i++;
    }

    int pending_space = 0;

    while (param_1[i] != '\0') {
        if (param_1[i] == ' ' || param_1[i] == '\t') {
            pending_space = 1;
        } else {
            if (pending_space && j > 0) {
                dest[j++] = ' ';
                pending_space = 0;
            }
            dest[j++] = param_1[i];
        }
        i++;
    }

    dest[j] = '\0';
    return dest;
}

int main() {
    // Test 1
    char* r1 = my_strip("See? It's easy to print the same thing");
    printf("Test 1 -> \"%s\"\n", r1);
    free(r1);

    char* r2 = my_strip(" this time...");
    printf("Test 2 -> \"%s\"\n", r2);
    free(r2);

    char* r3 = my_strip("");
    printf("Test 3 -> \"%s\"\n", r3);
    free(r3);

    char* r4 = my_strip(" ");
    printf("Test 4 -> \"%s\"\n", r4);
    free(r4);

        char* r5 = my_strip("\t\tworld\t");
    printf("Test 5 -> \"%s\"\n", r5);
    free(r5);
    return 0;
}