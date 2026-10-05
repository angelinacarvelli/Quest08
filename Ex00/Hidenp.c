#include <stdio.h>

int hidenp(char* param_1, char* param_2) {
    if (param_1 == NULL || param_2 == NULL) {
        return 0;
    }

    int indexparam1 = 0;
    int indexparam2 = 0;

    while (param_1[indexparam1] != '\0' && param_2[indexparam2] != '\0') {
        if (param_1[indexparam1] == param_2[indexparam2]) {
            indexparam1++;
        }
        indexparam2++;
    }

    return (param_1[indexparam1] == '\0') ? 1 : 0;
}

int main() {
    int res1 = hidenp("fgex.;", "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6");
    printf("(\"fgex.;\", \"...\") -> Resultat : %d\n", res1);

    int res2 = hidenp("abc", "btarc");
    printf("(\"abc\", \"btarc\") -> Resultat : %d\n", res2);

    int res3 = hidenp("", "long string ?ddl");
    printf("(\"\", \"long string ?ddl\") -> Resultat : %d\n", res3);

    int res4 = hidenp("abc", "abc");
    printf("(\"abc\", \"abc\") -> Resultat : %d\n", res4);

    int res5 = hidenp("abcd", "abc");
    printf("(\"abcd\", \"abc\") -> Resultat : %d\n", res5);

    return 0;
}