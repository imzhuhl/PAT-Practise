#include <iostream>

using namespace std;

int main() {
    char s1[10005] = {'\0'};
    int len = 0;
    int asc[256] = {0};

    char c = getchar();
    while (c != '\n') {
        s1[len++] = c;
        c = getchar();
    }

    c = getchar();
    while (c != '\n') {
        asc[c]++;
        c = getchar();
    }

    for (int i = 0; i < len; i++) {
        char c = s1[i];
        if (asc[c] == 0) {
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;
}