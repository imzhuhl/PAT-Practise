#include <iostream>
#include <cctype>
using namespace std;

int asc[256] = {0};
char s[90];
int len = 0;
int have[256] = {0};
int main() {
    char c = getchar();
    while (c != '\n') {
        if (isalpha(c)) {
            c = toupper(c);
        }
        s[len++] = c;
        c = getchar();
    }
    c = getchar();
    while (c != '\n') {
        if (isalpha(c)) {
            c = toupper(c);
        }
        asc[c] = 1;
        c = getchar();
    }

    for (int i = 0; i < len; i++) {
        c = s[i];
        if (asc[c] == 0 && have[c] == 0) {
            have[c] = 1;
            printf("%c", c);
        }
    }
    printf("\n");
    
    return 0;
}