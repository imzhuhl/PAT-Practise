#include <iostream>
using namespace std;

int asc[256] = {0};
int len = 0;

int main() {
    char c = getchar();
    while (c != '\n') {
        asc[c]++;
        len++;
        c = getchar();
    }

    int match = 0;
    int total = 0;
    c = getchar();
    while (c != '\n') {
        total++;
        if (asc[c]) {
            asc[c]--;
            match++;
        }
        c = getchar();
    }

    if (total == match) {
        printf("Yes %d\n", len - total);
    } else {
        printf("No %d\n", total - match);
    }

    return 0;
}