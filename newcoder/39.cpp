#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    char s1[10005];
    int len = 0;
    char c = getchar();
    while (c != '\n') {
        s1[len++] = c;
        c = getchar();
    }

    set<char> s2;
    c = getchar();
    while (c != '\n') {
        s2.insert(c);
        c = getchar();
    }

    for (int i = 0; i < len; i++) {
        c = s1[i];
        if (s2.find(c) == s2.end()) {
            printf("%c", c);
        }
    }
    printf("\n");
    // for (set<char>::iterator it = s2.begin(); it != s2.end(); it++) {
    //     printf("%c", *it);
    // }
    // printf("\n");

    return 0;
}