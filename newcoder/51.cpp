#include <iostream>
using namespace std;

char all[1005];
int len = 0;

int main() {
    char c = getchar();
    while (c != '\n') {
        all[len++] = c;
        c = getchar();
    }

    int maxval = 0;
    for (int i = 0; i < len - 1; i++) {
        char a, b;
        int now = 0;
        a = all[i - now];
        b = all[i + 1 + now];
        while (a == b) {
            now++;
            if (i - now < 0 || i + 1 + now >= len) {
                break;
            }
            a = all[i - now];
            b = all[i + 1 + now];
        }
        if (now * 2 > maxval) {
            maxval = now * 2;
        }

        now = 0;
        if (i - 1 - now >= 0) {
            a = all[i - 1 - now];
            b = all[i + 1 + now];
            while (a == b) {
                now++;
                if (i - 1 - now < 0 || i + 1 + now >= len) {
                    break;
                }
                a = all[i - 1 - now];
                b = all[i + 1 + now];
            }
            if (now * 2 + 1 > maxval) {
                maxval = now * 2 + 1;
            }
        }
    }

    if (len == 1) {
        printf("1\n");
    } else {
        printf("%d\n", maxval);
    }

    return 0;
}