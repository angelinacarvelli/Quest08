#include <stdio.h>
#include <stdlib.h>

typedef struct s_string_array {
    int size;
    char** array;
} string_array;

char* my_substr(char* src, int start, int end) {
    int len = end - start;
    char* dest = (char*)malloc(len + 1);
    if (!dest) return NULL;
    
    int i = 0;
    while (i < len) {
        dest[i] = src[start + i];
        i++;
    }
    dest[len] = '\0';
    return dest;
}

string_array* my_split(char* param_1, char* param_2) {
    string_array* res = (string_array*)malloc(sizeof(string_array));
    if (!res) return NULL;

    if (!param_1 || param_1[0] == '\0') {
        res->size = 0;
        res->array = NULL;
        return res;
    }

    char sep = (param_2 && param_2[0] != '\0') ? param_2[0] : '\0';

    int count = 0;
    int i = 0;
    int in_token = 0;

    while (param_1[i] != '\0') {
        if (param_1[i] == sep) {
            in_token = 0;
        } else {
            if (!in_token) {
                count++;
                in_token = 1;
            }
        }
        i++;
    }

    res->size = count;
    if (count == 0) {
        res->array = NULL;
        return res;
    }

    res->array = (char**)malloc(sizeof(char*) * count);
    if (!res->array) return res;

    int token_index = 0;
    i = 0;
    in_token = 0;
    int start = 0;

    while (param_1[i] != '\0') {
        if (param_1[i] == sep) {
            if (in_token) {
                res->array[token_index] = my_substr(param_1, start, i);
                token_index++;
                in_token = 0;
            }
        } else {
            if (!in_token) {
                start = i;
                in_token = 1;
            }
        }
        i++;
    }
    
    if (in_token) {
        res->array[token_index] = my_substr(param_1, start, i);
    }

    return res;
}

void print_string_array(string_array* arr) {
    if (!arr || arr->size == 0 || !arr->array) {
        printf("[]\n");
        return;
    }
    printf("[");
    for (int i = 0; i < arr->size; i++) {
        printf("\"%s\"", arr->array[i]);
        if (i < arr->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    print_string_array(my_split("abc def gh-!", "-")); 

    print_string_array(my_split("abc def gh-!", " "));

    print_string_array(my_split("", "")); 

    print_string_array(my_split("---", "-")); 

    print_string_array(my_split("abc", "x")); 

    return 0;
}